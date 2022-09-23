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


int main(void){

    unsigned int c = 0;
    
PORTA = 0x00; //Inicialiaza el puerto A apagado
ANSEL = 0x00; // Entradas analogicas
TRISA = 0x00; //Todo el puerto A es un salida.
PORTE = 0x00; // Iniciar el puerto E apagado
TRISE = 0x01; // Solo el pin numero 1 es entrada
PORTB = 0x00; // Iniciar el puerto B Apagado
TRISB = 0x04; //Solo el pin 3 es entrada 
ANSELH = 0x00; //Entradas digitales.
   
    while(1)
    {     
        if(RB2 == 0){
            __delay_ms(1000);
            if(RB2 == 0){
                RB4 = !RB4;
                __delay_ms(100);
                c++;
                RB4 = !RB4;
                if(c > 3){
                    c = 0;
                }
            }
        }
        
        //La constante c nos permitira cambiar los modos del PIC para el resto de los modos del led.
        
        if(c == 0 )
        {
            if(RE0 == 0)
            {
                
                __delay_ms(1000);
            
                    if(RE0 == 0)
                    {
                
                    RA0 = !RA0;
                    __delay_ms(500);
                    RA0 = !RA0;
                    __delay_ms(500);
                    RA1 = !RA1;
                    __delay_ms(500);
                    RA1 = !RA1;
                    __delay_ms(500);
                    RA2 = !RA2;
                    __delay_ms(500);
                    RA2 = !RA2;
                    __delay_ms(500);
                    RA3 = !RA3;
                    __delay_ms(500);
                    RA3 = !RA3;
                    __delay_ms(500);
                    RA4 = !RA4;
                    __delay_ms(500);
                    RA4 = !RA4;
                    __delay_ms(500);
                    RA5 = !RA5;
                    __delay_ms(500);
                    RA5 = !RA5;
                    __delay_ms(500);
                    RE1 = !RE1;
                    __delay_ms(500);
                    RE1 = !RE1;
                    __delay_ms(500);
                    RE2 = !RE2;
                    __delay_ms(500);
                    RE2 = !RE2;
                    __delay_ms(500);
                    
                   }
            }
        }
        
       if(c == 1){
            if(RE0 == 0){
                __delay_ms(1000);
                if(RE0 == 0){
                    PORTE = 0x04;
                 __delay_ms(500);
                 PORTE = 0x00;
                 __delay_ms(500);
                 PORTE = 0x02;
                 __delay_ms(500);
                 PORTE = 0x00;
                 __delay_ms(500);
                 PORTA = 0x20;
                 __delay_ms(500);
                 PORTA = 0x00;
                 __delay_ms(500);
                 PORTA = 0x10;
                 __delay_ms(500);
                 PORTA = 0x00;
                 __delay_ms(500);
                 PORTA = 0x08;
                 __delay_ms(500);
                 PORTA = 0x00;
                 __delay_ms(500);
                 PORTA = 0x04;
                 __delay_ms(500);
                 PORTA = 0x00;
                 __delay_ms(500);
                 PORTA = 0x02;
                 __delay_ms(500);
                 PORTA = 0x00;
                 __delay_ms(500);
                 PORTA = 0x01;
                 __delay_ms(500);
                 PORTA = 0x00;
                }
            }
        }
        if(c == 2){
            if(RE0 == 0){
                __delay_ms(1000);
                if(RE0 == 0){
                    
                    RA3 = !RA3;
                    RA4 = !RA4;
                    __delay_ms(500);
                    RA3 = !RA3;
                    RA4 = !RA4; //1ra
                    __delay_ms(500);
                    RA2 = !RA2;
                    RA5 = !RA5;
                    __delay_ms(500);
                    RA2 = !RA2;
                    RA5 = !RA5; //2da
                    __delay_ms(500);
                    RA1 = !RA1;
                    RE1 = !RE1;
                    __delay_ms(500);
                    RA1 = !RA1;
                    RE1 = !RE1;//3ra
                    __delay_ms(500);
                    RA0 = !RA0;
                    RE2 = !RE2;
                    __delay_ms(500);
                    RA0 = !RA0;
                    RE2 = !RE2;//4ta
                    __delay_ms(500);
                    
                }
                }
        }
        if(c == 3){
            if(RE0 == 0){
                __delay_ms(1000);
                if(RE0 == 0){
                    RA0 = !RA0;
                    RE2 = !RE2;
                    __delay_ms(500);
                    RA0 = !RA0;
                    RE2 = !RE2;
                    __delay_ms(500);
                    RA1 = !RA1;
                    RE1 = !RE1;
                    __delay_ms(500);
                    RA1 = !RA1;
                    RE1 = !RE1;
                    __delay_ms(500);
                    RA2 = !RA2;
                    RA5 = !RA5;
                    __delay_ms(500);
                    RA2 = !RA2;
                    RA5 = !RA5; 
                    __delay_ms(500);
                    RA3 = !RA3;
                    RA4 = !RA4;
                    __delay_ms(500);
                    RA3 = !RA3;
                    RA4 = !RA4; 
                    __delay_ms(500);
                }
                }
        }
    }
    return 0;

}
