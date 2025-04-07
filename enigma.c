#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  int notche;
  int alph[26];
} t_rotor;

typedef int t_reflector[26];

typedef struct {
  int swap1[10];
  int swap2[10];
} t_plug;


t_rotor * init_rotor(int n, char * t);
t_reflector * init_reflector(char * t);
t_plug * init_plug_connection(char * t);

int recherche(int n, int * swap);
int map(int n, t_plug * plug);

int perm_rot(int n,t_rotor * rotor, int position);

int perm_ref(int n,t_reflector * reflector);


int main(){
  // SETTINGS
  int whell_order[3] = {2,1,4};
  char reflector_choice = 'c';
  int rings_settings[3] = {12,23,5};
  int starting_position[3] = {25,7,18};
  t_plug * plug_connections = init_plug_connection("AE.BF.CM.DQ.HU.JN.LX.PR.SZ.VW");

  // ROTORS
  t_rotor * r1 = init_rotor('R',"EKMFLGDQVZNTOWYHXUSPAIBRCJ");
  t_rotor * r2 = init_rotor('F',"AJDKSIRUXBLHWTMCQGZNPYFVOE");
  t_rotor * r3 = init_rotor('W',"BDFHJLCPRTXVZNYEIWGAKMUSQO");
  t_rotor * r4 = init_rotor('K',"ESOVPZJAYQUIRHXLNFTGKDCMWB");
  t_rotor * r5 = init_rotor('A',"VZBRGITYUPSDNHLXAWMJQOFECK");

  // REFLECTORS
  t_reflector * refa = init_reflector("EJMZALYXVBWFCRQUONTSPIKHGD");
  t_reflector * refb = init_reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");
  t_reflector * refc = init_reflector("FVPJIAOYEDRZXWGCTKUQSBNMHL");

  // MESSAGE A CODER / DECODER
  char * message;
  printf("Message a coder ou decoder :\n");
  scanf("%s",message);
  char result[strlen(message)+1];
  result[strlen(message)] = '\0';

  return 0;
}

// INITIALISATION ROTOR, REFLECTOR ET PLUG CONNECTIONS

t_rotor * init_rotor(int n, char * t){
  t_rotor * rotor = malloc(sizeof(*rotor));
  assert(rotor != NULL);
  rotor->notche = n;
  for(int i=0;i<26;i++){
    (rotor->alph)[i]=t[i];
  }
  return rotor;
}

t_reflector * init_reflector(char * t){
  t_reflector * reflector = malloc(sizeof(*reflector));
  assert(reflector != NULL);
  for(int i=0;i<26;i++){
    (*reflector)[i]=t[i];
  }
  return reflector;
}

t_plug * init_plug_connection(char * t){
  t_plug * plug = malloc(sizeof(*plug));
  assert(plug != NULL);
  int j=0;
  for(int i=0;i<10;i++){
    plug->swap1[i]=t[3*i];
    plug->swap2[i]=t[3*i+1];
  }
  return plug;
}

// MAPPING

int recherche(int n, int * swap){
  for(int i=0; i<10;i++){
    if (swap[i]=n){
      return i;
    }
  }
  return 10;
}

int map(int n, t_plug * plug){
  int j = recherche(n,plug->swap1);
  if (j!=10){
    return plug->swap2[j];
  }
  j = recherche(n,plug->swap2);
  if (j!=10){
    return plug->swap1[j];
  }
  return n;
}

// ROTOR 1st path
int perm_rot(int n,t_rotor * rotor, int position){
  int j =(n+position -'A') % 26;

  return 0;
}

// REFLECTOR

int perm_ref(int n,t_reflector * reflector){
  return reflector[n-'A'];
}