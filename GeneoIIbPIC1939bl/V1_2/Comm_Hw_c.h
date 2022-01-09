/* ========================================
 *
 * Hardware definitions for Comm.c
 *
 * ========================================
*/

#ifndef _COMM_HW_H_
#define _COMM_HW_H_

#include "General.h"
#include "Types.h"


////Registers
//    #ifdef SW_UC_PIC16F
//        #define COMM_HW_RX_OVF_RELEASE  if(OERR){CREN=0;CREN=1;} //Release overflow error
//        #define COMM_HW_TX_RESTART      {TXEN=0;TXEN=1;}    //Disable transmitter and enable
//        #define COMM_HW_RX_REG          RCREG               //Receive register
//        #define COMM_HW_TX_REG          TXREG               //Transmit register
//        #define COMM_HW_TX_INT_ENA      {TXIE=1;}           //Transmit interrupt enable
//        #define COMM_HW_TX_INT_DIS      {TXIE=0;}           //Transmit interrupt disable
//    #endif
//    #ifdef SW_UC_PIC18F
//        #define COMM_HW_RX_OVF_RELEASE  if(RCSTA1bits.OERR){RCSTA1bits.CREN=0;RCSTA1bits.CREN=1;} //Release overflow error
//        #define COMM_HW_TX_RESTART      {TXSTA1bits.TXEN=0;TXSTA1bits.TXEN=1;}    //Disable transmitter and enable
//        #define COMM_HW_RX_REG          RCREG1              //Receive register
//        #define COMM_HW_TX_REG          TXREG1              //Transmit register
//        #define COMM_HW_TX_INT_ENA      {PIE1bits.TX1IE=1;}          //Transmit interrupt enable
//        #define COMM_HW_TX_INT_DIS      {PIE1bits.TX1IE=0;}          //Transmit interrupt disable
//    #endif


////Hardware config
//    #ifdef SW_UC_PIC16F
//        void Comm_HwCnfg(void)
//        {
//            TRISC6 = 0;       //making output port
//            TRISC7 = 1;       //making input port
//         
//            BRG16 = 1;          // use 16 bit BRG
//            BRGH = 0; 
//            SPBRGH  = BRG_VALUE >> 8;
//            SPBRG   = BRG_VALUE & 0xFF;
//            BRGH   = 1;         //high data rate for sending
//            SYNC   = 0;         //asynchronous
//            SPEN   = 1;         //enable serial port pins
//            //SREN   = 0;         //no effect
//            TX9    = 0;           //8-bit transmission
//            RX9    = 0;           //8-bit reception
//            CREN    = 1;        //enable the reciever
//            RCIE    = 1;        //Enable receiver interrupt
//        }    
//    #endif
//    #ifdef SW_UC_PIC18F
//        void Comm_HwCnfg(void)
//        {
//            TRISCbits.TRISC6 = 1; //0;           //making output port
//            TRISCbits.TRISC7 = 1;           //making input port
//            ANSELCbits.ANSC7 = 0;
//            ANSELCbits.ANSC6 = 0;
//         
//            BAUD1CONbits.BRG16 = 1;         // use 16 bit BRG
//            TXSTA1bits.BRGH = 0; 
//            SPBRGH1  = BRG_VALUE >> 8;
//            SPBRG1   = BRG_VALUE & 0xFF;
//            TXSTA1bits.BRGH   = 1;          //high data rate for sending
//            TXSTA1bits.SYNC   = 0;          //asynchronous
//            RCSTA1bits.SPEN   = 1;          //enable serial port pins
//            //SREN   = 0;                   //no effect
//            TXSTA1bits.TX9    = 0;          //8-bit transmission
//            RCSTA1bits.RX9    = 0;           //8-bit reception
//            RCSTA1bits.CREN    = 1;         //enable the reciever
//            PIE1bits.RCIE    = 1;           //Enable receiver interrupt
//        }    
//    #endif



#endif
//[] END OF FILE
