#include <stdio.h>
#include <time.h>

int main(void){
    
    time_t     timesTamp;
    struct tm  ts;
    char       buf[80];

    timesTamp = 1554766189;

    ts = *localtime(&timesTamp);
 
    // Ano, mês, dia, hora, minutos, segundos, zona de tempo 
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S %Z", &ts);
    printf("%s\n", buf);
    // Hora, mês, segundos
    strftime(buf, sizeof(buf), "%H:%M:%S", &ts);
    printf("%s\n", buf);

    return 0;
}