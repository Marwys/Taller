#include <xc.h>

#pragma config FOSC = HS 
#pragma config WDTE = OFF 
#pragma config PWRTE = OFF 
#pragma config MCLRE = ON
#pragma config CP = OFF 
#pragma config CPD = OFF 
#pragma config BOREN = OFF 
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config LVP = OFF 
#pragma config DEBUG = OFF 
#define _XTAL_FREQ 20000000

void main(void) {
    
    PORTA = 0x00;
    TRISA = 0x01;
    ANSEL = 0x00;
    
    /*
     Codigo Gray esperado:
     * RA4 RA3 RA2 RA1
     * 0    0   0   0
     * 0    0   0   1
     * 0    0   1   1
     * 0    0   1   0
     * 0    1   1   0
     * 0    1   0   0   
     * 1    1   0   0
     * 1    0   0   0
     * 0    0   0   0
     */
    
    if(RA0 == 0){
        __delay_ms(1000);
        if(RA0 == 0){
            RA1 = !RA1;
            __delay_ms(1000);
            RA2 = !RA2;
            __delay_ms(1000);
            RA1 = !RA1;
            __delay_ms(1000);
            RA3 = !RA3;
            __delay_ms(1000);
            RA2 = !RA2;
            __delay_ms(1000);
            RA4 = !RA4;
            __delay_ms(1000);
            RA3 = !RA3;
            __delay_ms(1000);
            RA4 = !RA4;
        }
    }
     
    return;
}
