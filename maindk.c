/*
  000000000000000000000000000000000
  00                             00
  00   0000                      00
  00   00     00000000           00
  00   00     00  0  0   00000   00
  00          00  0  0   00      00
  00                     00  000 00
  00                     00   00 00
  00                     0000000 00
  00                             00
  000000000000000000000000000000000
*/
#include<stdio.h>
#include<gb/gb.h>
#include<gb/drawing.h>
#include <gb/sample.h>
#include<time.h>
#include<stdlib.h>
#include<rand.h>

#define SAMPLES 256             //length sample
extern UBYTE okey[]; 
extern UBYTE sample1[];        //Bank 1
extern UBYTE sample2[];       //bank 2
extern UBYTE sample3[]; 
extern UBYTE sample4[]; 
extern UBYTE samm[]; 


extern unsigned char number[];


unsigned char i=0;          //to fors
unsigned char p=0;         //pointer
unsigned char Twoo=1;     //swith

                         //tiles
unsigned char numero[] ={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};



        /* >>>>>>>> FUNCIONES <<<<<<  */

       /* >>>>>   MODO   BMP <<<<<<< */

//INCREMENTAR TODO EL SAMPLE
int up(UBYTE sample[]){
for(i=0;i<256;i++){
sample[i]++;
sample[i+256]++; //correccion para acceder a las posiciones superiores a 78
sample[i+256]--;
}
return sample;
}
//DECREMENTAR TODO EL SAMPLE
int down(UBYTE sample[]){
for(i=0;i<256;i++){
sample[i]--;
sample[i+256]--; //correccion para acceder a las posiciones superiores a 78
sample[i+256]++;
}
return sample;
}
//RANDOMOXAR TODO EL SAMPLE
int randomixar(UBYTE sample[]){
for(i=0;i<78;i++){
sample[i]=rand();
sample[rand()+256]=sample[i]; //correccion para acceder a las posiciones superiores a 32
sample[i+256]+=sample[i];    //correccion para acceder a las posiciones superiores a 78
}
return sample;
}
//PONER EN CERO TODO EL SAMPLE
int resett(UBYTE sample[]){
for(i=0;i<200;i++){
sample[i]=0;
sample[i+200]=0; //correccion para acceder a las posiciones superiores a 200
}
return sample;
}

//PARA EL USO DE LOS CONTROLES
int inputt(UBYTE sample[]){
                if(joypad()==J_UP+J_SELECT){up(sample);}
                if(joypad()==J_DOWN+J_SELECT){down(sample);}
                if(joypad()==J_B+J_SELECT){randomixar(sample);}
                if(joypad()==J_A+J_SELECT){resett(sample);}
                if(joypad()==J_RIGHT){p++;}
                if(joypad()==J_LEFT){p--;}
                if(p>80){p=0;}if(p<0){p=80;}
                if(joypad()==J_UP){sample[p]++;}
                if(joypad()==J_DOWN){sample[p]--;}
                if(joypad()==J_B){sample[p]=rand();}
                if(joypad()==J_A){sample[p]=0;}
return sample;
}


              /*>>>>>>  MODO RANDOMICO <<<<<<*/

//REPRODUCE EL SAMPLE
void playbitt(){
       set_bkg_tiles(0,0,20,20,sample1);SHOW_BKG;
       play_sample(sample1, 40 / 16);
}

//PARA EL USO DE CONTROLES
void InputtRand(UBYTE x){
if(x==J_RIGHT){
       for(i=0;i<rand();i++){sample1[i]++;}          //incrementa el sample
       playbitt();                                  //de forma randomica
}
if(x==J_UP){
       for(i=0;i<40;i++){sample1[i]++;}           //incrementa todo el sample
       playbitt();
}
if(x==J_DOWN){
       for(i=0;i<40;i++){sample1[i]--;}        //decrementa todo el sample
       playbitt();
}if(x==J_A){
       for(i=0;i<rand();i++){sample1[i]=0;}  //pone en cero el sample
       playbitt();
}if(x==J_LEFT){
       for(i=0;i<rand();i++){sample1[i]--;}//decrementa el sample de forma randomica
       playbitt();
}if(x==J_START){playbitt();               //loopea el mismo sample
}if(x==J_SELECT){InputtRand(rand());}    //llamada recursiva de forma randomica
}

int okeyed(){
      SWITCH_RAM_MBC1 (1) ;
      if(okey[0]=='o'&&okey[1]=='k'&&okey[2]=='e'&&okey[3]=='y'){return 1;}
      else{return 0;}
}

void iniziar(){
    set_bkg_data(0,64,number);
    if(okeyed()==0){
        printf("inixializando...\n");
        SWITCH_RAM_MBC1 (1) ;
        okey[0]='o';
        okey[1]='k';
        okey[2]='e';
        okey[3]='y';
 for(i=0;i<200;i++){if(joypad()==J_A){break;}
        printf("inizializando...\n");
        sample1[i]=samm[i];sample1[i+200]=samm[i+200];
        sample2[i]=samm[i];sample2[i+200]=samm[i+200];
        sample3[i]=samm[i];sample3[i+200]=samm[i+200];
        sample4[i]=samm[i];sample4[i+200]=samm[i+200];}
}
}

void RandMode(){
       printf("Rand Music Generator\n");
       printf("This is \n");
       printf("ALL RANDOM MODE \n");
       printf("you only listen \n");
       printf("THE RANDOM MUSIC \n");
       printf("Press B to Back to Menu \n");
       printf("\nPRESS START\nTO CONTINUE");
       waitpad(J_START);
       
       iniziar();

       while(1){
       for(i=0;i<40;i++){sample1[i]=rand();}
       while(joypad()!=0){InputtRand(joypad());}
       set_bkg_tiles(0,0,20,20,sample1);SHOW_BKG;
       play_sample(sample1, 40 / 16);
       if(joypad()==J_B){break;}
       }
}

void Menu(){
        while(1){
        if(Twoo==1){if(joypad()==J_SELECT){Twoo=0;}
        printf("  > RAND MODE\n");
        printf("    BPM MODE\n");if(joypad()==J_A){RandMode();Twoo=0;
        
        SWITCH_RAM_MBC1 (1) ;
        set_bkg_data(0,64,number);
        
        SHOW_BKG;}
        }else{if(joypad()==J_SELECT){Twoo=1;}
        printf("    RAND MODE\n");
        printf("  > BPM MODE\n");if(joypad()==J_A){break;}
        } printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  }
}

int BmpMode(UBYTE sample[]){
                set_bkg_tiles(0,0,20,20,sample);
                SHOW_BKG;
                if(joypad()!=0){inputt(sample);}
                return sample;
}

void banknumber(unsigned char num){
 /*set_win_data(0,64,number)*/;p=0;
 /*for(i=num*64;i<num*64+64;i++){numero[p]=number[i];p++;}*/
 for(i=0;i<64;i++){numero[i]=num;}
 set_win_tiles(0,0,8,8,numero);
 SHOW_WIN;
}

void Parts(){
 if(joypad()==J_RIGHT+J_SELECT){Twoo++;
 printf("BANK");banknumber(Twoo);waitpadup();HIDE_WIN;}
 if(joypad()==J_LEFT+J_SELECT){Twoo--;
 banknumber(Twoo);waitpadup();HIDE_WIN;}
 switch(Twoo){
     case 0x00:SWITCH_RAM_MBC1 (1) ; BmpMode(sample1);break;
     case 0x01:SWITCH_RAM_MBC1 (1) ; BmpMode(sample2);break;
     case 0x02:SWITCH_RAM_MBC1 (1) ; BmpMode(sample3);break;
     case 0x03:SWITCH_RAM_MBC1 (1) ; BmpMode(sample4);break;
     default: Twoo=0;
}
}

void main()
{
        ENABLE_RAM_MBC1;
	Menu();
        printf("Rand Music Generator\n");
        printf("Press A to RESET\n");
        printf("Press B to RANDOM\n");
        printf("Use R/L to POS\n");
        printf("Use U/D to VAL\n");
        printf("Use SEL to SELEC ALL\n");
        printf("Use SEL+R to BANK\n");
        printf("\nPRESS START\nTO CONTINUE");
        waitpad(J_START);

        iniziar();
        
	while(1)
	{
                Parts();
		if(joypad()==J_START){
		puts(".");
		play_sample(sample1, SAMPLES / 16);
                play_sample(sample2, SAMPLES / 16);
                play_sample(sample3, SAMPLES / 16);
                play_sample(sample4, SAMPLES / 16);
		waitpadup();
                }
                delay(50);

	}
}
unsigned char number[] =
{
  0xFF,0xFF,0xFF,0x81,0xFF,0xB9,0xFF,0xB5,
  0xFF,0xAD,0xFF,0x9D,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFD,0xFF,0xF9,0xFF,0xFD,
  0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xFD,0xFF,0xFD,
  0xFF,0x87,0xFF,0xBF,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xFD,0xFF,0xF1,
  0xFF,0xFD,0xFF,0xFD,0xFF,0xE1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFD,0xFF,0xBD,0xFF,0x81,
  0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBF,0xFF,0xBF,
  0xFF,0xC1,0xFF,0xFD,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBF,0xFF,0xBF,
  0xFF,0xA1,0xFF,0x8D,0xFF,0xE1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xFD,0xFF,0xFD,
  0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBD,0xFF,0x81,
  0xFF,0xBD,0xFF,0xBD,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBD,0xFF,0x81,
  0xFF,0xFD,0xFF,0xFD,0xFF,0xFD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBD,0xFF,0xBD,
  0xFF,0x81,0xFF,0xBD,0xFF,0xBD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xBF,0xFF,0xBF,0xFF,0x83,
  0xFF,0xBD,0xFF,0xBD,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBF,0xFF,0xBF,
  0xFF,0xBF,0xFF,0xBF,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xBD,0xFF,0xBD,
  0xFF,0xBD,0xFF,0xBD,0xFF,0x87,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBF,0xFF,0x8F,
  0xFF,0xBF,0xFF,0xBF,0xFF,0x87,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x81,0xFF,0xBF,0xFF,0x87,
  0xFF,0xBF,0xFF,0xBF,0xFF,0xBF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAD,0xFF,0xAD,
  0xFF,0xAD,0xFF,0xAD,0xFF,0xA1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xBD,0xFF,0xBD,0xFF,0xBD,
  0xFF,0xBD,0xFF,0xBD,0xFF,0xBD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xBD,0xFF,0xA1,
  0xFF,0xAF,0xFF,0xAF,0xFF,0xA1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xBD,0xFF,0xBD,
  0xFF,0xB1,0xFF,0xBD,0xFF,0xB9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xAD,0xFF,0xAD,0xFF,0xA1,
  0xFF,0xBD,0xFF,0xBD,0xFF,0xBD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAF,0xFF,0xAF,
  0xFF,0xB1,0xFF,0xBD,0xFF,0xB1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xB1,0xFF,0xAF,0xFF,0xAF,
  0xFF,0xA9,0xFF,0xA5,0xFF,0xB9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xBD,0xFF,0xBD,
  0xFF,0xBD,0xFF,0xBD,0xFF,0xBD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAD,0xFF,0xA1,
  0xFF,0xAD,0xFF,0xAD,0xFF,0xA1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAD,0xFF,0xA1,
  0xFF,0xBD,0xFF,0xBD,0xFF,0xBD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAD,0xFF,0xAD,
  0xFF,0xA1,0xFF,0xAD,0xFF,0xAD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xAF,0xFF,0xAF,0xFF,0xAF,
  0xFF,0xA1,0xFF,0xAD,0xFF,0xA1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAF,0xFF,0xAF,
  0xFF,0xAF,0xFF,0xAF,0xFF,0xA1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA3,0xFF,0xAD,0xFF,0xAD,
  0xFF,0xAD,0xFF,0xAF,0xFF,0xA3,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAF,0xFF,0xA3,
  0xFF,0xAF,0xFF,0xAF,0xFF,0xA1,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xA1,0xFF,0xAF,0xFF,0xA3,
  0xFF,0xAF,0xFF,0xAF,0xFF,0xAF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xE9,0xFF,0xC9,
  0xFF,0xBF,0xFF,0xBF,0xFF,0x8F,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x85,0xFF,0xF5,0xFF,0xED,
  0xFF,0x9D,0xFF,0xBD,0xFF,0x85,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x8F,0xFF,0xEF,0xFF,0x89,
  0xFF,0xBD,0xFF,0x89,0xFF,0xFB,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xED,0xFF,0xD9,
  0xFF,0x8D,0xFF,0xFD,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x8F,0xFF,0xEB,0xFF,0x99,
  0xFF,0x8D,0xFF,0xFD,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x8F,0xFF,0xE9,0xFF,0x9B,
  0xFF,0x89,0xFF,0xFD,0xFF,0x81,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x8B,0xFF,0xEB,0xFF,0x99,
  0xFF,0x95,0xFF,0xF9,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xED,0xFF,0x8D,
  0xFF,0xBD,0xFF,0xCD,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xE9,0xFF,0x99,
  0xFF,0x89,0xFF,0xFF,0xFF,0xF9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xE9,0xFF,0x99,
  0xFF,0x89,0xFF,0xFD,0xFF,0xFD,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xED,0xFF,0x9D,
  0xFF,0x89,0xFF,0xF9,0xFF,0xF9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x8B,0xFF,0xEB,0xFF,0x9B,
  0xFF,0x89,0xFF,0xF9,0xFF,0xF9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xEB,0xFF,0xDB,
  0xFF,0x89,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x8D,0xFF,0xED,0xFF,0xDD,
  0xFF,0x89,0xFF,0xF9,0xFF,0xF9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xEB,0xFF,0xDB,
  0xFF,0x89,0xFF,0xFB,0xFF,0xF9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xEB,0xFF,0xDB,
  0xFF,0x89,0xFF,0xFB,0xFF,0xFB,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x87,0xFF,0xF7,0xFF,0x9F,
  0xFF,0xF1,0xFF,0xF5,0xFF,0x91,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x85,0xFF,0xF5,0xFF,0xF5,
  0xFF,0x85,0xFF,0xF5,0xFF,0x8D,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x87,0xFF,0xF7,0xFF,0xE9,
  0xFF,0x8D,0xFF,0xEB,0xFF,0x89,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xED,0xFF,0xED,
  0xFF,0x89,0xFF,0xED,0xFF,0x89,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x87,0xFF,0xF7,0xFF,0xFF,
  0xFF,0x95,0xFF,0xF1,0xFF,0x9D,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x87,0xFF,0xF9,0xFF,0xF7,
  0xFF,0x91,0xFF,0xFD,0xFF,0x93,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xF9,0xFF,0xF7,
  0xFF,0xC3,0xFF,0xF5,0xFF,0xC9,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xFB,0xFF,0xFF,
  0xFF,0x81,0xFF,0xFD,0xFF,0x85,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xFB,0xFF,0xFF,
  0xFF,0x91,0xFF,0xF1,0xFF,0x91,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xFB,0xFF,0xFF,
  0xFF,0x91,0xFF,0xF1,0xFF,0x9D,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xFB,0xFF,0xFF,
  0xFF,0x91,0xFF,0xF5,0xFF,0x95,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xFB,0xFF,0xFF,
  0xFF,0x8B,0xFF,0xF9,0xFF,0x89,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x83,0xFF,0xFB,0xFF,0xFF,
  0xFF,0x89,0xFF,0xFB,0xFF,0x89,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x8D,0xFF,0xFD,0xFF,0xFD,
  0xFF,0x89,0xFF,0xFB,0xFF,0x89,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xFF,0xFF,0xFF,
  0xFF,0x89,0xFF,0xFB,0xFF,0x89,0xFF,0xFF,
  0xFF,0xFF,0xFF,0x89,0xFF,0xF7,0xFF,0xF7,
  0xFF,0x89,0xFF,0xFB,0xFF,0x8B,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xBF,0xFF,0xBF,0xFF,0x8F,
  0xFF,0xF1,0xFF,0xF5,0xFF,0xF1,0xFF,0xFF
};
UBYTE samm[] =
{
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x01,0x00,
  0x00,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x01,0x00,
  0x00,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x01,0x01,
  0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,
  0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,
  0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x00,0x01,0x01,0x00,0x00,0x00,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x00,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01
};