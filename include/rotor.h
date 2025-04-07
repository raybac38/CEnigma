#include "CEnigma.h"

typedef struct
{
    int notche;
    char * offsetTable;
}Rotor;

Rotor * initRotor(RotorIdentifier identifiant);

void destroyRoror(Rotor ** rotor);

