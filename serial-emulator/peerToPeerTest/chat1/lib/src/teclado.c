#include <sys/teclado.h>
#include <sys/videoprints.h>
#include <sys/history.h>
#include <sys/timedate.h>
#include <sys/io.h>

char key_map[250];

unsigned int posx = 2;
unsigned int posy = 23;

int key = 0;
int key_anterior = 0;

void print(int x){ // Printa o roda pé
    int a = x / 1000;
    x = x % 1000;

    printc(0, 24, 0x01, 0x0F, a + '0');

    a = x / 100;
    x = x % 100;
    printc(1, 24, 0x01, 0x0F, a + '0');

    a = x / 10;
    x = x % 10;
    printc(2, 24, 0x01, 0x0F, a + '0');

    a = x / 1;
    x = x % 1;
    printc(3, 24, 0x01, 0x0F, a + '0');
}

void init_teclado(void){
    int i;

    for (i = 0; i < 250; i++) {

        key_map[i] = -1;
    }

    key_map[0] = 0x00;
    key_map[1] = 0x01;
    key_map[2] = '1';
    key_map[3] = '2';
    key_map[4] = '3';
    key_map[5] = '4';
    key_map[6] = '5';
    key_map[7] = '6';
    key_map[8] = '7';
    key_map[9] = '8';
    key_map[10] = '9';
    key_map[11] = '0';
    key_map[12] = '-';
    key_map[13] = '=';
    key_map[16] = 'q';
    key_map[17] = 'w';
    key_map[18] = 'e';
    key_map[19] = 'r';
    key_map[20] = 't';
    key_map[21] = 'y';
    key_map[22] = 'u';
    key_map[23] = 'i';
    key_map[24] = 'o';
    key_map[25] = 'p';
    key_map[26] = '?';
    key_map[27] = '[';
    key_map[28] = '*';
    key_map[30] = 'a';
    key_map[31] = 's';
    key_map[32] = 'd';
    key_map[33] = 'f';
    key_map[34] = 'g';
    key_map[35] = 'h';
    key_map[36] = 'j';
    key_map[37] = 'k';
    key_map[38] = 'l';
    key_map[39] = '?';
    key_map[40] = '~';
    key_map[41] = '"';
    key_map[43] = ']';
    key_map[44] = 'z';
    key_map[45] = 'x';
    key_map[46] = 'c';
    key_map[47] = 'v';
    key_map[48] = 'b';
    key_map[49] = 'n';
    key_map[50] = 'm';
    key_map[51] = ',';
    key_map[52] = '.';
    key_map[53] = ';';
    key_map[57] = ' ';
    key_map[71] = '7';
    key_map[72] = '8';
    key_map[73] = '9';
    key_map[74] = '-';  
    key_map[75] = '4';
    key_map[76] = '5';
    key_map[77] = '6';
    key_map[78] = '+';
    key_map[79] = '1';
    key_map[80] = '2';
    key_map[81] = '3';
    key_map[82] = '0';
    key_map[83] = ',';
}

char map_key(int scancode){

    if (scancode > 130 || scancode < 0) {

        return -1;
    } else if (scancode == 28) {

        return key_map[scancode];
    }
    
    else {

    return key_map[scancode];
    }
}

char tecla(char** historico,int *linha,char *msg,int *indexMSG){
     int scancode = inb(0x60);

        print(scancode);

        key = map_key(scancode);

        if (key != key_anterior && key > 0 && key != '*') {

           // print(key);v
            printc(posx, posy, 0x01, 0x0F, key);
            msg[(*indexMSG)++] = key;
            posx++;
            key_anterior = key;
        } else if (key != key_anterior && key == '*') {
            // AQUI VAI O LANCE QUE MONTA O PACOTE e envia menssagem
                    msg[*indexMSG] = '\0';  
                    *indexMSG = 0;
                    (*linha)++;
                    if(*linha > 16){
                        *linha = 2;
                    }
                  
                    montahistorico(msg, day(), month(), year(), minute(), second(), hour(), historico, *linha);
            posy = 23;
            posx = 2;
            prints(posx, posy, 0x00, 0x00, "                                                           ");
            key_anterior = key;
        }
    return  key;
}