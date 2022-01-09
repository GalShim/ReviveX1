/* ========================================
 *
 * Hardware definitions for Motor.c
 *
 * ========================================
*/

#ifndef _MOTOR_HW_H_
#define _MOTOR_HW_H_

//#ifdef SW_MOT_X                             //H
//    #define MOT_PORT_MOTX           PORTE
//    #define MOT_PORT_BIT_MOTX       0x04
//#endif
//#ifdef SW_MOT_Y                             //V
//    #define MOT_PORT_MOTY           PORTD
//    #define MOT_PORT_BIT_MOTY       0x02
//#endif
//#ifdef SW_MOT_RF
//    #define MOT_PORT_RF             PORTC
//    #define MOT_PORT_BIT_RF         0x01
//#endif
//
//#ifdef SW_MOT_X
//    void Motor_ActMotorX (void)
//    {
//        MOT_PORT_MOTX |= MOT_PORT_BIT_MOTX;
//    }    
//    void Motor_DisMotorX (void)
//    {
//        MOT_PORT_MOTX &= ~MOT_PORT_BIT_MOTX;
//    }
//#endif
//#ifdef SW_MOT_Y
//    void Motor_ActMotorY (void)
//    {
//        MOT_PORT_MOTY |= MOT_PORT_BIT_MOTY;
//    }    
//    void Motor_DisMotorY (void)
//    {
//        MOT_PORT_MOTY &= ~MOT_PORT_BIT_MOTY;
//    }
//#endif
//#ifdef SW_MOT_RF
//    void Motor_ActRf (void)
//    {
//        MOT_PORT_RF |= MOT_PORT_BIT_RF;
//    }    
//    void Motor_DisRf (void)
//    {
//        MOT_PORT_RF &= ~MOT_PORT_BIT_RF;
//    }
//#endif
//
//void Motor_HwInit(void)
//{
//    #ifdef SW_MOT_X
//        Motor_DisMotorX();
//        TRISE2 = 0;                             //Set port
//        ANSELE &= ~MOT_PORT_BIT_MOTX;           //Disable analog function
//    #endif
//    #ifdef SW_MOT_Y
//        Motor_DisMotorY();
//        TRISD1 = 0;                             //Set output ports
//    #endif
//    #ifdef SW_MOT_RF
//        Motor_DisRf();
//        TRISCbits.TRISC0 = 0;                             //Set output ports
//    #endif
//}    

#endif
//[] END OF FILE
