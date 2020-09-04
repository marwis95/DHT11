/*
 * main.c    ATmega32    F_CPU = 8000000 Hz
 * 
 * Created on: 2020-09-04
 *     Author: admin                                              
*/
#include <avr/io.h>
#include "hd44780.h"   
#include "dht.h"                                       
#include <stdlib.h>
#include <stdio.h>                        
                                               
                                                            
int main (void){                                                          
    char bufor[8];                                                  
    int8_t wilgotnosc = 0;                                            
    LCD_Initalize();                                        
                                                                
    while(1){                                                                           
        LCD_GoTo(4,0);                                                                        
        LCD_WriteText("DHT11:           ");                         
        wilgotnosc = dht11_gethumidity();  
        if(wilgotnosc != -1){          
            itoa(wilgotnosc, bufor, 10);                            
            LCD_GoTo(0,1);                            
            LCD_WriteText(bufor);
        }
        _delay_ms(1500);
    }                                                           
}  