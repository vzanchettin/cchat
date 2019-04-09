#include <sys/io.h>

unsigned short *video = (unsigned short *) 0xB8000;

//key map com as teclas ABNT2
// unsigned char key_map[150] = {
//     0x00, 0x01, '1', '2', '3', '4', '5', '6', '7', '8',
//     '9', '0', '-', '=', '*', '*', 'q', 'w'
// };

unsigned char key_map[150] = {
0x00, 0x01, '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',  '-',  '=', 'N/D',
'N/D', 'q',  'w',  'e',  'r',  't',  'y',  'u',  'i',  'o',  'p',  '´',  '[',
'N/D', 'N/D', 'a',  's',  'd',  'f',  'g',  'h',  'j',  'k',  'l',  'ç',  '~',  ']',
'N/D', '\\',  'z',  'x',  'c',  'v',  'b',  'n',  'm',  ',',  '.',  ';',  'N/D'
};

int main(void)
{
    int key = 0;

    while (1) {
        key = inb(0x60);
        printc(0, 0, 0x05, 0x01, key_map[key]);
    }

    return 0;
}

void prints(int x, int y, int fcolor, int bcolor, char *str) {
    int inicio = x + y * 80; // *80 para ir pra proxima linha da matrix 80x25

    while (*str) {
        video[inicio] = (fcolor << 8) | (bcolor << 12) | *str;

        inicio++;
        str++;
    }
}

void printc(int x, int y, int fcolor, int bcolor, int c) {
    video[80] = (fcolor << 8) | (bcolor << 12) | c;
}
