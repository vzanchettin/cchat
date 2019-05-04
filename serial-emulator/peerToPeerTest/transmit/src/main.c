#include <sys/serial.h>
#include <sys/timedate.h>
#include <sys/videoprints.h>
#include <sys/teclado.h>
#include <sys/io.h>
//char COM2 = 0x2f8;   /* COM2 */
/* Porta   Endereco I/O    IRQ
COM1    3F8              4
COM2    2F8              3
COM3    3E8              4
COM4    2E8              3 */

int main(void)
{
    int COM1 = 0x3f8; /* COM1 */
    int COM2 = 0x3e8; /* COM2 */
    init_serial(COM1);
    init_serial(COM2);
    init_Video();
    init_teclado();

    while (1)
    {
        char c = tecla();
        //printc(3, 10, 0x07, 0x04, c);

        write_serial(c, COM1);

        printc(3, 10, 0x07, 0x04, read_serial(COM2));
    }
}
