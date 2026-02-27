#include"timer.h"
#include"devices.h"
#include "clock.h"
#include "notes.h"

volatile uint8_t cnt = 0;

volatile uint8_t music_changed = 0;

/**
 * @brief On initialise le timer et le buzzer et on les lient l'un à l'autre
 * 
 */

extern void init_led_tricolore()
{
	  enable_GPIOA();
	  GPIOA.MODER &= ~(0x3F<<16);
	  GPIOA.MODER |= (0x15<<16);
}

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

extern void init_button()
{
	enable_GPIOC(); // Activer l'horloge GPIOC

	GPIOC.PUPDR &= ~(3<<26);
	GPIOC.MODER &= ~(3<<26); // Bouton poussoir PC13 en entrée
}

extern void select_PC13_as_EXTI13()
{
	enable_SYSCFG(); // Activer l'horloge SYSCFG

	SYSCFG.EXTICR4 &= ~(0xF<<4); // Clear
	SYSCFG.EXTICR4 |= (2<<4); // 0010 car port C
}

extern void setup_IRQ_on_EXTI13_events() // Configuration pour front descendant (appui sur le bouton)
{
	EXTI.IMR  |= (1 << 13);    // Active les interruptions sur la ligne 13
    EXTI.FTSR |= (1 << 13);    // Active l'interruption pour les fronts descendants
    EXTI.RTSR &= ~(1 << 13);   // Désactive l'interruption pour les fronts montants
}

extern void enable_EXTI15_10_IRQ()
{
	NVIC.ISER[1] |= (1<<8);
}

extern void init_IRQ_PC13()
{
	init_button();
	select_PC13_as_EXTI13();
	setup_IRQ_on_EXTI13_events();
	enable_EXTI15_10_IRQ();
}

extern void EXTI15_10_Handler()
{
    if(EXTI.PR & (1 << 13))   // Vérifier si c'est bien la ligne 13 qui s'est déclenchée
    {
        EXTI.PR |= (1 << 13); // Système Write 1 to clear
        cnt++;
        if(cnt > 4)
        {
        	cnt = 0;
        }
        music_changed = 1;
    }
}
