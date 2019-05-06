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
    int COM = 0x3f8; /* COM1 */
    init_serial(COM);
    init_Video();
    init_teclado();
    char t = ' ';
    while (1)
    {
        if (serial_received(COM))
        {
            char c = read_serial(COM);
            printc(5, 11, 0x02, 0x08, c);
        }
        t = tecla();
        if (t != ' ')
        {
            write_serial(t, COM);
            t = ' ';
        }
    }
}
