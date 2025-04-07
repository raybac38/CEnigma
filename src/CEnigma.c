#include "CEnigma.h"

#include <stdlib.h>



char * premierOffset;
char * secondOffset;
char * troisiemeOffset;

int premierPosition; 
int secondPosition;
int troisiemePosition;

void createOffsetTable(char ** offsetTable, char ** rotorData) 
{
    *offsetTable = malloc(sizeof(char) * 26);
    for(int i = 0; i < 26; i++)
    {
        char offset =  ((*rotorData)[i] - 'A' - i + 26) % 26;
        (*offsetTable)[i] = offset;
    }
}



int setRotorConfig(RotorIdentifier premier, int positionPremier, RotorIdentifier second, int positionSecond, RotorIdentifier troisieme, int positionTroisieme)
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
    c = c - 'A';

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

    return c + 'A';
}
