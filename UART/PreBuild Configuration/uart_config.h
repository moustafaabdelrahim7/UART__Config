


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*	options For Speed:-
	1)normal_speed		
	2)double_speed
	3)total_speed
*/

#define Speed_Modes_Selection			  normal_speed
/***************************************************************/
/*	options For Parity:-
	1)NO_PARITY		
	2)EVEN_PARITY
	3)ODD_PARITY
*/
	
#define Parity_Selection				  NO_PARITY   
/******************************************************************/

/*	options For Synchronism:-
	1)ASYNCH		
	2)SYNCH
*/
	
#define Type_Of_Synchronism				  ASYNCH 
/**********************************************************************/
/*	options For Stop Bits:-
	1)ONE_STOP_BIT		
	2)TWO_STOP_BIT
*/	
#define Stop_Bits_Selection				  ONE_STOP_BIT   
/***********************************************************************/
/*	options For Data Size:-
	1)_5_DATA_BITS		
	2)_6_DATA_BITS
	3)_7_DATA_BITS
	3)_8_DATA_BITS
	3)_9_DATA_BITS
*/	

#define  data_Size_Selection			 _8_DATA_BITS    
/**************************************************************************/

/*	options For CPU_Freq:-
	1)_4_MHZ		
	2)_8_MHZ
	3)_16_MHZ
*/
#define CPU_frequency_Selection			 _8_MHZ 
/*****************************************************************************/
/*	options For Data Size:-
			it's in the hand of the Developer 
*/

#define baud_rate_Selection				 51 
/******************************************************************************/
/*	options For CPU_Freq:-
	1)Enable_TX_RX		
	2)Enable_TX
	3)Enable_RX
*/
#define Enable_Selection				Enable_TX_RX  
/*******************************************************************************/

#endif 
 


