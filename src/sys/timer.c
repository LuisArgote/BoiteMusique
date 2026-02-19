#include"timer.h"
#include"devices.h"
#include "clock.h"
//#include "notes.h"


/**
 * @brief On initialise le timer et le buzzer et on les lient l'un à l'autre
 * 
 */
extern void init_timer_buzzer()
{
	/* ========== Initialisation buzzer PB9 ========== */
	enable_GPIOB(); // On active l'horloge du GPIOB
	
	GPIOB.MODER &= ~(3<<18);  // On met le buzzer en mode alternative
	GPIOB.MODER |= 1<<19;

	GPIOB.AFRH &= ~(0xF<<4);  // On relie la patte 9 avec le timer 2 en selectionnant AF1 sur AFRH (referance manuel v2 page 175-177)
	GPIOB.AFRH |= 1<<4;

	/* ========== Initialisation Timer 2 channel 2 ========== */

	enable_TIM2();   // On active l'horloge 2
    
    TIM2.CCMR1 &= ~(7<<12); // On met a 0 les bits 12-14
    TIM2.CCMR1 |= (6<<12); // 110 pour le mode pwm mode 1
    TIM2.CCMR1 |= (1<<11); // Eviter les erreurs

    TIM2.CCER |= (1<<4); // CC2E = bit 4, nous activons la sortie sur le PB9
    TIM2.CR1 |= (1<<7); // Activation de bit ARPE

    TIM2.CNT = 0;  // On met les valeurs de CNT à 0
	TIM2.PSC = 0;
    TIM2.EGR = 1;   // Mise à joure immediat
}
