/******************************************************************
  Project name : PLC-DIO Library v. 1.1
  Author       : 
  Date Time    :
  Description  : Digital IO shield  
  CPU BOARD    : MicroPLC
  URL          : www.plc-expert.com
******************************************************************/

#include "PLC_DIO.h"

//PRIVATE METHODS
void PLC_DIO::SetupPorts()
{
  pinMode(INPUT_1, INPUT);	
  pinMode(INPUT_2, INPUT);
  pinMode(INPUT_3, INPUT);
  pinMode(INPUT_4, INPUT);
  pinMode(INPUT_5, INPUT);
  pinMode(INPUT_6, INPUT);
  pinMode(INPUT_7, INPUT);
  //pinMode(INPUT_8, INPUT);	//ANALOG
  //pinMode(INPUT_9, INPUT);	//ANALOG
  pinMode(INPUT_10, INPUT);
  pinMode(INPUT_11, INPUT);
  pinMode(INPUT_12, INPUT);
  pinMode(INPUT_13, INPUT);
  
  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(OUTPUT_3, OUTPUT);
  pinMode(OUTPUT_4, OUTPUT);
  pinMode(OUTPUT_5, OUTPUT);
  pinMode(OUTPUT_6, OUTPUT);
  pinMode(OUTPUT_7, OUTPUT); 
}

//PUBLIC METHODSbool PLC_DIO::Input(int InputNumber){
  	byte port_number;
	
	switch(InputNumber)
	{
		case 1:	
			port_number = INPUT_1;
			break;
		case 2:
			port_number = INPUT_2;
			break;
		case 3:
			port_number = INPUT_3;
			break;
		case 4:
			port_number = INPUT_4;
			break;
		case 5:
			port_number = INPUT_5;
			break;
		case 6:
			port_number = INPUT_6;
			break;
		case 7:
			port_number = INPUT_7;
			break;
		case 8:
			port_number = INPUT_8;
			break;
		case 9:
			port_number = INPUT_9;
			break;
		case 10:		
			port_number = INPUT_10;
			break;
		case 11:
			port_number = INPUT_11;
			break;
		case 12:
			port_number = INPUT_12;
			break;
		case 13:
			port_number = INPUT_13;
			break;
	}
	
	if(port_number == INPUT_8 || port_number == INPUT_9)
	{
		//analog inputs only
		return (analogRead(port_number) < 500);
	}
	else
	{
		return !digitalRead(port_number);  
	}
}

void PLC_DIO::Output(int OutputNumber, bool NewState){
	byte port_number;

	switch(OutputNumber)
	{
		case 1:	
			port_number = OUTPUT_1;
			break;
		case 2:
			port_number = OUTPUT_2;
			break;
		case 3:
			port_number = OUTPUT_3;
			break;
		case 4:
			port_number = OUTPUT_4;
			break;
		case 5:
			port_number = OUTPUT_5;
			break;
		case 6:
			port_number = OUTPUT_6;
			break;
		case 7:
			port_number = OUTPUT_7;
			break;
	}	
	
	digitalWrite(port_number, NewState);
}