/*# LCD Interface with PIC16F877A – MPLAB & Proteus

This project demonstrates the interfacing of a 16x2 LCD with a PIC16F877A microcontroller using MPLAB for programming and Proteus for simulation.

## Features
- Pressing **S1** → LCD displays: `Hi`
- Pressing **S2** → LCD displays: `Hello`

## Tools Used
- **MPLAB** for Embedded C coding
- **Proteus** for circuit simulation
- **PIC16F877A Microcontroller**
- **16x2 LCD**, **Push Buttons**, and related components

## Simulation Screenshot
*(Add your simulation image here if available)*

## Author
Edvin Jose Vakaparamban*/
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define RS RD0
#define EN RD1
#define LCD_PORT PORTD

#include <xc.h>
#define _XTAL_FEEQ 16000000
     void lcd();
     void cmd(int);
     void data1(char);
     void display(char*);
     void delay();
     
     void main() {
     PORTD=0;
     TRISD=0;
     PORTC=0;
     TRISC=0;
     while(1){
     lcd();
     display("hi");
     }
     }
     
     void lcd() {
     cmd(0x38);
     cmd(0x0e);
     cmd(0x01);
     cmd(0x06);
     cmd(0x80);
     }
     
     void cmd(int a){
     PORTD=a;
     PORTC=0x00;
     PORTC=0x02;
     delay();
     PORTC=0x00;
     }
     
     void data1(char x){
     PORTD=x;
     PORTC=0x01;
     PORTC=0x02;
     delay();
     PORTC=0x00;
     }
     
     void display(char*s){
     while(*s!='\0'){
     data1(*s);
     s++;
     }
     }
     void delay(){
     int i,j;
     for(i=0;i<250;i++)
     for(j=0;j<250;j++);
     }
