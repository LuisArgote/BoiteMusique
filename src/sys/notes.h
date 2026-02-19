#ifndef NOTES_H
#define NOTES_H
#include <stdint.h>



typedef enum{
/*====== 3 octave ======*/
	DO3,
	RE3,
	MI3,
	FA3,
	SOL3,
	LA3,
	SI3,

/* ===== 4 octave =======*/
    DO4,
    RE4,
    MI4,
    FA4,
    SOL4,
    LA4,
    SI4
}notes;


typedef enum{
    CROCHE,
    NOIRE,
    BLANCHE 
}duree;
//uint32_t cpt = 2666666;

extern uint32_t tempo;  // On definit tempo comme une variable global

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
void delay_par_duree(duree Duree);

/**
 * @brief On met la frequence de la note choisi dans le TIMER
 * 
 * @param Note Note à mettre
 */
void play_note(notes Note, duree Duree);

#endif
