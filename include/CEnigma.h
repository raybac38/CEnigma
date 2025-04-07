#ifndef CENIGMA_H
#define CENIGMA_H

typedef enum 
{
    A, B, C, D, E
}RotorIdentifier; 

/*
    Permet de set la machine Enigma
    @param premier rotor gauche
    @param position position du rotor gauche (0-25)
    @param second rotor central
    @param positionSecond position du rotor central (0-25)
    @param troiseme rotor de droite
    @param positionTroiseme position du rotor droit (0-25)
    @return 0 if succes, -1 if error  
*/
int setRotorConfig(RotorIdentifier premier, int positionPremier, RotorIdentifier second, int positionSecond, RotorIdentifier troiseme, int positionTroiseme);

/*
    Permet de set un couple a échanger sur la plugboard
    @param a première lettre
    @param b deuxième lettre
    @return 0 if succes, -1 if error
*/
int setPlugboardPair(char a, char b);

/*
    Permet de passé un char dans Enigma
    @param c lettre a coder
    @return lettre codé
*/
char code(char c);

#endif


