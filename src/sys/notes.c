#include "devices.h"
#include "init.h"
#include "clock.h"
#include "notes.h"
#include "timer.h"
#include "cm4.h"
#include "devices.h"
#include "init.h"
#include "clock.h"
#include<stdint.h>
#include "potentiometer.h"
#include "stdio.h"
#include <math.h>

/**
 * @brief Function que fait une pause
 * 
 * @param time milisecondes a faire la pause
 */
uint32_t tempo = 60;        // Declaration de la variable global tempo

static const uint32_t notes_arr[] =
{
    /*====== 3e octave ====== */

	1376055,    // DO3
	1298793,    // REb3
	1298793,	// DO#3
    1225822,    // RE3
	1156871,    // RE#3
	1156871,	// MIb3
    1091684,    // MI3
    1030864,    // FA3
    973083,     // FA#3
	973083,		// SOLb3
    918366,     // SOL3
    866621,     // SOL#3
	866621,		// LAb3
    818180,     // LA3
    772259,     // LA#3
	772259,		// SIb3
    728919,     // SI3

    /*====== 4e octave ======*/

	687993,     // DO4
	649397,     // DO#4
	649397,		// REb4
	612952,     // RE4
	578559,     // RE#4
	578559,		// MIb4
	546065,     // MI4
	512418,     // FA4
	486541,     // FA#4
	486541,		// SOLb4
	459182,     // SOL4
	433310,     // SOL#4
	433310,		// LAb4
	409089,     // LA4
	386129,     // LA#4
	386129,		// SIb4
	364460,     // SI4

    /*====== 5e octave ======*/

    343996,     // DO5
    324699,     // DO#5
	324699,		// REb5
    306476,     // RE5
    289280,     // RE#5
	289280,		// MIb5
    273032,     // MI5
    256209,     // FA5
    243270,     // FA#5
	243270,		// SOLb5
    229591,     // SOL5
    216655,     // SOL#5
	216655,		// LAb5
    204545,     // LA5
    193064,     // LA#5
	193064,		// SIb5
    182230,     // SI5

	/*====== 6e octave ======*/
	171998,  	// DO6
	153238      // RE6
};

extern void delay(uint32_t ms)
{
    while (ms--)
    {
        for (volatile uint32_t  t = 0; t < 18000; t++)
        {
        }
    }
    
}

extern void delay_par_duree(rythme RYTHME)
{
    uint32_t duree_noire = 60000/tempo;		// Attention il faut mettre (30 * 1000 ) / tempo
    switch (RYTHME)
    {
    case CARREE:
            delay(8 * duree_noire);
            break;
    case RONDE:
            delay(4 * duree_noire);
            break;
    case BLANCHE:
        delay(2 * duree_noire);
        break;
    case NOIRE_POINTEE:
        delay(1.5 * duree_noire);
        break;
    case NOIRE:
        delay(duree_noire);
        break;
    case CROCHE_POINTEE:
        delay(duree_noire * 0.75);
        break;
    case CROCHE:
        delay(duree_noire / 2);
        break;
    case DOUBLE_CROCHE:
    	delay(duree_noire / 4);
        break;
    case TRIPLE_CROCHE:
        delay(duree_noire / 8);
        break;
    case QUADRUPLE_CROCHE:
        delay(duree_noire / 16);
        break;
    default:
        break;
    }
}

extern void eteindre_son()
{
    // On éteint le son
    TIM2.CCR2 = 0;
    TIM2.EGR |= 1;
}

extern void pause(silence SILENCE)
{
    uint32_t duree_noire = 60000/tempo;		// Attention il faut mettre (30 * 1000 ) / tempo
    switch (SILENCE)
    {
    case BATON_DE_PAUSE:
    	eteindre_son();
        delay(8 * duree_noire);
        break;
    case PAUSE:
    	eteindre_son();
        delay(4 * duree_noire);
        break;
    case DEMI_PAUSE:
    	eteindre_son();
        delay(2 * duree_noire);
        break;
    case SOUPIR:
    	eteindre_son();
        delay(duree_noire);
        break;
    case DEMI_SOUPIR:
    	eteindre_son();
        delay(duree_noire / 2);
        break;
    case QUART_DE_SOUPIR:
    	eteindre_son();
    	delay(duree_noire / 4);
        break;
    case HUITIEME_DE_SOUPIR:
    	eteindre_son();
        delay(duree_noire / 8);
        break;
    case SEIZIEME_DE_SOUPIR:
    	eteindre_son();
        delay(duree_noire / 16);
        break;
    default:
        break;
    }
}

uint32_t volume(uint32_t arr)
{
    // 1 et 4090
    // uint32_t valeur_de_potentiometre = 4095 -  mesure_potentiometre();
	uint32_t diviseur;
    printf("%4ld\r", mesure_potentiometre());
    if (mesure_potentiometre() <= 3000)
    {
    	diviseur = 1000;
    }
    if ((mesure_potentiometre() > 3000) && (mesure_potentiometre() < 3500))
    {
    	diviseur = 1000 - (mesure_potentiometre() - 3000) * (500/3500);
    }
    if ((mesure_potentiometre() > 3500) && (mesure_potentiometre() < 3700))
    {
    	diviseur = 500 - (mesure_potentiometre() - 3500) * (300/200);
    }
    if ((mesure_potentiometre() > 3700) && (mesure_potentiometre() < 3850))
    {
    	diviseur = 200 - (mesure_potentiometre() - 3700) * (100/150);
    }
    if ((mesure_potentiometre() > 3850) && (mesure_potentiometre() < 3950))
    {
    	diviseur = 100 - (mesure_potentiometre() - 3850) * (70/100);
    }
    if ((mesure_potentiometre() > 3950) && (mesure_potentiometre() < 4095))
    {
    	diviseur = 30 - (mesure_potentiometre() - 3950) * (28/145);
    }
    return arr / diviseur;
}

extern void play_note(notes Note, rythme RYTHME)
{
    TIM2.CNT = 0;
    TIM2.ARR = notes_arr[Note];
    TIM2.CCR2 = volume(TIM2.ARR);
    TIM2.EGR |= 1;   // Mise à jour immediate
                     // Les valeurs tampons sont mis dans les vrais variables
                     // TIM2.ARR n'est pas la vrai valeur
    TIM2.CR1 |= 1;  // CEN
    color_leds(RYTHME);
    delay_par_duree(RYTHME);
    eteindre_son();
    leds_off();
    delay(10);
}

extern void led_red_on()
{
	GPIOA.ODR |= (1<<8);
}

extern void led_green_on()
{
	GPIOA.ODR |= (1<<9);
}

extern void led_blue_on()
{
	GPIOA.ODR |= (1<<10);
}

extern void leds_off()
{
	GPIOA.ODR &= ~(7<<8);
}

extern void color_leds(rythme RYTHME)
{
	switch(RYTHME)
	{
	case CARREE:
		led_blue_on();
		break;
	case RONDE:
		led_blue_on();
		break;
	case BLANCHE:
		led_blue_on();
		break;
	case NOIRE_POINTEE:
		led_green_on();
		break;
	case NOIRE:
		led_green_on();
		break;
	case CROCHE_POINTEE:
		led_green_on();
		break;
	case CROCHE:
		led_red_on();
		break;
	case DOUBLE_CROCHE:
		led_red_on();
		break;
	case TRIPLE_CROCHE:
		led_red_on();
		break;
	case QUADRUPLE_CROCHE:
		led_red_on();
		break;
	}
}
