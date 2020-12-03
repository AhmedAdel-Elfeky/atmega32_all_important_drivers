
#include "std_types.h"
#include "AVR_DIOReg.h"
#include "DIO_int.h"



void DIO_vidSetPortDirection(u8 u8PortCPY , u8 u8DirectionCPY)
{
	switch (u8PortCPY)
	{
		case PORT_A:
		{
			DDRA=u8DirectionCPY;
			break;
		}
		case PORT_B:
		{
			DDRB=u8DirectionCPY;
			break;
		}
		case PORT_C:
		{
			DDRC=u8DirectionCPY;
			break;
		}
		case PORT_D:
		{
			DDRD=u8DirectionCPY;
			break;
		}
		default :break;
     }
}

void DIO_vidSetPortValue(u8 u8PortCPY , u8 u8ValueCPY)
{
	switch (u8PortCPY)
		{
			case PORT_A:
			{
				PORTA=u8ValueCPY;
				break;
			}
			case PORT_B:
			{
				PORTB=u8ValueCPY;
				break;
			}
			case PORT_C:
			{
				PORTC=u8ValueCPY;
				break;
			}
			case PORT_D:
			{
				PORTD=u8ValueCPY;
				break;
			}
			default :break;
	     }
}

u8 DIO_u8GetPortValue(u8 u8PortCPY)
{
	u8 u8PinRegLOC;

	switch (u8PortCPY)
		{
			case PORT_A:
			{
				u8PinRegLOC= PINA;
				break;
			}
			case PORT_B:
			{
				u8PinRegLOC= PINB;
				break;
			}
			case PORT_C:
			{
				u8PinRegLOC= PINC;
				break;
			}
			case PORT_D:
			{
				u8PinRegLOC= PIND;
				break;
			}
			default :break;
		}
	return u8PinRegLOC;
}

void DIO_vidSetPinDirection(u8 u8PortCPY,u8 u8PinCPY,u8 u8DirectionCPY)
{
	switch(u8PortCPY)
	{
	case PORT_A:
		{
			switch(u8DirectionCPY)
			{
			case OUTPUT:
			{
				(DDRA)|=(1<<(u8PinCPY));
				break;
			}
			case INPUT:
			{
				(DDRA)&=~(1<<(u8PinCPY));
				break;
			}default:break;
			}
			break;
		}
	case PORT_B:
		{
			switch(u8DirectionCPY)
			{
			case OUTPUT:
			{
				(DDRB)|=(1<<(u8PinCPY));
				break;
			}
			case INPUT:
			{
				(DDRB)&=~(1<<(u8PinCPY));
				break;
			}default:break;
			}
			break;
		}
	case PORT_C:
		{
			switch(u8DirectionCPY)
			{
			case OUTPUT:
			{
				(DDRC)|=(1<<(u8PinCPY));
				break;
			}
			case INPUT:
			{
				(DDRC)&=~(1<<(u8PinCPY));
				break;
			}default:break;
			}
			break;
		}
	case PORT_D:
		{
			switch(u8DirectionCPY)
			{
			case OUTPUT:
			{
				(DDRD)|=(1<<(u8PinCPY));
				break;
			}
			case INPUT:
			{
				(DDRD)&=~(1<<(u8PinCPY));
				break;
			}default:break;
			}
			break;
		}
	default :break;
	}
}

void DIO_vidSetPinValue(u8 u8PortCPY,u8 u8PinCPY,u8 u8ValueCPY)
{
	switch(u8PortCPY)
	{
	case PORT_A:
	{
		switch(u8ValueCPY)
		{
		case HIGH:
		{
			(PORTA)|=(1<<(u8PinCPY));
			break;
		}
		case LOW :
		{
			(PORTA)&=~(1<<(u8PinCPY));
			break;
		}
		default:break;
		}
		break;
	}
	case PORT_B:
	{
		switch(u8ValueCPY)
		{
		case HIGH:
		{
			(PORTB)|=(1<<(u8PinCPY));
			break;
		}
		case LOW :
		{
			(PORTB)&=~(1<<(u8PinCPY));
			break;
		}
		default:break;
		}
		break;
	}
	case PORT_C:
	{
		switch(u8ValueCPY)
		{
		case HIGH:
		{
			(PORTC)|=(1<<(u8PinCPY));
			break;
		}
		case LOW :
		{
			(PORTC)&=~(1<<(u8PinCPY));
			break;
		}
		default:break;
		}
		break;
	}
	case PORT_D:
	{
		switch(u8ValueCPY)
		{
		case HIGH:
		{
			(PORTD)|=(1<<(u8PinCPY));
			break;
		}
		case LOW :
		{
			(PORTD)&=~(1<<(u8PinCPY));
			break;
		}
		default:break;
		}
		break;
	}
	default :
			break;
	}
}



u8 DIO_u8GetPinValue(u8 u8PortCPY,u8 u8PinCPY)
{
	u8 u8GetPinLOC;
	switch(u8PortCPY)
	{
	case PORT_A:
	{
		u8GetPinLOC=((PINA&(1<<u8PinCPY))>>u8PinCPY);
		break;
	}
	case PORT_B:
    {
    	 u8GetPinLOC=((PINB&(1<<u8PinCPY))>>u8PinCPY);
	     break;
	}
	case PORT_C:
	{
	   	 u8GetPinLOC=((PINC&(1<<u8PinCPY))>>u8PinCPY);
	     break;
	}
	case PORT_D:
	{
	     u8GetPinLOC=((PIND&(1<<u8PinCPY))>>u8PinCPY);
	     break;
	}
	default :break;

	}

	return u8GetPinLOC;
}
