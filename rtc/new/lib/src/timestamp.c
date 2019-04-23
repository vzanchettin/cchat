#include<sys/timestamp.h>

/* Função atribui um endereço de memoria que 
  contem o valor de timestamp calculado na função 
*/
void getTimestamp(int* timestamp);
// retorna uma string com o o seguinte formato [dia/mês/ano hora:minutos]
unsigned char*  toString(int* timestamp);

/* void getTimestramp(int* timestamp){
    timestamp[0] = '[';
    getDia(timestamp);
    getMes(timestamp);
    getAno(timestamp);
    getHora(timestamp);
    getMinuto(timestamp);
    timestamp[15] = ']';
} */
// Printa o dia
void getDia(char* timestamp){
    outb(0x70, 0x07);
    char get = inb(0x71);
    char diaP2 = (get & 0X0F) + 0x30;
    char diaP1 = ((get & 0xF0) >> 4) + 0x30;
    timestamp[1] = diaP1;
    timestamp[2] = diaP2;
    timestamp[3] = '/';
    //printc(3, 5, 0x06, 0x04, diaP1);
    //printc(4, 5, 0x06, 0x04, diaP2);
    //rintc(4, 5, 0x06, 0x04, "/");
}
// Printa o mês 
void getMes(char* timestamp){
    outb(0x70, 0x08);
    char get = inb(0x71);
    char mesP2 = (get & 0X0F) + 0x30;
    char mesP1 = ((get & 0xF0) >> 4) + 0x30;

    timestamp[4] = mesP1;
    timestamp[5] = mesP2;
    timestamp[6] = '/';
    //printc(3, 5, 0x06, 0x04, mesP1);
    //printc(4, 5, 0x06, 0x04, mesP2);
   // printc(4, 5, 0x06, 0x04, "/");
}
// Printa o ano 
void getAno(char* timestamp){
    outb(0x70, 0x09);
    char get = inb(0x71);
    char anoP2 = (get & 0X0F) + 0x30;
    char anoP1 = ((get & 0xF0) >> 4) + 0x30;
    timestamp[7] = anoP1;
    timestamp[8] = anoP2;
    timestamp[9] = ' ';
    //printc(3, 5, 0x06, 0x04, anoP1);
    //printc(4, 5, 0x06, 0x04, anoP2);
    // printc(4, 5, 0x06, 0x04, "/");
}
// Printa as Horas
void getHora(char* timestamp){
    outb(0x70, 0x04);
    char get = inb(0x71);
    char horasP2 = (get & 0X0F) + 0x30;
    char horasP1 = ((get & 0xF0) >> 4) + 0x30;
  
    timestamp[10] = horasP1;//horasP1;
    timestamp[11] = horasP2;
    timestamp[12] = ':';
    //printc(3, 5, 0x06, 0x04,horasP1);
    //printc(4, 5, 0x06, 0x04, horasP2);
}
// Printa os minutos
void getMinuto(char* timestamp){
    outb(0x70, 0x02);
    char get = inb(0x71);
    char minP2 = (get & 0X0F) + 0x30;
    char minP1 = ((get & 0xF0) >> 4) + 0x30;

    timestamp[13] = minP1;
    timestamp[14] = minP2;
    //printc(3, 5, 0x06, 0x04, minP1);
    //printc(4, 5, 0x06, 0x04, minP2);
   // printc(4, 5, 0x06, 0x04, ":");
}