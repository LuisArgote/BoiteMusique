#include "devices.h"
#include "init.h"
#include "clock.h"
#include "buzzer.h"
#include "notes.h"
#include "time.h"


/**
 * @brief Changer la valeur de psc
 *
 * @param psc
 */
void set_psc(uint32_t psc)
{
    TIM2.PSC = psc;
}

extern void set_note(notes Note)
{
    switch (Note)
    {
        case DO:
            
            break;
        case LA:
            set_psc(89);
            TIM2.CNT=0;
            TIM2.ARR = 4540;
            TIM2.CCR2 = TIM2.ARR / 2;
            TIM2.EGR |= 1;   // Mise à joure immediat
            				 // Les valeurs tampons sont mis dans les vrais variables
            				 // TIM2.ARR n'est pas la vrai valeur
            TIM2.CR1 |= 1; // CEN

            break;
        default:
            break;
    }


}


