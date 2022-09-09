/*********************************************************
* lab4.c
* Lab 4 ECE 231
* Writing a program to make LEDs light up on the breadboard 
* differing in brightness depending on the button pressed

* Date         Author          Revision
* 04/20/2022   Ritvik Verma    Lab 4 code write 

*References
*Proffesor McLaughlin's Lecture 16,17,18 Spring 2022
**********************************************************/
#include <avr/io.h>
#include <util/delay.h>

int main(void){

    DDRD = 1<< DDD6; //PD6 is output for LED
    PORTB = 1<<PORTB1|1<<PORTB2; //internal pullup resistor on B1 and B2

    //Initialize timer0 for FASTPWM, /64 prescaler
    TCCR0A = 0x81;  
    TCCR0B = 0x03;

    while(1){
        
        if (((PINB & (1<<PINB1))==0) && ((PINB & (1<<PINB2))==0)){ //if both buttons are pressed
            OCR0A = 255;    //set OCR0A to 255 for full brightness
            DDRD = 1<<DDD6; //make output pin 6 as output
            
        }
        else if (((PINB & (1<<PINB1))==0) && ((PINB & (1<<PINB2))!=0)){ //if button 1 is pressed
            OCR0A = 30; //set OCR0A to 30 for dim brightness
            DDRD = 1<<DDD6;
        }
        else if (((PINB & (1<<PINB1))!=0) && ((PINB & (1<<PINB2))==0)){ //if button 2 is pressed    
            OCR0A = 100;  //set OCR0A to 100 for medium brightness
            DDRD = 1<<DDD6;
        }
        else if (((PINB & (1<<PINB1))!=0) && ((PINB & (1<<PINB2))!=0)){ //if both buttons are not pressed
            OCR0A = 0;  //turn off LED
            DDRD = 1<<DDD6; 
        }
    }
    return 0;
}
