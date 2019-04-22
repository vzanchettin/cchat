#include <sys/io.h>

unsigned short *video = (unsigned short *)0xB8000; 

unsigned posx = 0;
unsigned posy = 0;

  void printc (int x, int y, int fcolor, int bcolor, int c) {

        video[x + y * 80] = (fcolor << 8) | (bcolor << 12) | c;
    }

    void prints (int x, int y, int fcolor, int bcolor, char *str) {

        int inicio = x + y * 80;

        while (*str) {

            video[inicio] = (fcolor << 8) | (bcolor << 12) | *str;

            inicio++;
            str++;
        }
    }


int main(void)
{
    while (1) {
  
    
     
    }

    return 0;
}

void minutos(){
  outb(0x70,0x02);
      char v = inb(0x71);
      char min = (v & 0X0F)+ 0x30;
      char min2 = ((v& 0xF0) >> 4) + 0x30;
      
      printc(3,5,0x06,0x04,min2);
      printc(4,5,0x06,0x04,min);
      printc(4,5,0x06,0x04,":");
}