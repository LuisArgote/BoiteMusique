#include "devices.h"
#include "init.h"
#include "clock.h"
#include "notes.h"
#include "time.h"
#include "cm4.h"
#include "devices.h"
#include "init.h"
#include "clock.h"
#include<stdint.h>

/**
 * @brief Function que fait une pause
 * 
 * @param time milisecondes a faire la pause
 */
/* extern void delay(uint32_t time)
{
    for (int i = 0; i < time; i++)
    {
        while (cpt >0)
        {
            cpt--;
        }
        cpt = 2666666;
    }
    
} */

uint32_t tempo = 60;        // Declaration de la variable global tempo

static const uint32_t notes_arr[] =
{
    /*====== 3 octave ===== */
    1376055,    // DO3
    1225822,    // RE3
    1091684,    // MI3
    1030864,    // FA3
    918366,     // SOL3
    818180,     // LA3
    728919,     // SI3

    /*===== 4 octave ======*/
    687993,     // DO4
    612952,     // RE4
    546065,     // MI4
    512418,     // FA4
    459182,     // SOL4
    409089,     // LA4
    364460     // SI4
};

extern void delay(uint32_t ms)
{
    volatile uint32_t cpt;
    while (ms--)
    {
        for (volatile uint32_t  t = 0; t < 18000; t++)
        {
            cpt = 0;
        }
    }
    
}

extern void delay_par_duree(duree Duree)
{
    // Erreur faut mettre (30 * 1000 ) / tempo
    switch (Duree)
    {
    case CROCHE:

        delay(30000 / tempo);
        break;
    case NOIRE:
        delay(60000 / tempo);
        break;
    case BLANCHE:
        delay(120000 / tempo);
        break;
    default:
        break;
    }
}

void eteindre_son()
{
    // On éteint le son
    TIM2.CCR2 = 0;
    TIM2.EGR |= 1;
}

extern void play_note(notes Note, duree Duree)
{
    TIM2.CNT = 0;
    TIM2.ARR = notes_arr[Note];
    TIM2.CCR2 = TIM2.ARR / 2;
    TIM2.EGR |= 1;   // Mise à jour immediat
                     // Les valeurs tampons sont mis dans les vrais variables
                     // TIM2.ARR n'est pas la vrai valeur
    TIM2.CR1 |= 1;  // CEN
    delay_par_duree(Duree);
    eteindre_son();
    delay(10);
    
}


