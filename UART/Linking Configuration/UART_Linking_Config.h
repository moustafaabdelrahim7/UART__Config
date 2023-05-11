

#ifndef UART_H_
#define UART_H_
/************************************************************************************************************************************************
																	 Includes
*************************************************************************************************************************************************/

#include "uart_config.h"
#include "Std_Types.h"

/******************************************************************End Of Includes***************************************************************************/

/************************************************************************************************************************************************
																MemoryMaping
**************************************************************************************************************************************************/
#define UDR *((volatile uint8_t*)0x2C)
#define UCSRA *((volatile uint8_t*)0x2B)
#define UCSRB *((volatile uint8_t*)0x2A)
#define UCSRC *((volatile uint8_t*)0x40)
#define UBRRL *((volatile uint8_t*)0x29)
#define UBRRH *((volatile uint8_t*)0x40)

/************************************************************End Of Maping*************************************************************************/

/*****************************************************************************************************************************************************
																Bit Defines
***************************************************************************************************************************************************/

#define  RXEN  4
#define  TXEN  3
#define  URSEL 7
#define  UCSZ0 1
#define  UDRE  5
#define  RXC   7
#define  UCSZ1 2

#define U2X				2
#define URSEL			7

#define UPM0			4
#define UPM1			5

#define TXEN			3
#define RXEN			4

#define UCSZ0			1
#define UCSZ1			2
#define UCSZ2			2
#define USBS			3
#define UMSEL			6

#define UDRE			5
#define TXC				6
#define RXC				7

#define RUSBS			3
#define RUPM0			4
#define RUPM1			5


/************************************************************End Of Defines*************************************************************************/

/***********************************************************************************************************************************************
															Macros
**************************************************************************************************************************************************/

/*
speed modes Selection
*/
#define  normal_speed     0
#define  double_speed     1
#define  total_speed      2
/*
parity Selection
*/
#define NO_PARITY    0
#define EVEN_PARITY  1
#define ODD_PARITY   2
/*
Type Of Synchronism 
*/
#define  SYNCH  0
#define  ASYNCH 1
/*
stop bits	selection
*/
#define  ONE_STOP_BIT   1
#define  TWO_STOP_BIT   2
/*
 data Size Selection
*/
#define  _5_DATA_BITS    5
#define  _6_DATA_BITS    6
#define  _7_DATA_BITS    7
#define  _8_DATA_BITS    8
#define  _9_DATA_BITS    9
/*
CPU frequency  Selection
*/
#define   _4_MHZ          4000000U
#define   _8_MHZ		  8000000u
#define   _16_MHZ         16000000u


/*
CPU frequency  Selection
*/

#define Enable_TX			0
#define Enable_RX			1
#define Enable_TX_RX		2




/************************************************************End Of Macros*************************************************************************/

/*******************************************************************************************************************************************************
																Enums
********************************************************************************************************************************************************/
/*Speed*/
typedef enum
{
	UART_NORMAL_SPEED,
	UART_DOUBLE_SPEED
}EN_UART_Speed_Type;
/*********************************************/
/*Parity*/
typedef enum
{
	NO_PARITY,
	EVEN_PARITY,
	ODD_PARITY
}EN_UART_Parity_Type;
/*******************************************/
/*Synchronism*/
typedef enum
{
	ASYNCH,
	SYNCH
}EN_UART_Synchronism_Type;
/*******************************************/
/*Stop Bits*/
typedef enum
{
	ONE_STOP_BIT,
	TWO_STOP_BIT
}EN_UART_StopBit_Type;
/*******************************************/
/*Data Size*/
typedef enum
{
	UART_5_BIT,
	UART_6_BIT,
	UART_7_BIT,
	UART_8_BIT,
	UART_9_BIT
}EN_UART_DataSize_Type;
/******************************************/
/*Stop Bits*/
typedef enum
{
	_4_MHZ,
	_8_MHZ,
	_16_MHZ
}EN_UART_Freq_Type;
/*******************************************/
/*Enable Type*/
typedef enum
{
	UART_TX_ENABLE,
	UART_RX_ENABLE,
	UART_TX_RX_ENABLE
}EN_UART_TX_RX_Enable_Type;
/*******************************************/
/*Disable Type*/
typedef enum
{
	UART_TX_DISABLE,
	UART_RX_DISABLE,
	UART_TX_RX_DISABLE
}EN_UART_TX_RX_Disable_Type;
/*********************************************/
/*INT Enable*/
typedef enum
{
	UART_TX_INT_ENABLE,
	UART_RX_INT_ENABLE
}EN_UART_TX_RX_Int_Enable_Type;
/**********************************************/
/*INT Disable*/
typedef enum
{
	UART_TX_INT_DISABLE,
	UART_RX_INT_DISABLE
}EN_UART_TX_RX_Int_Disable_Type;
/************************************************/
/*BaudRate*/
typedef enum
{
	UART_2400_BAUDRATE ,
	UART_4800_BAUDRATE,
	UART_9600_BAUDRATE,
	UART_14400_BAUDRATE,
	UART_19200_BAUDRATE,
	UART_28800_BAUDRATE,
	UART_38400_BAUDRATE,
	UART_57600_BAUDRATE,
	UART_76800_BAUDRATE,
	UART_115200_BAUDRATE,
	UART_230400_BAUDRATE,
	UART_250000_BAUDRATE
}EN_UART_BaudRate_Type;
/***************************************************/


typedef struct
{
	EN_UART_Speed_Type			    UART_Speed;
	EN_UART_Parity_Type			    UART_Parity;
	EN_UART_Synchronism_Type        UART_Synch;
	EN_UART_StopBit_Type		    UART_StopBits;
	EN_UART_DataSize_Type		    UART_DataSize;
	EN_UART_Freq_Type			    CPU_F;
	EN_UART_TX_RX_Enable_Type	    UART_EnablePins;
	EN_UART_TX_RX_Int_Enable_Type	UART_INT_Enable;
	EN_UART_BaudRate_Type			UART_BaudRate;

}ST_UART_LConfig_Type;

/************************************************************End Of Enums*************************************************************************/


/*******************************************************************************************************************************************************
																ProtoTypes
********************************************************************************************************************************************************/

void USART_init(void);

/************************************************************End Of Prototypes***************************************************************************/

#endif /* UART_H_ */