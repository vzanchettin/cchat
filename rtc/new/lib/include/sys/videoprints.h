#ifndef VIDEOPRINTS_H
#define VIDEOPRINTS_H

// Inicializa o registrador do video
extern void initVideo();
// Printa na tela o valor de um char
extern void printc(int x, int y, int fcolor, int bcolor, int c);
// Printa na tela uma String 
extern void prints(int x, int y, int fcolor, int bcolor, char *str);

#endif 
