/* ========================================
 *
 * Hardware definitions for Led.c
 *
 * ========================================
*/

#ifndef _LED_HW_H_
#define _LED_HW_H_

#include "General.h"


////Registers
//    #ifdef SW_UC_PIC16F
//        #define LED_PORT_GREEN          PORTA
//        #define LED_PORT_BIT_GREEN      0x40
//        #define LED_PORT_RGB_R          PORTC
//        #define LED_PORT_BIT_RGB_R      0x04
//        #define LED_PORT_RGB_G          PORTB
//        #define LED_PORT_BIT_RGB_G      0x08
//        #define LED_PORT_RGB_B          PORTB
//        #define LED_PORT_BIT_RGB_B      0x20
//    #endif
//    #ifdef SW_UC_PIC18F
//        #define LED_PORT_GREEN          PORTA
//        #define LED_PORT_BIT_GREEN      0x80
//        #define LED_PORT_BIT_BLUE       0x40
//        #define LED_PORT_RGB_R          PORTC
//        #define LED_PORT_BIT_RGB_R      0x04        //Used as Orange
//        #define LED_PORT_RGB_G          PORTA
//        #define LED_PORT_BIT_RGB_G      0x00
//        #define LED_PORT_RGB_B          PORTA
//        #define LED_PORT_BIT_RGB_B      0x00
//        #define LED_ORANGE_BLINK_ON     5
//        #define LED_ORANGE_BLINK_OFF    5
//    #endif







////Set RGB intensity
//    #ifdef SW_UC_PIC16F
//        //-----------------------------------
//        void Led_SetIntensityR(unsigned char IntensityR)
//        {
//            CCPR1L = (Led_RgbIntensity[IntensityR] >> 2);
//            DC1B0  = Led_RgbIntensity[IntensityR] & 0x01;
//            DC1B1  = (Led_RgbIntensity[IntensityR] >> 1) & 0x01;
//        }
//        //-----------------------------------
//        void Led_SetIntensityG(unsigned char IntensityG)
//        {
//            CCPR2L = (Led_RgbIntensity[IntensityG] >> 2);
//            DC2B0  = Led_RgbIntensity[IntensityG] & 0x01;
//            DC2B1  = (Led_RgbIntensity[IntensityG] >> 1) & 0x01;
//        }
//        //-----------------------------------
//        void Led_SetIntensityB(unsigned char IntensityB)
//        {
//            CCPR3L = (Led_RgbIntensity[IntensityB] >> 2);
//            DC3B0  = Led_RgbIntensity[IntensityB] & 0x01;
//            DC3B1  = (Led_RgbIntensity[IntensityB] >> 1) & 0x01;
//        }
//        //-----------------------------------
//    #endif
//    #ifdef SW_UC_PIC18F
//        //-----------------------------------
//        void Led_SetIntensityR(unsigned char IntensityR)
//        {
//            //Intensity not in use
//        }
//        //-----------------------------------
//        void Led_SetIntensityG(unsigned char IntensityG)
//        {
//            //Intensity not in use
//        }
//        //-----------------------------------
//        void Led_SetIntensityB(unsigned char IntensityB)
//        {
//            //Intensity not in use
//        }
//        //-----------------------------------
//    #endif
//
////Check RGB LEDs
//    /******************************************************************************
//    *  Function name: Led_CheckRgbSet
//    *  Main tasks:
//    *    Set to check RGB LEDs
//    *  Parameters:
//    *    Single LED ID
//    *  Returned values:
//    *    None
//    *  Remarks:
//    *    None
//    ******************************************************************************/
//    #ifdef SW_UC_PIC16F
//        void Led_CheckRgbSet (LED_RGB_ID_e LedId)
//        {
//            switch (LedId)
//            {
//              case LED_RGB_ID_R:
//                //PORTB &= ~0x28;
//                //PORTB |=  0x00;
//                //PORTC &= ~0x04;
//                //PORTC |=  0x04;
//                LED_PORT_RGB_R |= LED_PORT_BIT_RGB_R;
//                LED_PORT_RGB_G &= ~LED_PORT_BIT_RGB_G;
//                LED_PORT_RGB_B &= ~LED_PORT_BIT_RGB_B;
//                break;
//              case LED_RGB_ID_G:
//                //PORTB &= ~0x28;
//                //PORTB |=  0x08;
//                //PORTC &= ~0x04;
//                //PORTC |=  0x00;
//                LED_PORT_RGB_R &= ~LED_PORT_BIT_RGB_R;
//                LED_PORT_RGB_G |= LED_PORT_BIT_RGB_G;
//                LED_PORT_RGB_B &= ~LED_PORT_BIT_RGB_B;
//                break;
//              case LED_RGB_ID_B:
//                //PORTB &= ~0x28;
//                //PORTB |=  0x20;
//                //PORTC &= ~0x04;
//                //PORTC |=  0x00;
//                LED_PORT_RGB_R &= ~LED_PORT_BIT_RGB_R;
//                LED_PORT_RGB_G &= ~LED_PORT_BIT_RGB_G;
//                LED_PORT_RGB_B |= LED_PORT_BIT_RGB_B;
//                break;
//            }    
//        }    
//    #endif
//    #ifdef SW_UC_PIC18F
//        void Led_CheckRgbSet (LED_RGB_ID_e LedId)
//        {
//            switch (LedId)
//            {
//              case LED_RGB_ID_R:
//                LED_PORT_RGB_R |= LED_PORT_BIT_RGB_R;
//                LED_PORT_RGB_G &= ~LED_PORT_BIT_RGB_G;
//                LED_PORT_RGB_B &= ~LED_PORT_BIT_RGB_B;
//                break;
//              case LED_RGB_ID_G:
//                LED_PORT_RGB_R &= ~LED_PORT_BIT_RGB_R;
//                LED_PORT_RGB_G |= LED_PORT_BIT_RGB_G;
//                LED_PORT_RGB_B &= ~LED_PORT_BIT_RGB_B;
//                break;
//              case LED_RGB_ID_B:
//                LED_PORT_RGB_R &= ~LED_PORT_BIT_RGB_R;
//                LED_PORT_RGB_G &= ~LED_PORT_BIT_RGB_G;
//                LED_PORT_RGB_B |= LED_PORT_BIT_RGB_B;
//                break;
//            }    
//        }    
//    #endif
//
////Config/unconfig
//    #ifdef SW_UC_PIC16F
//        //----------------------------------------
//        void Led_ConfigRgbled (void)
//        {
//            TRISC2 = 0; //CCP1              //Output pins
//            TRISB3 = 0; //CCP2
//            TRISB5 = 0; //CCP3
//            PR2 = 255;                      //PWM period 0x65 - 51us
//            CCP1CON = 0b00001100;           //Set to PWM mode
//            CCP2CON = 0b00001100;
//            CCP3CON = 0b00001100;
//            Led_SetIntensityR(0); //R               //Set initial values to 0
//            Led_SetIntensityG(0); //G
//            Led_SetIntensityB(0); //B
//            CCPTMRS0bits.C1TSEL = 0;        //Base for PWM is timer2 (for R,G and B)
//            CCPTMRS0bits.C2TSEL = 0;
//            CCPTMRS0bits.C3TSEL = 0;
//            T2CON = 123; //0b01111011;      //Config timer2
//            APFCONbits.CCP2SEL = 1;         //PWM
//            APFCONbits.CCP3SEL = 1;
//            ANSELBbits.ANSB5 = 0;           //Disable ADC functions
//            ANSELBbits.ANSB3 = 0;
//            T2CONbits.TMR2ON = 1;           //Enable timer2
//        }    
//        //----------------------------------------
//        void Led_UnConfigRgbled (void)
//        {
//            CCP1CON = 0;
//            CCP2CON = 0;
//            CCP3CON = 0;
//            APFCONbits.CCP2SEL = 0;
//            APFCONbits.CCP3SEL = 0;
//            T2CONbits.TMR2ON = 0;
//        }    
//        //----------------------------------------
//        void Led_InitPorts (void)
//        {
//            TRISA &= ~LED_PORT_BIT_GREEN;               
//            ANSELA &= ~LED_PORT_BIT_GREEN;
//        }    
//        //----------------------------------------
//    #endif
//    #ifdef SW_UC_PIC18F
//        //----------------------------------------
//        void Led_ConfigRgbled (void)
//        {
//            TRISAbits.TRISA4 = 0;
//            TRISAbits.TRISA7 = 0;
//            TRISCbits.TRISC3 = 0;
//        }    
//        //----------------------------------------
//        void Led_UnConfigRgbled (void)
//        {
//            //???<<<<
//        }    
//        //----------------------------------------
//        void Led_InitPorts (void)
//        {
//            Led_ConfigRgbled();
//        }    
//        //----------------------------------------
//        #ifdef SW_LED_RGB_FIXED
//            void Led_ActRgbled (LED_RGB_ID_e LedId, uint8 Action)
//            {
//                switch (LedId)
//                {
//                  case LED_RGB_ID_R:
//                    if (Action)
//                    {
//                        LED_PORT_RGB_R |= LED_PORT_BIT_RGB_R;
//                    }
//                    else
//                    {
//                        LED_PORT_RGB_R &= ~LED_PORT_BIT_RGB_R;
//                    }        
//                    break;
//                  case LED_RGB_ID_G:
//                    if (Action)
//                    {
//                        LED_PORT_RGB_G |= LED_PORT_BIT_RGB_G;
//                    }
//                    else
//                    {
//                        LED_PORT_RGB_G &= ~LED_PORT_BIT_RGB_G;
//                    }        
//                    break;
//                  case LED_RGB_ID_B:
//                    if (Action)
//                    {
//                        LED_PORT_RGB_B |= LED_PORT_BIT_RGB_B;
//                    }
//                    else
//                    {
//                        LED_PORT_RGB_B &= ~LED_PORT_BIT_RGB_B;
//                    }        
//                    break;
//                }    
//            }    
//        #endif
//    #endif
//
///******************************************************************************
//*  Function name: Led_SetGreen
//*  Main tasks:
//*    Set green LED on/off
//*  Parameters:
//*    TRUE/FALSE
//*  Returned values:
//*    None
//*  Remarks:
//*    None
//******************************************************************************/
//void Led_SetGreen(uint8 State)
//{
//  uint8 TempBit;
//                                                        //Select color
//    #ifdef SW_LED_RGB_FIXED
//     if (Led_IntObj.Task.Flags.Bits.ColorBlue)
//     {
//         TempBit = LED_PORT_BIT_BLUE;
//     }
//     else
//    #endif
//    {
//        TempBit = LED_PORT_BIT_GREEN;
//    }
//                                                        //Select action
//    if (State)
//    {
//        LED_PORT_GREEN = LED_PORT_GREEN & ~TempBit;
//    }
//    else
//    {
//        LED_PORT_GREEN = LED_PORT_GREEN | TempBit;
//    }        
//}    
//
//

#endif
//[] END OF FILE
