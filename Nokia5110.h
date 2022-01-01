/*    Author: jsegu010
 *  Partner(s) Name:
 *    Lab Section:
 *    Assignment: Lab #  Exercise #
 *    Exercise Description: [optional - include for your own benefit]
 *
 
 
 https://youtu.be/Q7RuQu2hal0 
 
    
 *    I acknowledge all content contained herein, excluding template or example
 *    code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

//P is the port, I is the port bit that will be changed
#define SET_BIT(p,i) ((p) |= ( 0x01 << (i)))
#define CLR_BIT(p,i) ((p) &= ~( 0x01 << (i)))
#define GET_BIT(p,i) ((p) & ( 0x01 << (i)))

//PORTS N STUFF
#define BUS PORTB
#define CE 0
#define RST 1
#define DC 2
#define moSI 5
#define CLK 7

void wCom(unsigned char command){
	CLR_BIT(BUS,CE);
	CLR_BIT(BUS,DC);
	unsigned char i;
	for(i = 0; i < 8; i++){
		if( ((command >> (7-i)) & 0x01) == 0x01){
			SET_BIT(BUS,moSI);
		}
		else{
			CLR_BIT(BUS,moSI);
		}
		SET_BIT(BUS,CLK);
		CLR_BIT(BUS,CLK);			
	}
	
	SET_BIT(BUS,CE);
}

void wData(unsigned char data){
	CLR_BIT(BUS,CE);
	SET_BIT(BUS,DC);
	
	unsigned char i;
	for(i = 0; i < 8; i++){
		if( ((data >> (7-i)) & 0x01) == 0x01){
			SET_BIT(BUS,moSI);
		}
		else{
			CLR_BIT(BUS,moSI);
		}
		SET_BIT(BUS,CLK);
		CLR_BIT(BUS,CLK);			
	}
	

	SET_BIT(BUS,CE);
}

void blankScrn(){
unsigned char i;
unsigned char j;
	for(i = 0; i <= 5; i++){
		for(j = 0; j <= 83; j++){
			wData(0x00);
		}
	}
	wCom(0x80); //reset position to 0,0;
	wCom(0x40);
}
void Nok_init(){
	//dont Forget to set PORTB output and portB to 0x00;
	SET_BIT(BUS,RST); // res off
	SET_BIT(BUS,CE); //CE off
	CLR_BIT(BUS,RST); // reset
	SET_BIT(BUS,RST); // res off again
	
	wCom(0x21); //H=1
	wCom(0x13); //default bias data sheet
	wCom(0x06); //default temp on data sheet
	wCom(0xC2); //default V(op) on data sheet
	wCom(0x20); // H = 0
	wCom(0x0C); // Normal mode
	
	
}
