#include "musique.h"
#include "notes.h"


extern void au_clair_de_la_lune()
{
	tempo = 100;

    play_note(DO4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(MI4, NOIRE);
    play_note(RE4, NOIRE);
    play_note(DO4, CROCHE);
    play_note(MI4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(DO4, BLANCHE);
    
    play_note(DO4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(MI4, NOIRE);
    play_note(RE4, NOIRE);
    play_note(DO4, CROCHE);
    play_note(MI4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(DO4, BLANCHE);

    play_note(RE4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(LA3, NOIRE);
    play_note(LA3, NOIRE);
    play_note(RE4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(SI3, CROCHE);
    play_note(LA3, CROCHE);
    play_note(SOL3, BLANCHE);

    play_note(DO4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(MI4, NOIRE);
    play_note(RE4, NOIRE);
    play_note(DO4, CROCHE);
    play_note(MI4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(DO4, BLANCHE);
}


extern void megalovania()
{
    tempo = 132;

    // ===== RIFF PRINCIPAL =====
    play_note(RE4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(RE5, CROCHE);
    play_note(LA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(FA4, CROCHE);

    play_note(SOL4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(RE5, CROCHE);
    play_note(LA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(RE4, CROCHE);

    // ===== VARIATION =====
    play_note(LA3, CROCHE);
    play_note(LA3, CROCHE);
    play_note(RE4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(LA4, CROCHE);
    play_note(DO5, CROCHE);
    play_note(LA4, CROCHE);

    play_note(SOL4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(RE4, CROCHE);
    play_note(DO4, CROCHE);
    play_note(LA3, CROCHE);

    // ===== PARTIE PLUS INTENSE =====
    play_note(RE5, CROCHE);
    play_note(DO5, CROCHE);
    play_note(LA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(LA4, CROCHE);
    play_note(DO5, CROCHE);

    play_note(RE5, CROCHE);
    play_note(RE5, CROCHE);
    play_note(RE5, CROCHE);
    play_note(DO5, CROCHE);
    play_note(LA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(RE4, BLANCHE);

    // ===== OUTRO (bouclable) =====
    play_note(RE4, CROCHE);
    play_note(FA4, CROCHE);
    play_note(SOL4, CROCHE);
    play_note(LA4, CROCHE);
    play_note(RE5, NOIRE);
    play_note(LA4, NOIRE);
    play_note(SOL4, BLANCHE);
}


extern void die_forelle()
{
    tempo = 140;  // tempo de la mélodie (adaptable)

// Ligne 1
play_note(DO4, CROCHE);   
play_note(DO4, CROCHE);   
play_note(MI4, CROCHE);   
play_note(MI4, CROCHE);   

play_note(DO4, NOIRE);   
play_note(SOL4, CROCHE);  
play_note(SOL4, CROCHE);  

play_note(SOL3, CROCHE);  
play_note(SOL3, CROCHE);  
play_note(RE4, CROCHE);  
play_note(DO4, CROCHE);  
play_note(SI3, CROCHE);  
play_note(LA3, CROCHE);  

play_note(SOL4, NOIRE);  
eteindre_son();
delay_par_duree( CROCHE);  
play_note(SOL4, CROCHE);

// Ligne 2
play_note(DO4, CROCHE);  
play_note(DO4, CROCHE);  
play_note(MI4, CROCHE);  
play_note(MI4, CROCHE);  

play_note(DO4, NOIRE);  
play_note(SOL4, CROCHE);  
play_note(DO4, CROCHE);  

play_note(SI4, CROCHE);  
play_note(LA4, CROCHE);  
play_note(SI4, CROCHE);  
play_note(DO4, CROCHE);  
play_note(FA4, CROCHE);  
play_note(FA4, CROCHE);  

play_note(SOL4, NOIRE);  
eteindre_son();
delay_par_duree( CROCHE);  
play_note(SOL4, CROCHE);


}
