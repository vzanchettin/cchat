#include <sys/serial.h>
#include <sys/timedate.h>
#include <sys/videoprints.h>
#include <sys/io.h>

int main(void) {

    init_serial();
    initVideo();

    while (1) {
        char c = read_serial();
        printc(3, 10, 0x07, 0x04, c);
    }
}
