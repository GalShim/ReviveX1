/* ===================================================================================================================
File Name:   Keys_Hw.h
Description: Hardware definitions for Keys handler
====================================================================================================================*/
#ifndef __KEYS_HW_H__
#define __KEYS_HW_H__

//    #ifdef SW_UC_PIC16F
//        #define KEYS_NUM 4
//        #define KEY_MASK_UP             0x02                //Keys bits
//        #define KEY_MASK_DOWN           0x01
//        #define KEY_MASK_START          0x08
//        #define KEY_MASK_LIGHT          0x04
//        #define KEY_READ_PORT           ((PORTD>>3)&0x0f)   //Read keys from port
//        #define KEY_INIT_PORT           {TRISD|=0x78;ANSELD=0;} //Init ports
//    #endif
//    #ifdef SW_UC_PIC18F
//        #define KEYS_NUM 4
//        #define KEY_MASK_UP             0x02                //Keys bits (only Start exists. the rest are dummy)
//        #define KEY_MASK_DOWN           0x08
//        #define KEY_MASK_START          0x01
//        #define KEY_MASK_LIGHT          0x04
//        #define KEY_READ_PORT           ((PORTB&0x01)|0x0e) //Read keys from port (only one key. The rest - set to not active)
//        #define KEY_INIT_PORT           {TRISBbits.TRISB0=1;ANSELBbits.ANSB0=0;} //Init ports
//    #endif



#endif //__KEYS_HW_H__
