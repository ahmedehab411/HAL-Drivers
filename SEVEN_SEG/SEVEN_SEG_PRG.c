/*
 * SEVEN_SEG_PRG.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Ahmed Ehab
 */

#include"LIB\stdtypes.h"
#include"LIB\bitmath.h"

#include"../../MCAL/DIO/DIO_INT.h"

#include"SEVEN_SEG_CONFIG.h"
#include"SEVEN_SEG_INT.h"

u8 SEVEN_SEG_u8Init()
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Mode == MODE_FULL_PORT_DIS)
	{
		Local_u8ErrorStatus=DIO_u8SetPinDir(PinAPort,PinA,OUTPUT);
		if(Local_u8ErrorStatus ==RT_OK)
		{
			Local_u8ErrorStatus=DIO_u8SetPinDir(PinBPort,PinB,OUTPUT);
			if(Local_u8ErrorStatus ==RT_OK)
			{
				Local_u8ErrorStatus=DIO_u8SetPinDir(PinCPort,PinC,OUTPUT);
				if(Local_u8ErrorStatus ==RT_OK)
				{
					Local_u8ErrorStatus=DIO_u8SetPinDir(PinDPort,PinD,OUTPUT);
					if(Local_u8ErrorStatus ==RT_OK)
					{
						Local_u8ErrorStatus=DIO_u8SetPinDir(PinEPort,PinE,OUTPUT);
						if(Local_u8ErrorStatus ==RT_OK)
						{
							Local_u8ErrorStatus=DIO_u8SetPinDir(PinFPort,PinF,OUTPUT);
							if(Local_u8ErrorStatus ==RT_OK)
							{
								Local_u8ErrorStatus=DIO_u8SetPinDir(PinGPort,PinG,OUTPUT);
								if(Local_u8ErrorStatus ==RT_OK)
								{
									Local_u8ErrorStatus=DIO_u8SetPinDir(PinDotPort,PinDot,OUTPUT);
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Mode == MODE_FULL_PORT_EN)
	{
		Local_u8ErrorStatus=DIO_u8SetPortDir(PortNo,FULL_OUTPUT);
	}
	return Local_u8ErrorStatus;
}
u8 SEVEN_SEG_u8SetNo(u8 Number,DOT_STAT Status)
{
	u8 Local_u8ErrorStatus=RT_NOK;
	u8 Num=SEVEN_SEG_GetNum(Number);
	if(CommonType==COMMON_TYPE_CATHODE)
	{
	}
	else if(CommonType==COMMON_TYPE_ANODE)
	{
		Num=~Num;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	if(Mode == MODE_FULL_PORT_DIS && Local_u8ErrorStatus==RT_OK)
	{
		Local_u8ErrorStatus=DIO_u8SetPinVal(PinAPort,PinA,Get_Bit(Num,0));
		if(Local_u8ErrorStatus ==RT_OK)
			{
			Local_u8ErrorStatus=DIO_u8SetPinVal(PinBPort,PinB,Get_Bit(Num,1));
			if(Local_u8ErrorStatus ==RT_OK)
			{
				Local_u8ErrorStatus=DIO_u8SetPinVal(PinCPort,PinC,Get_Bit(Num,2));
				if(Local_u8ErrorStatus ==RT_OK)
				{
					Local_u8ErrorStatus=DIO_u8SetPinVal(PinDPort,PinD,Get_Bit(Num,3));
					if(Local_u8ErrorStatus ==RT_OK)
					{
						Local_u8ErrorStatus=DIO_u8SetPinVal(PinEPort,PinE,Get_Bit(Num,4));
						if(Local_u8ErrorStatus ==RT_OK)
						{
							Local_u8ErrorStatus=DIO_u8SetPinVal(PinFPort,PinF,Get_Bit(Num,5));
							if(Local_u8ErrorStatus ==RT_OK)
							{
								Local_u8ErrorStatus=DIO_u8SetPinVal(PinGPort,PinG,Get_Bit(Num,6));
								if(Local_u8ErrorStatus ==RT_OK && Status==DOT_STAT_EN)
								{
									Local_u8ErrorStatus=DIO_u8SetPinVal(PinDotPort,PinDot,Get_Bit(Num,7));
								}
								else if(Local_u8ErrorStatus ==RT_OK && Status==DOT_STAT_EN)
								{
									Local_u8ErrorStatus=DIO_u8SetPinVal(PinDotPort,PinDot,LOW);
								}
								else
								{
									Local_u8ErrorStatus=RT_NOK;
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Mode == MODE_FULL_PORT_EN)
	{
		Local_u8ErrorStatus=DIO_u8SetPortVal(PortNo,Num);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	return Local_u8ErrorStatus;
}
u8 SEVEN_SEG_GetNum(u8 Num)
{
	u8 Number=NUMBER_EIGHT;
	switch (Num)
	{
		case 0:
			Number=NUMBER_ZERO;
			break;
		case 1:
			Number=NUMBER_ONE;
			break;
		case 2:
			Number=NUMBER_TWO;
			break;
		case 3:
			Number=NUMBER_THREE;
			break;
		case 4:
			Number=NUMBER_FOUR;
			break;
		case 5:
			Number=NUMBER_FIVE;
			break;
		case 6:
			Number=NUMBER_SIX;
			break;
		case 7:
			Number=NUMBER_SEVEN;
			break;
		case 8:
			Number=NUMBER_EIGHT;
			break;
		case 9:
			Number=NUMBER_NINE;
			break;
		default:
			break;
	}
	return Number;
}
u8 SEVEN_SEG_u8PortInit(DIO_PORT PortNo)
{
	u8 Local_u8ErrorStatus=RT_OK;
	Local_u8ErrorStatus=DIO_u8SetPortDir(PortNo,FULL_OUTPUT);
	return Local_u8ErrorStatus;
}

u8 SEVEN_SEG_u8PortSetNo(DIO_PORT PortNo,u8 Number,DOT_STAT Status)
{
	u8 Local_u8ErrorStatus=RT_NOK;
	u8 Num=SEVEN_SEG_GetNum(Number);
	if(CommonType==COMMON_TYPE_CATHODE)
	{
	}
	else if(CommonType==COMMON_TYPE_ANODE)
	{
		Num=~Num;
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}
	Local_u8ErrorStatus=DIO_u8SetPortVal(PortNo,Num);
	return Local_u8ErrorStatus;
}
