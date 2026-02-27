#ifndef NOTES_H
#define NOTES_H
#include <stdint.h>



typedef enum{

/*====== 3e octave ======*/

	DO3,
	DOd3,
    REb3,
	RE3,
	REd3,
	MIb3,
    MI3,
    FA3,
	FAd3,
    SOLb3,
	SOL3,
	SOLd3,
	LAb3,
    LA3,
	LAd3,
	SIb3,
    SI3,

/* ===== 4e octave =======*/

    DO4,
	DOd4,
    REb4,
	RE4,
	REd4,
	MIb4,
    MI4,
    FA4,
	FAd4,
    SOLb4,
	SOL4,
	SOLd4,
	LAb4,
    LA4,
	LAd4,
	SIb4,
    SI4,

/* ====== 5e octave ======*/

	DO5,
	DOd5,
    REb5,
	RE5,
	REd5,
	MIb5,
    MI5,
    FA5,
	FAd5,
    SOLb5,
	SOL5,
	SOLd5,
	LAb5,
    LA5,
	LAd5,
	SIb5,
    SI5,

	/* ====== 6e octave ======*/
	DO6,
	RE6
}notes;


typedef enum{
	CARREE,
	RONDE,
	BLANCHE,
	NOIRE_POINTEE,
	NOIRE,
	CROCHE_POINTEE,
	CROCHE,
	DOUBLE_CROCHE,
	TRIPLE_CROCHE,
	QUADRUPLE_CROCHE
}rythme;

typedef enum{
	BATON_DE_PAUSE,
	PAUSE,
	DEMI_PAUSE,
	SOUPIR,
	DEMI_SOUPIR,
	QUART_DE_SOUPIR,
	HUITIEME_DE_SOUPIR,
	SEIZIEME_DE_SOUPIR
}silence;
//uint32_t cpt = 2666666;

extern uint32_t tempo;  // On definit tempo comme une variable global

extern uint8_t volume_percent;

void pause(silence SILENCE);

void eteindre_son();

/**
 * @brief Function que fait une pause
 * 
 * @param time milisecondes a faire la pause
 */
void delay(uint32_t time);

/**
 * @brief Associe une durée à un type de note (noire, croche, blanche)
 * 
 * @param Duree 
 */
void delay_par_duree(rythme RYHTME);

/**
 * @brief On met la frequence de la note choisi dans le TIMER
 * 
 * @param Note Note à mettre
 */
void play_note(notes Note, rythme RYTHME);

void led_red_on();

void led_green_on();

void led_blue_on();

void leds_off();

void color_leds(rythme RYTHME);

uint32_t compute_ccr(uint32_t volume);

#endif
