#ifndef TIMER_H
#define TIMER_H


/**
 * @brief Fonction pour activer le TIMER qu'est dans la patte PB9
 * 
 */

void init_led_tricolore();

void init_timer_buzzer();

void init_button();

void select_PC13_as_EXTI13();

void setup_IRQ_on_EXTI13_events();

void enable_EXTI15_10_IRQ();

void init_IRQ_PC13();

void EXTI15_10_Handler();

#endif
