#include <sys/serial.h>
#include <sys/timedate.h>
#include <sys/videoprints.h>
#include <sys/io.h>

int main(void) {

    init_serial();
    initVideo();

    while (1) {
        char c = read_serial();
        write_serial('\n');
        write_serial(c);
    }
}
