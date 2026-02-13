#include"buzzer.h"
#include "devices.h"
#include "timer.h"
#include "notes.h"

extern void enable_buzzer()
{
    enable_GPIOB();
    // On met le buzzer en mode alternative
    GPIOB.MODER &= ~(3<<18);
    GPIOB.MODER |= 1<<19;
    

    // On relie la patte 9 avec le timer 2
    // On selectionnant AF1 sur AFRH
    // Voir referance manuel v2 page 175-177
    GPIOB.AFRH &= ~(0xF<<4);
    GPIOB.AFRH |= 1<<4;
    
    
}

