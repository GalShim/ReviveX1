/* ========================================
 *
 * Geneo II
 *
 * ========================================
*/
#include <htc.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "Types.h"
#include "Comm_Pub.h"
#include "Motor_Pub.h"
#include "Led_Pub.h"
#include "Keys_Pub.h"
#include "Adc_Pub.h"
#include "App_Pub.h"




__CONFIG(FOSC_INTOSC&WDTE_OFF&PWRTE_ON&MCLRE_ON&CP_OFF&CPD_OFF&BOREN_ON&CLKOUTEN_OFF&IESO_OFF&FCMEN_OFF);
//__CONFIG(FOSC_INTOSC&WDTE_OFF&PWRTE_ON&MCLRE_ON&CP_OFF&CPD_OFF&BOREN_ON&CLKOUTEN_OFF&IESO_OFF&FCMEN_ON);

//__CONFIG(WRT_ALL&PLLEN_OFF&STVREN_OFF&BORV_LO&LVP_OFF);
//__CONFIG(WRT_ALL&PLLEN_OFF&STVREN_ON&BORV_LO&LVP_OFF);
__CONFIG(WRT_OFF&PLLEN_OFF&STVREN_ON&BORV_LO&LVP_ON);

void main_TickFunctions(void);

//======================================================================
//Bootloader:
// - Include isr.as in the project
// - ROM range: default,-3E38-3FFF
// - RAM range: default,-7E-7F  ???
// - codeoffset 404 ???
// - Define W_TEMP and PCLATH_TEMP ???
//unsigned char W_TEMP @ 0x7F;
//unsigned char PCLATH_TEMP @ 0x7E;
//======================================================================

//#define  TMR1H_BYTE 0xFC
//#define  TMR1L_BYTE 0x18
#define TMR6_BYTE 80
#define  TICK_100MS_COUNT   100
uint8 Tick100mSCounter = TICK_100MS_COUNT;
volatile struct {
    union{
        uint8       Byte;
        struct {
            uint8       Tick:1;                 //1mS system tick
            uint8       b1:1;
            uint8       b2:1;
            uint8       b3:1;
            uint8       b4:1;
            uint8       b5:1;
            uint8       b6:1;
            uint8       b7:1;
        }   Flags;
    } Status;
} main_obj;    
#define SYSTEM_TICK if(main_obj.Status.Flags.Tick){main_TickFunctions();main_obj.Status.Flags.Tick=0;}  //To minimize stack

/******************************************************************************
*  Main routine
******************************************************************************/
void main (void)
{
    //Config

    
    SWDTEN = 0;         //Disable watch dog
   
    PEIE=0;             //Disable interrupts
    GIE=0;
    
    LCDCONbits.LCDEN = 0; //Disable LCD
    
    OSCCON = 0x7a;      //16MHz
    OSCTUNE = 0x00;
    while (OSCSTATbits.HFIOFR == 0) {}      //Wait till oscillator ready
    
    TRISA = 0xFF;       //Init all ports as inputs
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISD = 0xFF;
    TRISE = 0xFF;
    
//    T1CON = 0b00100001; //Timer1 setup
//    T1GCON = 0;
//    TMR1H = TMR1H_BYTE; //Count 1000
//    TMR1L = TMR1L_BYTE;
//    TMR1IE = 1;         //Enable timer1 interrupt
    
TMR6 = TMR6_BYTE;               //Count to 1mS tick
T6CON = 0b00000010;             //Config timer6
T6CONbits.TMR6ON = 1;           //Enable timer6
TMR6IE = 1;                     //Enable interrupt

    
    PEIE=1;             //Enable interrupts
    GIE=1;
    //SWDTEN = 1;         //Enable watch dog
    
    main_obj.Status.Byte = 0;
    
    //Init
    Motor_TaskInit();
    Led_TaskInit();
    Keys_TaskInit();
    Adc_TaskInit();
    Comm_TaskInit();
    App_TaskInit();
    
    //Main
    while(1)
    {
        Comm_TaskMain();
        SYSTEM_TICK;
        Motor_TaskMain();
        SYSTEM_TICK;
        Led_TaskMain();
        SYSTEM_TICK;
        Keys_TaskMain();
        SYSTEM_TICK;
        Adc_TaskMain();
        SYSTEM_TICK;
        App_TaskMain();
        SYSTEM_TICK;
        CLRWDT();               //Clear watch dog timer
    }    
}    


/******************************************************************************
*  Interrupt routine
******************************************************************************/
void main_TickFunctions(void)
{
    Adc_TaskTick1mS();
    Comm_TaskTick1mS();
    Keys_1mS_tick();
    Motor_TaskTick1mS();
    App_TaskTick1mS();
    Tick100mSCounter--;
    if (Tick100mSCounter == 0)
    {                           //100mS
        Tick100mSCounter = TICK_100MS_COUNT;
        Led_TaskTick100mS();
        #ifdef SW_MOT_BLDC
            MotorBLDC_TaskTick100mS();
        #endif
    }
}
    
static void interrupt interrupt_handler(void)
{
    //if(TMR1IF)
    if(TMR6IF)
    {                               //1mS system tick
        //TMR1H = TMR1H_BYTE;         //Count 1000
        //TMR1L = TMR1L_BYTE;
        TMR6 = TMR6_BYTE;
        main_obj.Status.Flags.Tick = 1;
        //TMR1IF = 0;
        TMR6IF = 0;
    }
    if (RCIE & RCIF)
    {                               //UART RX interrupt
        Comm_RxInterrupt();
        RCIF = 0;
    }    
    if (TXIE & TXIF)
    {                               //UART TX interrupt
        Comm_TxInterrupt();
        TXIF = 0;
    }    
}         
