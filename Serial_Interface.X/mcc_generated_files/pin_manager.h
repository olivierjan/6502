/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F46K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set DATABUS_D0 aliases
#define DATABUS_D0_TRIS                 TRISAbits.TRISA0
#define DATABUS_D0_LAT                  LATAbits.LATA0
#define DATABUS_D0_PORT                 PORTAbits.RA0
#define DATABUS_D0_WPU                  WPUAbits.WPUA0
#define DATABUS_D0_OD                   ODCONAbits.ODCA0
#define DATABUS_D0_ANS                  ANSELAbits.ANSELA0
#define DATABUS_D0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DATABUS_D0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DATABUS_D0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DATABUS_D0_GetValue()           PORTAbits.RA0
#define DATABUS_D0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DATABUS_D0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DATABUS_D0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DATABUS_D0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DATABUS_D0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DATABUS_D0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DATABUS_D0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define DATABUS_D0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set DATABUS_D1 aliases
#define DATABUS_D1_TRIS                 TRISAbits.TRISA1
#define DATABUS_D1_LAT                  LATAbits.LATA1
#define DATABUS_D1_PORT                 PORTAbits.RA1
#define DATABUS_D1_WPU                  WPUAbits.WPUA1
#define DATABUS_D1_OD                   ODCONAbits.ODCA1
#define DATABUS_D1_ANS                  ANSELAbits.ANSELA1
#define DATABUS_D1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DATABUS_D1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DATABUS_D1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DATABUS_D1_GetValue()           PORTAbits.RA1
#define DATABUS_D1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DATABUS_D1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DATABUS_D1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define DATABUS_D1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define DATABUS_D1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define DATABUS_D1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define DATABUS_D1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define DATABUS_D1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set DATABUS_D2 aliases
#define DATABUS_D2_TRIS                 TRISAbits.TRISA2
#define DATABUS_D2_LAT                  LATAbits.LATA2
#define DATABUS_D2_PORT                 PORTAbits.RA2
#define DATABUS_D2_WPU                  WPUAbits.WPUA2
#define DATABUS_D2_OD                   ODCONAbits.ODCA2
#define DATABUS_D2_ANS                  ANSELAbits.ANSELA2
#define DATABUS_D2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DATABUS_D2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DATABUS_D2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DATABUS_D2_GetValue()           PORTAbits.RA2
#define DATABUS_D2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DATABUS_D2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DATABUS_D2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DATABUS_D2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DATABUS_D2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DATABUS_D2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DATABUS_D2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define DATABUS_D2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set DATABUS_D3 aliases
#define DATABUS_D3_TRIS                 TRISAbits.TRISA3
#define DATABUS_D3_LAT                  LATAbits.LATA3
#define DATABUS_D3_PORT                 PORTAbits.RA3
#define DATABUS_D3_WPU                  WPUAbits.WPUA3
#define DATABUS_D3_OD                   ODCONAbits.ODCA3
#define DATABUS_D3_ANS                  ANSELAbits.ANSELA3
#define DATABUS_D3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define DATABUS_D3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define DATABUS_D3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define DATABUS_D3_GetValue()           PORTAbits.RA3
#define DATABUS_D3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define DATABUS_D3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define DATABUS_D3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define DATABUS_D3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define DATABUS_D3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define DATABUS_D3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define DATABUS_D3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define DATABUS_D3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set DATABUS_D4 aliases
#define DATABUS_D4_TRIS                 TRISAbits.TRISA4
#define DATABUS_D4_LAT                  LATAbits.LATA4
#define DATABUS_D4_PORT                 PORTAbits.RA4
#define DATABUS_D4_WPU                  WPUAbits.WPUA4
#define DATABUS_D4_OD                   ODCONAbits.ODCA4
#define DATABUS_D4_ANS                  ANSELAbits.ANSELA4
#define DATABUS_D4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DATABUS_D4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DATABUS_D4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DATABUS_D4_GetValue()           PORTAbits.RA4
#define DATABUS_D4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DATABUS_D4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define DATABUS_D4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define DATABUS_D4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define DATABUS_D4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define DATABUS_D4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define DATABUS_D4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define DATABUS_D4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set DATABUS_D5 aliases
#define DATABUS_D5_TRIS                 TRISAbits.TRISA5
#define DATABUS_D5_LAT                  LATAbits.LATA5
#define DATABUS_D5_PORT                 PORTAbits.RA5
#define DATABUS_D5_WPU                  WPUAbits.WPUA5
#define DATABUS_D5_OD                   ODCONAbits.ODCA5
#define DATABUS_D5_ANS                  ANSELAbits.ANSELA5
#define DATABUS_D5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DATABUS_D5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DATABUS_D5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DATABUS_D5_GetValue()           PORTAbits.RA5
#define DATABUS_D5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DATABUS_D5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DATABUS_D5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define DATABUS_D5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define DATABUS_D5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define DATABUS_D5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define DATABUS_D5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define DATABUS_D5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set DATABUS_D6 aliases
#define DATABUS_D6_TRIS                 TRISAbits.TRISA6
#define DATABUS_D6_LAT                  LATAbits.LATA6
#define DATABUS_D6_PORT                 PORTAbits.RA6
#define DATABUS_D6_WPU                  WPUAbits.WPUA6
#define DATABUS_D6_OD                   ODCONAbits.ODCA6
#define DATABUS_D6_ANS                  ANSELAbits.ANSELA6
#define DATABUS_D6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define DATABUS_D6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define DATABUS_D6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define DATABUS_D6_GetValue()           PORTAbits.RA6
#define DATABUS_D6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define DATABUS_D6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define DATABUS_D6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define DATABUS_D6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define DATABUS_D6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define DATABUS_D6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define DATABUS_D6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define DATABUS_D6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set DATABUS_D7 aliases
#define DATABUS_D7_TRIS                 TRISAbits.TRISA7
#define DATABUS_D7_LAT                  LATAbits.LATA7
#define DATABUS_D7_PORT                 PORTAbits.RA7
#define DATABUS_D7_WPU                  WPUAbits.WPUA7
#define DATABUS_D7_OD                   ODCONAbits.ODCA7
#define DATABUS_D7_ANS                  ANSELAbits.ANSELA7
#define DATABUS_D7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define DATABUS_D7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define DATABUS_D7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define DATABUS_D7_GetValue()           PORTAbits.RA7
#define DATABUS_D7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define DATABUS_D7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define DATABUS_D7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define DATABUS_D7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define DATABUS_D7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define DATABUS_D7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define DATABUS_D7_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define DATABUS_D7_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISBbits.TRISB0
#define LED_LAT                  LATBbits.LATB0
#define LED_PORT                 PORTBbits.RB0
#define LED_WPU                  WPUBbits.WPUB0
#define LED_OD                   ODCONBbits.ODCB0
#define LED_ANS                  ANSELBbits.ANSELB0
#define LED_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LED_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LED_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LED_GetValue()           PORTBbits.RB0
#define LED_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LED_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define LED_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISBbits.TRISB1
#define BUTTON_LAT                  LATBbits.LATB1
#define BUTTON_PORT                 PORTBbits.RB1
#define BUTTON_WPU                  WPUBbits.WPUB1
#define BUTTON_OD                   ODCONBbits.ODCB1
#define BUTTON_ANS                  ANSELBbits.ANSELB1
#define BUTTON_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BUTTON_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BUTTON_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BUTTON_GetValue()           PORTBbits.RB1
#define BUTTON_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RWB aliases
#define RWB_TRIS                 TRISCbits.TRISC1
#define RWB_LAT                  LATCbits.LATC1
#define RWB_PORT                 PORTCbits.RC1
#define RWB_WPU                  WPUCbits.WPUC1
#define RWB_OD                   ODCONCbits.ODCC1
#define RWB_ANS                  ANSELCbits.ANSELC1
#define RWB_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RWB_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RWB_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RWB_GetValue()           PORTCbits.RC1
#define RWB_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RWB_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RWB_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RWB_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RWB_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define RWB_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define RWB_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RWB_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set CS0 aliases
#define CS0_TRIS                 TRISCbits.TRISC2
#define CS0_LAT                  LATCbits.LATC2
#define CS0_PORT                 PORTCbits.RC2
#define CS0_WPU                  WPUCbits.WPUC2
#define CS0_OD                   ODCONCbits.ODCC2
#define CS0_ANS                  ANSELCbits.ANSELC2
#define CS0_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define CS0_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define CS0_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define CS0_GetValue()           PORTCbits.RC2
#define CS0_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define CS0_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define CS0_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define CS0_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define CS0_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define CS0_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define CS0_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define CS0_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RS0 aliases
#define RS0_TRIS                 TRISCbits.TRISC4
#define RS0_LAT                  LATCbits.LATC4
#define RS0_PORT                 PORTCbits.RC4
#define RS0_WPU                  WPUCbits.WPUC4
#define RS0_OD                   ODCONCbits.ODCC4
#define RS0_ANS                  ANSELCbits.ANSELC4
#define RS0_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RS0_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RS0_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RS0_GetValue()           PORTCbits.RC4
#define RS0_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RS0_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RS0_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define RS0_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define RS0_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define RS0_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define RS0_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RS0_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RS1 aliases
#define RS1_TRIS                 TRISCbits.TRISC5
#define RS1_LAT                  LATCbits.LATC5
#define RS1_PORT                 PORTCbits.RC5
#define RS1_WPU                  WPUCbits.WPUC5
#define RS1_OD                   ODCONCbits.ODCC5
#define RS1_ANS                  ANSELCbits.ANSELC5
#define RS1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RS1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RS1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RS1_GetValue()           PORTCbits.RC5
#define RS1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RS1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RS1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define RS1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define RS1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define RS1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define RS1_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RS1_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSELD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSELD0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/