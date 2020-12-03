#include "types.h"
#include "dio.h"
#include "util\delay.h"
#include "lcd4bits.h"
#include <avr/io.h>
u8 counter =0 ;
u8 cpy_port = 0b00000000;

void LCD_WriteCommand(u8 command)
{
	cpy_port = (cpy_port & 0x0F) | (command & 0xF0); // send first 4 bits
	set_port_value(LCD_port,cpy_port);


	set_pin_value(LCD_ConPort,RS,0); //write commend
	set_pin_value(LCD_ConPort,RW,0);


	set_pin_value(LCD_ConPort,E,1); //pulse
	_delay_ms(1);
	set_pin_value(LCD_ConPort,E,0);

	_delay_us(200);

	cpy_port = (cpy_port & 0x0F) | (command << 4); // send second four bits
	set_port_value(LCD_port,cpy_port);


	set_pin_value(LCD_ConPort,E,1); // pulse
	_delay_ms(1);
	set_pin_value(LCD_ConPort,E,0);


	_delay_ms(2);


}




void LCD_int(void)
{
    set_pin_direction(LCD_port , D7, 1);
    set_pin_direction(LCD_port , D6, 1);
    set_pin_direction(LCD_port , D5, 1);
    set_pin_direction(LCD_port , D4, 1);

    set_pin_direction(LCD_ConPort , RS, 1);
    set_pin_direction(LCD_ConPort , RW, 1);
    set_pin_direction(LCD_ConPort , E, 1);



	    _delay_ms(50);                       //wait 50 ms
	    LCD_WriteCommand(0b00110011);
	    LCD_WriteCommand(0b00110010);
	    LCD_WriteCommand(0b00101000);        //2 line and 5*7 dot
		_delay_ms(1);                        //wait 1 ms
		LCD_WriteCommand(0b00001100);       //display and curser
		_delay_ms(1);                        //wait 1 ms
		LCD_WriteCommand(0b00000001);        //clear
		_delay_ms(2);                        //wait 2 ms
		LCD_WriteCommand(0b00000110);       //entry

}



void LCD_WriteData(u8 data)
{
	cpy_port = (cpy_port & 0x0F) | (data & 0xF0); // send first 4 bits
		set_port_value(LCD_port,cpy_port);


		set_pin_value(LCD_ConPort,RS,1); //write data
		set_pin_value(LCD_ConPort,RW,0);


		set_pin_value(LCD_ConPort,E,1); //pulse
		_delay_ms(1);
		set_pin_value(LCD_ConPort,E,0);

		_delay_us(200);

		cpy_port = (cpy_port & 0x0F) | (data << 4); // send second four bits
		set_port_value(LCD_port,cpy_port);

		set_pin_value(LCD_ConPort,RS,1); //write data
		set_pin_value(LCD_ConPort,RW,0);


		set_pin_value(LCD_ConPort,E,1); // pulse
		_delay_ms(1);
		set_pin_value(LCD_ConPort,E,0);


		_delay_ms(2);

}




void LCD_WriteData_counter (u8 data)
{

	cpy_port = (cpy_port & 0x0F) | (data & 0xF0); // send first 4 bits
		set_port_value(LCD_port,cpy_port);


		set_pin_value(LCD_ConPort,RS,1); //write data
		set_pin_value(LCD_ConPort,RW,0);


		set_pin_value(LCD_ConPort,E,1); //pulse
		_delay_ms(1);
		set_pin_value(LCD_ConPort,E,0);

		_delay_us(200);

		cpy_port = (cpy_port & 0x0F) | (data << 4); // send second four bits
		set_port_value(LCD_port,cpy_port);


		set_pin_value(LCD_ConPort,E,1); // pulse
		_delay_ms(1);
		set_pin_value(LCD_ConPort,E,0);


		_delay_ms(2);


	counter++ ;
     if (counter == 16){
		LCD_WriteCommand(0xc0);

	}
	else{}
}




void LCD_int_Cursor(void)
{
  set_port_direction(LCD_port , 0xff);
    set_port_direction(LCD_ConPort , 0xff);
     set_pin_direction(LCD_port , D7, 1);
     set_pin_direction(LCD_port , D6, 1);
     set_pin_direction(LCD_port , D5, 1);
     set_pin_direction(LCD_port , D4, 1);

     set_pin_direction(LCD_ConPort , RS, 1);
     set_pin_direction(LCD_ConPort , RW, 1);
     set_pin_direction(LCD_ConPort , E, 1);



    _delay_ms(50);                       //wait 50 ms
    LCD_WriteCommand(0x33);
    LCD_WriteCommand(0x32);
    LCD_WriteCommand(0b00101000);        //2 line and 5*7 dot
	_delay_ms(1);                        //wait 1 ms
	LCD_WriteCommand(0b00001111);       //display and curser
	_delay_ms(1);                        //wait 1 ms
	LCD_WriteCommand(0b00000001);        //clear
	_delay_ms(2);                        //wait 2 ms
	LCD_WriteCommand(0b00000110);       //entry

}



void Set_cursor(u8 LR , u8 step){
	u8 i = 0;
	if (LR == 0){//left
		for (i= 0 ; i < step ;  i++){

				LCD_WriteCommand(0b00010011);
		}


	}

	else if (LR == 1){//right
		for (i= 0 ; i < step ;  i++){
		LCD_WriteCommand(0b00010111);
		}
	}

	else{}



}


void Next_line (void){
	counter =0 ;
	LCD_WriteCommand(0xc0);
}




void shift (u8 LR ,  u8 step){

	u8 i = 0;

	if (LR ==0 ){//left
		for (i= 0 ; i < step ;  i++){

		LCD_WriteCommand(0b00011011);}

	}
	else if (LR== 1){//right
		for (i= 0 ; i < step ;  i++){

		LCD_WriteCommand(0b00011111);}

	}
	else{}

}



void clear (void ){
	LCD_WriteCommand(0b00000001);
			_delay_ms(2);

}




void Return_home (void){
	LCD_WriteCommand(0b00000011);

}



void write_data_string(unsigned char *str)                //take address value of the string in pointer *str
{
int i=0;
while(str[i]!='\0')                                       //the loop will done until the value is null
 {
	if (i==16)                                            //chick if the first line in LCD is full
	 {
		LCD_WriteCommand(0b11000000);                            //start write on second line
 	 }

	LCD_WriteData(str[i]);
     i++;
 }
}





void int_to_lcd(u32 number)
 {
	 u32 copy;
	  u8 lenght=0 , arr[10]={0} ;
	 u8 asky[10] = {'0','1','2','3','4','5','6','7','8','9'} ;
	 s8 i;
	 copy=number;
	 while(copy != 0)
	 {
		 lenght++;
		 copy/=10;
	 }
	 for(i=0;i<lenght;i++)
	 {
		 arr[i] = number % 10;
		 number/=10;
	 }
	 for(i=lenght-1;i>=0;i--)
	 {
		 LCD_WriteData(asky[arr[i]]);
	 }
 }







void LCD_Custom_Char (u8 loc, u8 *msg)
{
    u8 i;
    if(loc<8)
    {
    	LCD_WriteCommand (0x40 + (loc*8));  /* Command 0x40 and onwards forces
                                       the device to point CGRAM address */
       for(i=0;i<8;i++)  /* Write 8 byte for generation of 1 character */
    	   LCD_WriteData(msg[i]);
    }
    LCD_WriteCommand(0x80);
}











