#include <sys/serial.h>
#include <sys/timedate.h>
#include <sys/videoprints.h>
#include <sys/io.h>

int main(void) {

    init_serial();
    initVideo();

    while (1) {
        for(int x=0; x<=10000;x++){
           write_serial((char)x);
        }
    }
}
