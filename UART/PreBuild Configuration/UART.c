
#include "uart.h"

void USART_init(void)
{
	uint8_t Calc;
	/*Baud Rate With Speed*/
	#if Speed_Modes_Selection==normal_speed
	CLEAR_BIT(UCSRA,U2X);
	Calc=((CPU_frequency_Selection / (16*baud_rate_Selection)) - 1);
	UBRRL=(uint8_t)Calc;
	UBRRH = (uint8_t)(Calc>>8);
	
	#elif Speed_Modes_Selection==double_speed
	Set_Bit(UCSRA,U2X);
	Calc=((CPU_frequency_Selection / (8*baud_rate_Selection)) - 1);
	UBRRL=(uint8_t)Calc;
	UBRRH = (uint8_t)(Calc>>8);
#endif
/*************************************************************************/
	/*Synch*/
	#if	Type_Of_Synchronism==ASYNCH
	CLEAR_BIT(UCSRC,UMSEL);
	
	#elif Type_Of_Synchronism==ASYNCH
	Set_Bit(UCSRC,UMSEL);
#endif
/*************************************************************************/
	/*Parity*/
	#if Parity_Selection==NO_PARITY
	CLEAR_BIT(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);
	
	#elif Parity_Selection==ODD_PARITY
	Set_Bit(UCSRC,UPM0);
	Set_Bit(UCSRC,UPM1);
	
	#elif Parity_Selection==EVEN_PARITY
	CLEAR_BIT(UCSRC,UPM0);
	Set_Bit(UCSRC,UPM1);
	
	#else
	Set_Bit(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);		
	
#endif
/*************************************************************************/
	/*Data Length*/
	#if data_Size_Selection==_5_DATA_BITS
	CLEAR_BIT(UCSRB,UCSZ0);
	CLEAR_BIT(UCSRB,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);
	
	#elif data_Size_Selection==_6_DATA_BITS
	Set_Bit(UCSRB,UCSZ0);
	CLEAR_BIT(UCSRB,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);

	#if data_Size_Selection==_7_DATA_BITS
	CLEAR_BIT(UCSRB,UCSZ0);
	Set_Bit(UCSRB,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);
	
	#if data_Size_Selection==_8_DATA_BITS
	Set_Bit(UCSRB,UCSZ0);
	Set_Bit(UCSRB,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);
	
	#if data_Size_Selection==_9_DATA_BITS
	Set_Bit(UCSRB,UCSZ0);
	Set_Bit(UCSRB,UCSZ1);
	Set_Bit(UCSRB,UCSZ2);
	
#endif
/*************************************************************************/
	/*Stop Bit*/
	#if Stop_Bits_Selection==ONE_STOP_BIT
	CLEAR_BIT(UCSRB,RUSBS);
	
	#elif Stop_Bits_Selection==TWO_STOP_BIT
	Set_Bit(UCSRB,RUSBS);
	
	/*Enabling Type*/
	#if Enable_Selection==Enable_TX
	Set_Bit(UCSRC,TXEN);
	
	#if Enable_Selection==Enable_RX
	Set_Bit(UCSRC,RXEN);
	
	#if Enable_Selection==Enable_TX_RX
	Set_Bit(UCSRC,TXEN);
	Set_Bit(UCSRC,RXEN);
#endif
/*************************************************************************/

}

