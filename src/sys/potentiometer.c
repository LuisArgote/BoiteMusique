#include"timer.h"
#include"devices.h"
#include "clock.h"
#include "notes.h"
#include "adc.h"


extern void configuration_potentiometre(){
	enable_GPIOB();
	GPIOB.MODER |= (0x3);

	enable_ADC1();

	ADC1.CR2 |= 1;
	ADC_set_prediv(1);

	ADC1.SQR1 &= ~(0xF<<20);
	ADC1.SMPR2 = 7<<24;
	ADC1.SQR3 = 8;

}

extern uint32_t mesure_potentiometre(){
	uint32_t val;
	ADC_convert_sequence(&ADC1, &val);
	return (val);
}
