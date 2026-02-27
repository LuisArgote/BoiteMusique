#include "musique.h"
#include "notes.h"
#include "timer.h"

extern volatile uint8_t music_changed;

extern volatile uint8_t cnt;

extern void choix_musique()
{
	music_changed = 0; // Reset de la variable lorsque l'on change de musique
    switch(cnt)
    {
        case 1:
            au_clair_de_la_lune();
            break;

        case 2:
            megalovania();
            break;

        case 3:
            die_forelle();
            break;

        case 4:
            lullaby_berceuse_de_brahms();
            break;

        default:
            cnt = 0;
            break;
    }
}

extern void au_clair_de_la_lune()
{
	tempo = 100;

	delay_par_duree(NOIRE); //Léger temps d'attente avant le lancement de la musique

    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(MI4, NOIRE);
    if(music_changed) return;
    play_note(RE4, NOIRE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(MI4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(DO4, BLANCHE);
    if(music_changed) return;
    
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(MI4, NOIRE);
    if(music_changed) return;
    play_note(RE4, NOIRE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(MI4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(DO4, BLANCHE);
    if(music_changed) return;

    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(LA3, NOIRE);
    if(music_changed) return;
    play_note(LA3, NOIRE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(SI3, CROCHE);
    if(music_changed) return;
    play_note(LA3, CROCHE);
    if(music_changed) return;
    play_note(SOL3, BLANCHE);
    if(music_changed) return;

    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(MI4, NOIRE);
    if(music_changed) return;
    play_note(RE4, NOIRE);
    if(music_changed) return;
    play_note(DO4, CROCHE);
    if(music_changed) return;
    play_note(MI4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(DO4, BLANCHE);
    if(music_changed) return;
}


extern void megalovania()
{
    tempo = 135;

    delay_par_duree(NOIRE); //Léger temps d'attente avant le lancement de la musique

    // Mesure 1
    pause(DEMI_SOUPIR);
    play_note(RE5, CROCHE);
    if(music_changed) return;
    play_note(LA4, CROCHE_POINTEE);
    if(music_changed) return;
    play_note(LAb4, DOUBLE_CROCHE);
    if(music_changed) return;
    pause(DEMI_SOUPIR);
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;

    // Mesure 2
    pause(DEMI_SOUPIR);
    play_note(RE5, CROCHE);
    if(music_changed) return;
    play_note(LA4, CROCHE_POINTEE);
    if(music_changed) return;
    play_note(LAb4, DOUBLE_CROCHE);
    if(music_changed) return;
    pause(QUART_DE_SOUPIR);
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;

    // Mesure 3
    pause(DEMI_SOUPIR);
    play_note(RE5, CROCHE);
    if(music_changed) return;
    play_note(LA4, CROCHE_POINTEE);
    if(music_changed) return;
    play_note(LAb4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    pause(QUART_DE_SOUPIR);
    if(music_changed) return;
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;

    // Mesure 9
    play_note(FA5, NOIRE);
    if(music_changed) return;
    play_note(FA5, CROCHE);
    if(music_changed) return;
    play_note(FA5, CROCHE);
    if(music_changed) return;
    play_note(FA5, CROCHE);
    if(music_changed) return;
    play_note(RE5, CROCHE);
    if(music_changed) return;
    play_note(RE5, NOIRE);
    if(music_changed) return;

    // Mesure 10
    play_note(FA5, NOIRE);
    if(music_changed) return;
    play_note(FA5, CROCHE);
    if(music_changed) return;
    play_note(SOL5, CROCHE);
    if(music_changed) return;
    play_note(LAb5, CROCHE);
    if(music_changed) return;
    play_note(SOL5, CROCHE);
    if(music_changed) return;
    play_note(FA5, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL5, CROCHE_POINTEE);
    if(music_changed) return;

    // Mesure 11
    play_note(FA5, NOIRE);
    if(music_changed) return;
    play_note(FA5, CROCHE);
    if(music_changed) return;
    play_note(SOL5, CROCHE);
    if(music_changed) return;
    play_note(SOLd5, CROCHE);
    if(music_changed) return;
    play_note(LA5, CROCHE);
    if(music_changed) return;
    play_note(DO6, CROCHE);
    if(music_changed) return;
    play_note(LA5, CROCHE);
    if(music_changed) return;

    // Mesure 12
    play_note(RE6, CROCHE);
    if(music_changed) return;
    play_note(RE6, CROCHE);
    if(music_changed) return;
    play_note(RE6, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(LA5, CROCHE_POINTEE);
    if(music_changed) return;
    play_note(DO6, BLANCHE);
    if(music_changed) return;

    // Mesure 13
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(SOL4, NOIRE);
    if(music_changed) return;

    // Mesure 14
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(LA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(RE5, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(RE5, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(LA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, CROCHE);
    if(music_changed) return;

    // Mesure 15
    play_note(RE5, CROCHE);
    if(music_changed) return;
    play_note(LA4, CROCHE);
    if(music_changed) return;
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(DO5, CROCHE);
    if(music_changed) return;
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(MI4, CROCHE);
    if(music_changed) return;

    // Mesure 16
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(RE4, CROCHE);
    if(music_changed) return;
    play_note(MI4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE_POINTEE);
    if(music_changed) return;
    play_note(DO5, BLANCHE);

    // Mesure 17
    pause(DEMI_PAUSE);
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(RE4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(LAb4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(RE4, DOUBLE_CROCHE);
    if(music_changed) return;

    // Mesure 18
    play_note(LAb4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(SOL4, BLANCHE);
    if(music_changed) return;
    play_note(SOLd4, CROCHE);
    if(music_changed) return;
    play_note(LA4, CROCHE);
    if(music_changed) return;

    // Mesure 19
    play_note(LAb4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(SOL4, BLANCHE);
    if(music_changed) return;
    play_note(SOLd4, CROCHE);
    if(music_changed) return;
    play_note(LA4, CROCHE);
    if(music_changed) return;

    // Mesure 20
    play_note(DO5, CROCHE);
    if(music_changed) return;
    play_note(LA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(LAb4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(SOL4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(RE4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(MI4, DOUBLE_CROCHE);
    if(music_changed) return;
    play_note(FA4, CROCHE);
    if(music_changed) return;
    play_note(SOL4, CROCHE);
    if(music_changed) return;
    play_note(LA4, CROCHE);
    if(music_changed) return;
    play_note(DO5, CROCHE);
    if(music_changed) return;
}


extern void die_forelle()
{
    tempo = 140;

    delay_par_duree(NOIRE); //Léger temps d'attente avant le lancement de la musique

	// Ligne 1
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;

	play_note(DO4, NOIRE);
	if(music_changed) return;
	play_note(SOL4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, CROCHE);
	if(music_changed) return;

	play_note(SOL3, CROCHE);
	if(music_changed) return;
	play_note(SOL3, CROCHE);
	if(music_changed) return;
	play_note(RE4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(SI3, CROCHE);
	if(music_changed) return;
	play_note(LA3, CROCHE);
	if(music_changed) return;

	play_note(SOL4, NOIRE);
	if(music_changed) return;
	eteindre_son();
	delay_par_duree(CROCHE);
	play_note(SOL4, CROCHE);
	if(music_changed) return;

	// Ligne 2
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;

	play_note(DO4, NOIRE);
	if(music_changed) return;
	play_note(SOL4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;

	play_note(SI4, CROCHE);
	if(music_changed) return;
	play_note(LA4, CROCHE);
	if(music_changed) return;
	play_note(SI4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(FA4, CROCHE);
	if(music_changed) return;
	play_note(FA4, CROCHE);
	if(music_changed) return;

	play_note(SOL4, NOIRE);
	if(music_changed) return;
	eteindre_son();
	delay_par_duree( CROCHE);
	play_note(SOL4, CROCHE);
	if(music_changed) return;
}

extern void lullaby_berceuse_de_brahms()
{
	tempo = 150;

	delay_par_duree(NOIRE); //Léger temps d'attente avant le lancement de la musique

	// LIGNE 1
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, NOIRE_POINTEE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, BLANCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, CROCHE);
	if(music_changed) return;
	play_note(DO5, NOIRE);
	if(music_changed) return;
	play_note(SI4, NOIRE);
	if(music_changed) return;
	play_note(LA4, NOIRE);
	if(music_changed) return;
	play_note(LA4, NOIRE);
	if(music_changed) return;
	play_note(SOL4, NOIRE);
	if(music_changed) return;

	play_note(RE4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;

	// LIGNE 2
	play_note(FA4, NOIRE);
	if(music_changed) return;
	play_note(RE4, NOIRE);
	if(music_changed) return;
	play_note(RE4, CROCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(FA4, BLANCHE);
	if(music_changed) return;
	play_note(RE4, CROCHE);
	if(music_changed) return;
	play_note(FA4, CROCHE);
	if(music_changed) return;
	play_note(SI4, CROCHE);
	if(music_changed) return;
	play_note(LA4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, NOIRE);
	if(music_changed) return;
	play_note(SI4, NOIRE);
	if(music_changed) return;
	play_note(DO5, BLANCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;

	// LIGNE 3
	play_note(DO5, BLANCHE);
	if(music_changed) return;
	play_note(LA4, CROCHE);
	if(music_changed) return;
	play_note(FA4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, BLANCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(FA4, NOIRE);
	if(music_changed) return;
	play_note(SOL4, NOIRE);
	if(music_changed) return;
	play_note(LA4, NOIRE);
	if(music_changed) return;
	play_note(SOL4, BLANCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;

	// LIGNE 4
	play_note(DO5, BLANCHE);
	if(music_changed) return;
	play_note(LA4, CROCHE);
	if(music_changed) return;
	play_note(FA4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, BLANCHE);
	if(music_changed) return;
	play_note(MI4, CROCHE);
	if(music_changed) return;
	play_note(DO4, CROCHE);
	if(music_changed) return;
	play_note(FA4, CROCHE);
	if(music_changed) return;
	play_note(SOL4, DOUBLE_CROCHE);
	if(music_changed) return;
	play_note(FA4, DOUBLE_CROCHE);
	if(music_changed) return;
	play_note(MI4, NOIRE);
	if(music_changed) return;
	play_note(RE4, NOIRE);
	if(music_changed) return;
	play_note(DO4, BLANCHE);
	if(music_changed) return;
}
