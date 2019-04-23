#include <stdlib.h>
#include <stdio.h>

int DaysToMonth365[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int DaysToMonth366[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

long TicksInMillisecond = 10000L;
long TicksInSecond = 10000L * 1000L;

long TimeToTicks(int hour, int minute, int second);
int IsLeapYear(int year);
long DateToTicks(int year, int month, int day);

int main(void){

    int year = 2019; 
    int month = 04; 
    int day = 22; 
    int hour = 12; 
    int minute = 12; 
    int second = 12;
    
    long timestamp = TimeToTicks(hour,minute,second) + DateToTicks(year,month, day);

    timestamp = ((timestamp - 621355968000000000)/10000000); // COnverte de Tocks para Timestamp  
    // 1555935132 --> Valor calculado
    // 1555945932 --> Valor correto

    printf("%ld",timestamp);

    return 0;
}
// Contabiliza os segundos da hora informada 
long TimeToTicks(int hour, int minute, int second){
    long totalSeconds = ((hour * 3600L) + (minute * 60L)+second);
    return (totalSeconds * TicksInSecond);
}
// Verifica se é um ano com 365 ou 366 dias 
int IsLeapYear(int year){
  
    if ((year % 4) != 0)
        return 0;

    if ((year % 100) == 0)
        return ((year % 400) == 0);

    return 1;
}
// Contabiliza os segundos apartir do ano, mês e dia
long DateToTicks(int year, int month, int day)
{
    if (((year >= 1) && (year <= 9999)) && ((month >= 1) && (month <= 12)))
    {
        int *daysToMonth;

        if(IsLeapYear(year)){
          daysToMonth = DaysToMonth366; 
        }else{
          daysToMonth = DaysToMonth365;
        }  
          
        if ((day >= 1) && (day <= (daysToMonth[month] - daysToMonth[month - 1])))
        {
            int previousYear = year - 1;
            int daysInPreviousYears = ((((previousYear * 365) + (previousYear / 4)) - (previousYear / 100)) + (previousYear / 400));

            int totalDays = ((daysInPreviousYears + daysToMonth[month - 1]) + day) - 1;
            return (totalDays * 0xc92a69c000L);
        }
    }
}