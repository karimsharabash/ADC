/*
 * my_ADC.c
 *
 *  Created on: 15/2/2018
 *     Author: karim sharabash
 */
#include<avr/io.h>

void ADC_Init()
{
	ADMUX=(1<<REFS0);                                             // choose the Vref
	ADCSRA=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS2);	         	  //  Enable ADC ana set Prescaler /64

}
unsigned int ADC_Read(unsigned char channel)
{
        ADMUX &=0xE0;                                                 //   remove the recent channel
	channel &=0x07;                                              //   enter the new channel and mask it with  only 3 bits
	ADMUX |=channel;                                             //   select ADC channel
	ADCSRA|=(1<<ADSC);                                           //  Start conversion for ADC
	while(!(ADCSRA&(1<<ADIF)));                                  //  Wait till conversion complete
	ADCSRA|=(1<<ADIF);		                            //  Clear ADIF
//	while(ADCSRA & (1<<ADSC));                                   //  Wait till conversion complete
	return ADC;				                     //  return digital equivalent to the anaglog reading

}

