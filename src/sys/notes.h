#ifndef NOTES_H
#define NOTES_H

typedef enum{
    DO,
    RE,
    MI,
    FA,
    SOL,
    LA,
    SI
}notes;



/**
 * @brief On met la frequence de la note choisi dans le TIMER
 * 
 * @param Note Note à mettre
 */
void set_note(notes Note);

#endif