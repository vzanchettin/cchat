#include <sys/timedate.h>
// Dia
void getDia(char *str){
  outb(0x70, 0x07);
  str[0] = ((inb(0x71) & 0xF0) >> 4) + 0x30;
  str[1] = (inb(0x71) & 0X0F) + 0x30;
}
// Mês
void getMes(char *str){
  outb(0x70, 0x08);
  str[0] = ((inb(0x71) & 0xF0) >> 4) + 0x30;
  str[1] = (inb(0x71) & 0X0F) + 0x30;
}
// Ano
void getAno(char *str){
  outb(0x70, 0x09);
  str[0] = ((inb(0x71) & 0xF0) >> 4) + 0x30;
  str[1] = (inb(0x71) & 0X0F) + 0x30;
}
// Horas
void getHora(char *str){
  outb(0x70, 0x04);
  str[0] = ((inb(0x71) & 0xF0) >> 4) + 0x30;
  str[1] = ((inb(0x71) & 0X0F) + 0x30)-3; // menos 3 para ajustar a hora no nosso fuso
}
// Minutos
void getMinuto(char *str){
  outb(0x70, 0x02);
  str[0] = ((inb(0x71) & 0xF0) >> 4) + 0x30;
  str[1] = (inb(0x71) & 0X0F) + 0x30;
}
// Segundos
void getSegundo(char *str){
  outb(0x70, 0x00);
  str[0] = ((inb(0x71) & 0xF0) >> 4) + 0x30;
  str[1] = (inb(0x71) & 0X0F) + 0x30;
}
