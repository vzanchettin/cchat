#include <sys/io.h>
#include <sys/videoprints.h>

unsigned short *video;

// Inicializa o video
void init_Video(){
    
    video = (unsigned short *)0xB8000;

}
// Função sem retorno que imprime um char na tela
void printc(int x, int y, int fcolor, int bcolor, int c){
    
    video[x + y * 80] = (fcolor << 8) | (bcolor << 12) | c;

}
// Função sem retorno que imprime uma string na tela
void prints(int x, int y, int fcolor, int bcolor, char *str){

    int inicio = x + y * 80;

    while (*str){

     video[inicio] = (fcolor << 8) | (bcolor << 12) | *str;

     inicio++;
     str++;
    }
}

void desenhaTela(){


}





