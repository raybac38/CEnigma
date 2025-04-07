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

typedef struct {
  t_rotor * r_order[3];
  t_reflector reflector;
  t_plug * plugboard;
  int * offset;
} t_settings;


t_rotor * init_rotor(int n, char * t);
t_reflector * init_reflector(char * t);
t_plug * init_plug_connection(char * t);
int * init_offset(int rs[3], int sp[3]);
t_settings * init_settings(int wo[3], int rc, int rs[3], int sp[3], char * pc, t_rotor * l_ro[5], t_reflector * l_re[3]);

int recherche(int n, int * swap);
int map(int n, t_plug * plug);

int perm1_rot(int n,t_rotor * rotor, int position);
int perm2_rot(int n,t_rotor * rotor, int position);

int perm_ref(int n,t_reflector reflector);


int main(){
  // SETTINGS
  int whell_order[3] = {2,1,4}; // CHOOSE 1 - 5
  int reflector_choice = 'C'; // CHOOSE A - C
  int rings_settings[3] = {12,23,5}; // CHOOSE 0 - 25
  int starting_position[3] = {'Z','K','R'}; // CHOOSE A - Z
  char * plug_connections = "AE.BF.CM.DQ.HU.JN.LX.PR.SZ.VW";

  // ROTORS
  t_rotor * r1 = init_rotor('R',"EKMFLGDQVZNTOWYHXUSPAIBRCJ");
  t_rotor * r2 = init_rotor('F',"AJDKSIRUXBLHWTMCQGZNPYFVOE");
  t_rotor * r3 = init_rotor('W',"BDFHJLCPRTXVZNYEIWGAKMUSQO");
  t_rotor * r4 = init_rotor('K',"ESOVPZJAYQUIRHXLNFTGKDCMWB");
  t_rotor * r5 = init_rotor('A',"VZBRGITYUPSDNHLXAWMJQOFECK");

  t_rotor * l_rotor[5] = {r1,r2,r3,r4,r5};

  // REFLECTORS
  t_reflector * refa = init_reflector("EJMZALYXVBWFCRQUONTSPIKHGD");
  t_reflector * refb = init_reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");
  t_reflector * refc = init_reflector("FVPJIAOYEDRZXWGCTKUQSBNMHL");

  t_reflector * l_reflector[3] = {refa,refb,refc};

  while(0 == 0)
  {

  }
  /*
  // SETTINGS SETUP
  t_settings * settings = init_settings(whell_order, reflector_choice, rings_settings, starting_position, plug_connections, l_rotor, l_reflector);

  // MESSAGE A CODER / DECODER
  char message[1000];
  printf("Message a coder ou decoder :\n");
  scanf("%s",message);
  char result[strlen(message)+1];
  result[strlen(message)] = '\0';

  for (int i=0; i<strlen(message);i++){
    // ROTATION
    if (settings->r_order[0]->notche = settings->offset[0]){
      if (settings->r_order[1]->notche = settings->offset[1]){
        settings->offset[2] = (settings->offset[2] + 1) % 26;
      }
      settings->offset[1] = (settings->offset[1] + 1) % 26;
    }
    settings->offset[0] = (settings->offset[0] + 1) % 26;

    // TRANSLATION
    int c = message[i];
    c = map(c,settings->plugboard);
    for(int j=0;j<3;j++){
      c = perm1_rot(c,settings->r_order[j], settings->offset[j]);
    }
    c = perm_ref(c, settings->reflector);
    for(int j=0;j<3;j++){
      c = perm2_rot(c,settings->r_order[2-j], settings->offset[2-j]);
    }
    c = map(c,settings->plugboard);
    result[i]=c;
  }
  printf("Message traduit :\n%s\n",result);
  return 0;
  */
}

// INITIALISATION ROTOR, REFLECTOR, PLUG CONNECTIONS ET SETTINGS

t_rotor * init_rotor(int n, char * t){
  t_rotor * rotor = malloc(sizeof(*rotor));
  assert(rotor != NULL);
  rotor->notche = n - 'A';
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

int * init_offset(int rs[3], int sp[3]){
  int * offset = malloc(3*sizeof(*offset));
  assert(offset != NULL);
  for (int i=0;i<3;i++){
    offset[i]=(rs[i]+(sp[i]-'A')) %26;
  }
  return offset;
}
/*
t_settings * init_settings(int wo[3], int rc, int rs[3], int sp[3], char * pc, t_rotor * l_ro[5], t_reflector * l_re[3]){
  t_settings * settings = malloc(sizeof(*settings));
  assert(settings != NULL);
  for (int i=0; i<3;i++){ // SET ROTOR ORDER
    settings->r_order[i]=l_ro[wo[i]-1];
  }
  settings->reflector = l_re[rc-'A']; // SET REFLECTOR CHOICE
  settings->plugboard = init_plug_connection(pc); // SET PLUGBOARD
  settings->offset = init_offset(rs, sp); // SET OFFSET
  return settings;
}
*/
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
int perm1_rot(int n,t_rotor * rotor, int position){
  return ((rotor->alph[(n+position-'A') % 26]-position -'A') % 26 + 26) % 26 + 'A';
}

// ROTOR 2nd path
int perm2_rot(int n,t_rotor * rotor, int position){
  return (rotor->alph[((n-position-'A') % 26 + 26) % 26]+position -'A') % 26 + 'A';
}

// REFLECTOR

int perm_ref(int n,t_reflector reflector){
  return reflector[n-'A'];
}
  