#include "rotor.h"
#include "CEnigma.h"

#include <stdlib.h>

char * rotorA = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char * rotorB = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char * rotorC = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
char * rotorD = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
char * rotorE = "VZBRGITYUPSDNHLXAWMJQOFECK";

char * getRotorData(RotorIdentifier identifiant)
{
    switch (identifiant)
    {
    case A:
        return rotorA;
    case B:
        return rotorB;
    case C:
        return rotorC;
    case D:
        return rotorD;
    case E:
        return rotorE;
    default:
        break;
    }
}

Rotor * initRotor(RotorIdentifier identifiant)
{
    char * data = getRotorData(identifiant);
    Rotor * rotor = malloc(sizeof(Rotor));
    
    for(int i = 0; i < 26; i++)
    {   
        char offset =  (data[i] - 'A' - i + 26) % 26;
        rotor->offsetTable[i] = offset;
    }

    return rotor;
}

void destroyRoror(Rotor ** rotor)
{
    
}