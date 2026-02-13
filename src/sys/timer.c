#include"timer.h"
#include"devices.h"
#include "clock.h"
#include "buzzer.h"
#include "notes.h"

extern void init_timer()
{
	enable_TIM2();   // On active l'horloge 2
    
    TIM2.CCMR1 &= ~(7<<12); // On met a 0 les bits 12-14
    TIM2.CCMR1 |= (6<<12); // 110 pour le mode pwm mode 1
    TIM2.CCMR1 |= (1<<11); // Eviter les erreurs

    enable_buzzer(); // On active le Buzzer et on le relie a la 

    TIM2.CCER |= (1<<4); // CC2E = bit 4, nous activons la sortie sur le PB9
    TIM2.CR1 |= (1<<7); // Activation de bit ARPE

    TIM2.CNT = 0;  // On met les valeurs de CNT à 0
    TIM2.EGR = 1;   // Mise à joure immediat
    set_note(LA);
}
