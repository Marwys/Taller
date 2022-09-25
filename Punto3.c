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
#define TIEMPO 10

const unsigned char DIGITOS[10] = {0x3F, 0x06,  0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; // Constante de numeros que mostrar el display en hexadecimal


void mostrar_numeros(int valor) // Funcion para mostrar los numeros 

{

    
    unsigned char mil = 0;
    
    unsigned char cen = 0;

    unsigned char dec= 0;

    unsigned char uni = 0;


    
    mil = valor /1000; // Variable que almacenara las milesimas
    
    cen = (valor/100)%10; // Variable que almacenara las centanas

    dec = (valor/10)%10; // Variable que almacenara las decenas

    uni = valor%10; //Variable que almacenara las unidades
  
  /*
    Aqui se mostrara la forma de multiplexar la cual consistera
    en primero Mandar una señal al puerto para que manda por el 
    canal el pulso mostrando el numero correspondiente
    del 0 al 9 y activando el puerto correspondiente del display
    osea, activando la salida del ppuerto D .
    Ya que nuestra variable digitos es constante cuando
    esta llegue al 9 se desbordara y volvera al 0. Con esto en mente
    se usara para ahorrar espacio en PIC y codigo 
  */

    
    PORTC = DIGITOS[uni];

    PORTD = 0x08;

    __delay_ms(TIEMPO);

    PORTD = 0x00;


    PORTC = DIGITOS[dec];

    PORTD = 0x04;

    __delay_ms(TIEMPO);

    PORTD = 0x00;
    
    
    PORTC = DIGITOS[cen];
    
    PORTD = 0x02;
    
    __delay_ms(TIEMPO);
    
    PORTD = 0x00;
    
    PORTC = DIGITOS[mil];
    
    PORTD = 0x01;
    
    __delay_ms(TIEMPO);
    
    PORTD = 0x00;
            

}


int main(void)

{
    unsigned int co = 0;
    unsigned char cont = 0;

    int valor = 0;

    
    PORTC = 0x00;
    TRISC = 0x00;
    PORTD = 0x00;
    TRISD = 0x30;


    while(1)

    {  
                
        mostrar_numeros(valor);

       
        cont++;

        if(cont == 12)

        {

            cont = 0;

            valor++;

            
            if(valor == 10000)

            {

                valor = 0;

            }

        }

    } 
    return 0;

}
