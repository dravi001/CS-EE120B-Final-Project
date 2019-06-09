#include <avr/io.h>
#include "timer.c"
#include <string.h>
#include <util/delay.h>
#include "nokia5110.c"
#include <avr/eeprom.h>

unsigned char readValue() {
	
	return eeprom_read_byte(0x0F);
}
void writeValue(unsigned char score) {
	eeprom_write_byte(0x0F, score);
}

enum PatternStates {P_start, P_Welcome, P_One, P_Two, P_Three, P_Four, P_Five, P_Six, P_Seven, P_Eight, P_End} PatternState;
enum ScoreStates {S_start, S_Welcome, S_One, S_Two, S_Three, S_Four, S_Five, S_Six, S_Seven, S_Eight, S_End} ScoreState;
	

unsigned char button  = 0x00;
unsigned char button1 = 0x00;
unsigned char button2 = 0x00;
unsigned char button3 = 0x00;
unsigned char button4 = 0x00;

unsigned char x = 0x00;
unsigned char y = 0x00;

unsigned char score = 0x00;


void Pattern_tick(){ // Used for pattern outputs
	button  = ~PINA & 0x01;
	
	x = 60;
	y = 40;
	
	switch(PatternState){ // transitions
		case P_start:
		PatternState = P_Welcome;
		break;
		
		case P_Welcome:
		if(button){
			PatternState = P_One;
		}
		else{
			PatternState = P_Welcome;
		}
		break;
		
		case P_One:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Two;
		}
		break;
		
		case P_Two:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Three;
		}
		break;
		
		case P_Three:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Four;
		}
		break;
		
		case P_Four:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Five;
		}	
		break;
		
		case P_Five:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Six;
		}
		break;
		
		case P_Six:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Seven;
		}
		break;
		
		case P_Seven:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Eight;
		}
		break;
		
		case P_Eight:
		if (button){
			PatternState = P_End;
		}
		else{
			PatternState = P_Five;
		}
		break;
		
		case P_End:
		if (button){
			PatternState = P_start;
		}
		else{
			PatternState = P_End;
		}
		break;
	}
	switch(PatternState){ // actions
		case P_start:
		//score = 0;
		break;
		
		case P_Welcome:
		nokia_lcd_clear();
		nokia_lcd_write_string("Pattern", 2);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("Hero", 2);
		nokia_lcd_render();
		nokia_lcd_set_pixel(65,25,6);
		nokia_lcd_set_pixel(66,25,6);
		nokia_lcd_set_pixel(67,25,6);
		nokia_lcd_set_pixel(68,25,6);
		nokia_lcd_set_pixel(69,25,6);
		nokia_lcd_set_pixel(70,25,6);
		nokia_lcd_set_pixel(71,25,6);
		nokia_lcd_set_pixel(72,25,6);
		nokia_lcd_set_pixel(73,25,6);
		nokia_lcd_set_pixel(74,25,6);
		nokia_lcd_set_pixel(75,25,6);
		nokia_lcd_set_pixel(75,25,6);
		nokia_lcd_set_pixel(75,26,6);
		nokia_lcd_set_pixel(75,27,6);
		nokia_lcd_set_pixel(75,28,6);
		nokia_lcd_set_pixel(75,29,6);
		nokia_lcd_set_pixel(75,30,6);
		nokia_lcd_set_pixel(75,31,6);
		nokia_lcd_set_pixel(75,32,6);
		nokia_lcd_set_pixel(75,33,6);
		nokia_lcd_set_pixel(75,34,6);
		nokia_lcd_set_pixel(75,35,6);
		_delay_ms(1000);
		
		for (unsigned char i; i < 20; i++){
			nokia_lcd_set_pixel(x,40,6);
			x++;
			nokia_lcd_render();
		}
		for (unsigned char i; i < 20; i++){
			nokia_lcd_set_pixel(80,y,6);
			y--;
			nokia_lcd_render();
		}
		for (unsigned char i; i < 20; i++){
			nokia_lcd_set_pixel(x,20,6);
			x--;
			nokia_lcd_render();
		}
		for (unsigned char i; i < 20; i++){
			nokia_lcd_set_pixel(60,y,6);
			y++;
			nokia_lcd_render();
		}
		
		break;
		
		case P_One:
		nokia_lcd_clear();
		nokia_lcd_write_string("3",3);
		nokia_lcd_render();
		_delay_ms(10000);
		nokia_lcd_clear();
		nokia_lcd_write_string(" 2",3);
		nokia_lcd_render();
		_delay_ms(10000);
		nokia_lcd_clear();
		nokia_lcd_write_string("  1", 3);
		nokia_lcd_render();
		_delay_ms(10000);
		nokia_lcd_clear();
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("*       X    ",1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);
		break;
		
		case P_Two:
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("    O   X    ",1);
		nokia_lcd_set_cursor(0,10);
		nokia_lcd_write_string("*       X    ",1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);
		break;
		
		case P_Three:
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("*           @",1);
		nokia_lcd_set_cursor(0,10);
		nokia_lcd_write_string("    O   X    ",1);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("*       X    ", 1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);
		break;
		
		case P_Four:
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("*            ",1);
		nokia_lcd_set_cursor(0,10);
		nokia_lcd_write_string("*           @",1);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("    O   X    ", 1);
		nokia_lcd_set_cursor(0,40);
		nokia_lcd_write_string("*       X    ", 1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);
		break;
		
		case P_Five:
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("    O       @",1);
		nokia_lcd_set_cursor(0,10);
		nokia_lcd_write_string("*            ",1);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("*           @", 1);
		nokia_lcd_set_cursor(0,40);
		nokia_lcd_write_string("    O   X    ", 1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);
		break;
		
		case P_Six:
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("    O   X    ",1);
		nokia_lcd_set_cursor(0,10);
		nokia_lcd_write_string("    O       @",1);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("*            ", 1);
		nokia_lcd_set_cursor(0,40);
		nokia_lcd_write_string("*           @", 1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);

		break;
		
		case P_Seven:
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("*           @",1);
		nokia_lcd_set_cursor(0,10);
		nokia_lcd_write_string("    O   X    ",1);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("    O       @", 1);
		nokia_lcd_set_cursor(0,40);
		nokia_lcd_write_string("*            ", 1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);

		break;
		
		case P_Eight:
		nokia_lcd_set_cursor(0,0);
		nokia_lcd_write_string("*            ",1);
		nokia_lcd_set_cursor(0,10);
		nokia_lcd_write_string("*           @",1);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("    O   X    ", 1);
		nokia_lcd_set_cursor(0,40);
		nokia_lcd_write_string("    O       @", 1);
		nokia_lcd_set_cursor(0,30);
		nokia_lcd_write_string("==============",1);
		nokia_lcd_render();
		_delay_ms(10000);
		
		case P_End:
		nokia_lcd_clear();
		nokia_lcd_write_string("   Game", 2);
		nokia_lcd_set_cursor(0,20);
		nokia_lcd_write_string("   Over", 2);
		nokia_lcd_render();
		_delay_ms(3000);
		break;
	}
}

void Score_tick(){ // Used for score inputs
		button  = ~PINA & 0x01;
		button1 = ~PINA & 0x02;
		button2 = ~PINA & 0x04;
		button3 = ~PINA & 0x08;
		button4 = ~PINA & 0x16;
		
		switch(ScoreState) {// transitions
			case S_start:
			ScoreState = S_Welcome;
			break;
			
			case S_Welcome:
			if(button){
				ScoreState = S_One;
			}
			else{
				ScoreState = S_Welcome;
			}
			break;
			
			case S_One:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Two;
			}
			break;
			
			case S_Two:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Three;
			}
			break;
			
			case S_Three:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Four;
			}
			break;
			
			case S_Four:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Five;
			}
			break;
			
			case S_Five:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Six;
			}
			break;
			
			case S_Six:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Seven;
			}
			break;
			
			case S_Seven:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Eight;
			}
			break;
			
			case S_Eight:
			if (button){
				ScoreState = S_End;
			}
			else{
				ScoreState = S_Five;
			}
			break;
			
			case S_End:
			if (button){
				ScoreState = S_start;
			}
			else{
				PatternState = S_End;
			}
			break;
		}
		
		switch(ScoreState){ // actions
			case S_start:
			break;
			
			case S_One:
			_delay_ms(40000);
			break;
			
			case S_Two:
			_delay_ms(10000);
			break;
			
			case S_Three:
			_delay_ms(10000);
			break;
			
			case S_Four:
			_delay_ms(10000);
			if (button1 && button3 && !button2 && !button4){
			score++;
			}
			break;
			
			case S_Five:
			_delay_ms(10000);
			if (button2 && button3 && !button1 && !button4){
				score++;
			}
			break;
			
			case S_Six:
			_delay_ms(10000);
			if (button1 && button4 && !button3 && !button2){
				score++;
			}
			break;
			
			case S_Seven:
			_delay_ms(10000);
			if(button1 && !button2 && !button3 && !button4){
				score++;
			}
			break;
			
			case S_Eight:
			_delay_ms(10000);
			if (button2 && button4 && !button1 && !button3){
				score++;
			}
			break;
			
			case S_End:
			if (score > readValue()){
				writeValue(score);
			}
			PORTD = readValue();
			_delay_ms(3000);
			break;
		}
}


int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	//unsigned char i = 0;
	nokia_lcd_init();
	nokia_lcd_clear();
	if (readValue() == 255){
		writeValue(0);
	}

	while(1) {
		PORTD = readValue();
		Pattern_tick();
		Score_tick();
		_delay_ms(50);
		nokia_lcd_render();
	}
}
