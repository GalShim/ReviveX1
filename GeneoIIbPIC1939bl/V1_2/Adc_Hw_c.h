/* ========================================
 *
 * Hardware definitions for Adc.c
 *
 * ========================================
*/

#ifndef _ADC_HW_H_
#define _ADC_HW_H_


//--------------------------------------------------------------
//Convert code to ADC channel #
//--------------------------------------------------------------
//#ifdef SW_UC_PIC16F
//    const uint8 Adc_ConvertCodeToChannel[ADC_IN_num] = {
//         0, //ADC_IN_MOT_X_I
//         1, //ADC_IN_MOT_Y_I
//         2, //ADC_IN_RGB_LED_I
//         3, //ADC_IN_MOT_X_V
//         4, //ADC_IN_MOT_Y_V
//         5, //ADC_IN_RGB_LED_V
//         6, //ADC_IN_12V_V
//        15, //ADC_IN_5V_V
//         8, //ADC_IN_0V_V
//        10  //ADC_IN_DAC_SAMP_V
//    };
//#endif
//#ifdef SW_UC_PIC18F
//    rom const uint8 Adc_ConvertCodeToChannel[ADC_IN_num] = {
//        13, //ADC_IN_12V_V
//        31, //ADC_IN_5V_V           //Internal
//        11, //ADC_IN_SupCur_I
//        0   //ADC_IN_Temp_C         //Dummy. Not analog in
//    };
//#endif
//
////--------------------------------------------------------------
//// Registers
////--------------------------------------------------------------
//#ifdef SW_UC_PIC16F
//    #define ADC_REG_CONVERT_nDONE   ADCON0bits.GO_nDONE
//    #define ADC_REG_ON              ADCON0bits.ADON
//#endif
//#ifdef SW_UC_PIC18F
//    #define ADC_REG_CONVERT_nDONE   ADCON0bits.GO_NOT_DONE
//    #define ADC_REG_ON              ADCON0bits.ADON
//#endif
//--------------------------------------------------------------
//--------------------------------------------------------------


////--------------------------------------------------------------
//// Utilities
////--------------------------------------------------------------
//#ifdef SW_UC_PIC16F
//    void Adc_StartConvert (void)
//    {
//        ADCON0 &= ~0b1111100;
//        ADCON0 |= (Adc_ConvertCodeToChannel[Adc_Obj.Task.Channel] << 2);  //Select channel
//        ADCON0bits.GO_nDONE = 1;                    //Start conversion
//    }
//    void Adc_StartConvert5v (void)
//    {
//        ADCON1 = 0b11100000;                        //Vdd ref voltage
//    }    
//    void Adc_EndConvert (void)
//    {
//      uint16 TempW;
//        TempW = ADRESH & 0x03;                      //Save reading
//        TempW = TempW << 8;
//        TempW += ADRESL;
//        Adc_Obj.Input[Adc_Obj.Task.Channel] = TempW;
//    }
//    void Adc_HwInit (void)
//    {
//        FVRCON = 0b10000011;                        //4.096V ref
//        ANSELA |= 0b00101111;
//        ANSELB |= 0b00000111;
//        ANSELE |= 0x00000011;
//    
//        ADCON0 = 0b00000000;
//        ADCON1 = 0b11101000;                        //FVR BUF2 ref voltage
//    }
//    void Adc_Hw_SetLoadCap(void)                    //Set to load capacitor
//    {
//    }
//    void Adc_Hw_SetDischargeMeasure(void)           //Set to discharge measurement
//    {
//    }
//    void Adc_Hw_SetDischargeRef(void)               //Set to discharge capacitor via ref resistor
//    {
//    }
//    void Adc_Hw_SetDischargeTherm(void)             //Set to discharge capacitor via thermistor
//    {
//    }
//    void Adc_Hw_StopThermMeasure(void)              //Stop thermistor measurement
//    {
//    }
//    uint16 Adc_Hw_GetTime(void)                     //Get timer value
//    {
//        return(0);
//    }                
//#endif
//#ifdef SW_UC_PIC18F
//    void Adc_StartConvert (void)
//    {
//        ADCON0 &= ~0b1111100;
//        ADCON0 |= (Adc_ConvertCodeToChannel[Adc_Obj.Task.Channel] << 2);  //Select channel
//        ADCON0bits.GO_NOT_DONE = 1;                 //Start conversion
//    }
//    void Adc_StartConvert5v (void)
//    {
//        ADCON1 = 0b11100000;                        //Vdd ref voltage
//    }    
//    void Adc_EndConvert (void)
//    {
//      uint16 TempW;
//        TempW = ADRESH & 0x03;                      //Save reading
//        TempW = TempW << 8;
//        TempW += ADRESL;
//        Adc_Obj.Input[Adc_Obj.Task.Channel] = TempW;
//    }
//    void Adc_HwInit (void)
//    {
//        VREFCON0 = 0b10110000;                      //4.096V ref
//        ANSELA |= 0b00100000;
//        ANSELB |= 0b00110000;
//        //ANSELE |= 0x00000011;
//    
//        ADCON0 = 0b00000000;
//        ADCON1 = 0b11101000;                        //FVR BUF2 ref voltage
//        ADCON2 = 0b10101101;
//    }    
//    void Adc_Hw_SetLoadCap(void)                    //Set to load capacitor
//    {
//        TRISAbits.TRISA1 = 1;                       //RA1 input
//        TRISAbits.TRISA0 = 0;                       //RA0 output
//        TRISAbits.TRISA2 = 0;                       //RA2 output
//        PORTA |= 0b00000101;                        //Load via RA0 and RA2
//    }
//    void Adc_Hw_SetDischargeMeasure(void)           //Set to discharge measurement
//    {
//        CM1CON0 = 0b10011101;                       //Set comparator
//        CM2CON1 = 0b00101000;
//        T5CON = 0b01110101;                         //Set timer mode
//        T5GCON = 0b11000010;
//        TMR5H = 0;                                  //Clear timer
//        TMR5L = 0;
//    }
//    void Adc_Hw_SetDischargeRef(void)               //Set to discharge capacitor via ref resistor
//    {
//        TRISAbits.TRISA2 = 1;                       //Leave thermistor floating
//        PORTA &= ~0b00000001;                       //Start discharge via ref resistor
//        T5CONbits.TMR5ON = 1;                       //Enable counter
//    }
//    void Adc_Hw_SetDischargeTherm(void)             //Set to discharge capacitor via thermistor
//    {
//        TRISAbits.TRISA0 = 1;                       //Leave ref resistor floating
//        PORTA &= ~0b00000100;                       //Start discharge via thermistor
//        T5CONbits.TMR5ON = 1;                       //Enable counter
//    }
//    void Adc_Hw_StopThermMeasure(void)              //Stop thermistor measurement
//    {
//        CM1CON0 = 0b10010101;
//        CM2CON1 = 0b00101000;
//        T5CON = 0b01110100;
//        T5GCON = 0b11000010;
//    }    
//    uint16 Adc_Hw_GetTime(void)                     //Get timer value
//    {
//      uint16 TimerVal = TMR5H;
//        TimerVal = TimerVal << 8;
//        TimerVal += TMR5L;
//    }
//#endif
//--------------------------------------------------------------
//--------------------------------------------------------------

///******************************************************************************
//*  Function name: Adc_SampleRequest
//*  Main tasks:
//*    Sample one input
//*  Parameters:
//*    Channel code
//*  Returned values:
//*    None
//*  Remarks:
//*    Also restarts periodic ADC sampling
//******************************************************************************/
//#ifdef SW_UC_PIC16F
//    uint16 Adc_SampleRequest (ADC_IN_e Channel)
//    {
//        ADCON0bits.ADON = 0;                            //Stop ADC (if was active)
//        Adc_Obj.Task.Channel = Channel;
//        ADCON0bits.ADON = 1;                            //Start ADC
//        Adc_StartConvert();                             //Start conversion
//        while (ADCON0bits.GO_nDONE);                    //Wait till conversion end
//        Adc_EndConvert();    
//        ADCON0bits.ADON = 0;                            //Stop ADC
//        Adc_Obj.Task.State == ADC_TASK_STATE_INIT;      //Restart periodic ADC sampling
//        return (Adc_Obj.Input[Adc_Obj.Task.Channel]);
//    }
//#endif
//#ifdef SW_UC_PIC18F
//    uint16 Adc_SampleRequest (ADC_IN_e Channel)
//    {
//        ADCON0bits.ADON = 0;                            //Stop ADC (if was active)
//        Adc_Obj.Task.Channel = Channel;
//        ADCON0bits.ADON = 1;                            //Start ADC
//        Adc_StartConvert();                             //Start conversion
//        while (ADCON0bits.GO_nDONE);                    //Wait till conversion end
//        Adc_EndConvert();    
//        ADCON0bits.ADON = 0;                            //Stop ADC
//        Adc_Obj.Task.State == ADC_TASK_STATE_INIT;      //Restart periodic ADC sampling
//        return (Adc_Obj.Input[Adc_Obj.Task.Channel]);
//    }
//#endif
   



#endif
//[] END OF FILE
