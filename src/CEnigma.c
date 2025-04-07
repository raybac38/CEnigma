#include "CEnigma.h"

#include <stdlib.h>

char * rotorA = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char * rotorB = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char * rotorC = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
char * rotorD = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
char * rotorE = "VZBRGITYUPSDNHLXAWMJQOFECK";

char * premierOffset;
char * secondOffset;
char * troisiemeOffset;

int premierPosition; 
int secondPosition;
int troisiemePosition;

void createOffsetTable(char ** offsetsPtr, char ** rotorData)
{
    *offsetsPtr = malloc(sizeof(char) * 26);
    for(int i = 0; i < 26; i++)
    {
        char offset =  ((*rotorData)[i] - 'A' - i + 26) % 26;
        (*offsetsPtr)[i] = offset;
    }
}

char * getRotorData(Rotor rotor)
{
    switch (rotor)
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

int setRotorConfig(Rotor premier, int positionPremier, Rotor second, int positionSecond, Rotor troisieme, int positionTroisieme)
{
    if(premier == second || second == troisieme || troisieme == premier)
    {
        return -1;
    }

    createOffsetTable(&premierOffset, &premier);
    createOffsetTable(&secondOffset, &second);
    createOffsetTable(&troisiemeOffset, &troisieme);
}

int setPlugboardPair(char a, char b)
{
    return 0;
}



char code(char c)
{
    c = (c + troisiemeOffset[(c + troisiemePosition) % 26]) % 26;
    c = (c + secondOffset[(c + secondPosition) % 26]) % 26;
    c = (c + premierOffset[(c + premierPosition) % 26]) % 26;
    
    /*
        Insertion du reflecteur
    */

    c = (c - premierOffset[(c + premierPosition) % 26]) % 26;
    c = (c - secondOffset[(c + secondPosition) % 26]) % 26;
    c = (c - troisiemeOffset[(c + troisiemePosition) % 26]) % 26;

    premierPosition++;
    secondPosition++;
    troisiemePosition++;

    return c;
}
