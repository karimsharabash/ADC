/*
 * my_ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ascom
 */
#include<avr/io.h>

void ADC_Init()
{

	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);						 // 1- Enable ADC 2- Define Prescaler 128

}
unsigned int ADC_Read(unsigned char channel,float Vref )
{

	ADMUX=channel;		        // 3- select ADC channel
	if(Vref==2.56f)              // 4- Select vref
	{
		ADMUX|=(1<<REFS0)|(1<<REFS1);       // AVCC=2.56v
	}
	else{
		ADMUX|=(1<<REFS0);        // AVCC=5VA  (default if u didn't choose 2.56 v)
	}

	ADCSRA|=(1<<ADSC);          // 5- Start conversion for ADC
	while(!(ADCSRA&(1<<ADIF))); // 6- Wait till conversion complete
	ADCSRA|=(1<<ADIF);			// 7- Clear ADIF
	return ADC;					// 8- return ADC

}

