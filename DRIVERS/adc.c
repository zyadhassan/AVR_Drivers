/*
 * adc.c
 *
 *  Created on: Oct 4, 2022
 *      Author: User
 */


#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>



void ADC_init(void){
	ADMUX=(1<<REFS0);
	ADCSRA=(1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

}





uint16 ADC_readChannel(uint8 channel){
	ADMUX=(ADMUX&0XE0) | (channel & 0x1F);
	ADCSRA |= (1<<ADSC);
	while(BIT_IS_CLEAR(ADCSRA,4));
	ADCSRA |= (1<<ADIF);
	return ADC;
}

