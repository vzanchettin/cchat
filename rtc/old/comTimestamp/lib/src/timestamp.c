#include<sys/timestamp.h>

int year; 
int month; 
int day; 
int hour; 
int minute; 
int second;

typedef unsigned uint;
typedef unsigned long long uint64;

// Vetores da relação dos dias do ano 
int DaysToMonth365[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}; // Normal
int DaysToMonth366[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}; // Bissextos

//A PARTE
// Coloca os valores referente a  ano, mês, dia, hora, minutos e segundos nas variaveis inteiras 
void getDataHora();
int montaNumero(char um, char dois);

// Parte do calculo para retornar um long timestamp
long TicksInMillisecond = 10000L;
long TicksInSecond = 10000L * 1000L;
long TimeToTicks(int hour, int minute, int second);
int IsLeapYear(int year);
long DateToTicks(int year, int month, int day);
// Parte do calculo para retornar a string 
void SecondsSinceEpochToDateTime(int SecondsSinceEpoch, char *timestamp);
/* Função atribui um endereço de memoria que 
  contem o valor de timestamp calculado na função 
*/
long getTimestamp(){
    getDataHora(); // Popula as variaveis de tempo
    long timestamp = TimeToTicks(hour,minute,second) + DateToTicks(year,month, day);
    timestamp =((timestamp - (long)621355968000000000)/10000000);
    return timestamp;
}
// retorna uma string com o o seguinte formato [dia/mês/ano hora:minutos]
char* toString(int timeInt, char *timestamp){

   //SecondsSinceEpochToDateTime(timeInt, timestamp);
    return((char)42);
 
}

// Coloca os valores pegos nas variaveis de tempo
void getDataHora(){

    getDia();
    getMes();
    getAno();
    getHora();
    getMinuto();
    getSegundo();
 
}
// Printa o dia
void getDia(){
    outb(0x70, 0x07);
    char get = inb(0x71);
    char diaP2 = (get & 0X0F) + 0x30;
    char diaP1 = ((get & 0xF0) >> 4) + 0x30;
    day = montaNumero(diaP1,diaP2);  
}
// Printa o mês 
void getMes(){
    outb(0x70, 0x08);
    char get = inb(0x71);
    char mesP2 = (get & 0X0F) + 0x30;
    char mesP1 = ((get & 0xF0) >> 4) + 0x30; 
    month = montaNumero(mesP1,mesP2); 
}
// Printa o ano 
void getAno(){
    outb(0x70, 0x09);
    char get = inb(0x71);
    char anoP2 = (get & 0X0F) + 0x30;
    char anoP1 = ((get & 0xF0) >> 4) + 0x30;
    year = montaNumero(anoP1,anoP2)+2000; 
}
// Printa as Horas
void getHora(){
    outb(0x70, 0x04);
    char get = inb(0x71);
    char horasP2 = (get & 0X0F) + 0x30;
    char horasP1 = ((get & 0xF0) >> 4) + 0x30;
    hour = montaNumero(horasP1,horasP2);
}
// Printa os minutos
void getMinuto(){
    outb(0x70, 0x02);
    char get = inb(0x71);
    char minP2 = (get & 0X0F) + 0x30;
    char minP1 = ((get & 0xF0) >> 4) + 0x30;
    minute = montaNumero(minP1,minP2);
}
void getSegundo(){
    outb(0x70, 0x00);
    char get = inb(0x71);
    char segP2 = (get & 0X0F) + 0x30;
    char segP1 = ((get & 0xF0) >> 4) + 0x30;
    second = montaNumero(segP1,segP2);
}
// Monta a parte um com a parte dois 
int montaNumero(char um, char dois){
    int aux =0;  
    switch (um){
      case '0':
         aux = 0 + (int)dois;
      break;
      case '1':
         aux = 10 + (int)dois;
      break;
      case '2':
         aux = 20 + (int)dois;
      break;
      case '3':
         aux = 30 + (int)dois;
      break;
      case '4':
         aux = 40 + (int)dois;
      break;
      case '5':
         aux = 50 + (int)dois;
      break;
      case '6':
         aux = 60 + (int)dois;
      break;
      case '7':
         aux = 70 + (int)dois;
      break;
      case '8':
         aux = 80 + (int)dois;
      break;
      case '9':
         aux = 90 + (int)dois;
      break;
      default:
         return 0;
    }
  return 0;  
}
// PARTE DO CONVERSOR PARA TIMESTAMP
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
long DateToTicks(int year, int month, int day){
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
// PARTE DO CONVERSOR PARA STRING
void SecondsSinceEpochToDateTime(int SecondsSinceEpoch, char *timestamp){

      int sec;
      int quadricentennials, centennials, quadrennials, annuals;
      int year, leap;
      int yday, hour, min;
      int month, mday, wday;
      static const int daysSinceJan1st[2][13]=
      {
        {0,31,59,90,120,151,181,212,243,273,304,334,365}, // 365 days, non-leap
        {0,31,60,91,121,152,182,213,244,274,305,335,366}  // 366 days, leap
      };
     
      // Re-bias from 1970 to 1601:
      // 1970 - 1601 = 369 = 3*100 + 17*4 + 1 years (incl. 89 leap days) =
      // (3*100*(365+24/100) + 17*4*(365+1/4) + 1*365)*24*3600 seconds
      sec = SecondsSinceEpoch + 11644473600LL;
     
      wday = ((sec / 86400 + 1) % 7); // day of week
     
      // Remove multiples of 400 years (incl. 97 leap days)
      quadricentennials =(int) ((int)sec / (int)12622780800ULL); // 400*365.2425*24*3600
      sec %=(int) 12622780800ULL;
     
      // Remove multiples of 100 years (incl. 24 leap days), can't be more than 3
      // (because multiples of 4*100=400 years (incl. leap days) have been removed)
      centennials = ((int)sec /(int)3155673600ULL); // 100*(365+24/100)*24*3600
      if (centennials > 3)
      {
        centennials = 3;
      }
      sec -= centennials * 3155673600ULL;
     
      // Remove multiples of 4 years (incl. 1 leap day), can't be more than 24
      // (because multiples of 25*4=100 years (incl. leap days) have been removed)
      quadrennials = (sec / 126230400); // 4*(365+1/4)*24*3600
      if (quadrennials > 24)
      {
        quadrennials = 24;
      }
      sec -= quadrennials * 126230400ULL;
     
      // Remove multiples of years (incl. 0 leap days), can't be more than 3
      // (because multiples of 4 years (incl. leap days) have been removed)
      annuals = (sec / 31536000); // 365*24*3600
      if (annuals > 3)
      {
        annuals = 3;
      }
      sec -= annuals * 31536000ULL;
     
      // Calculate the year and find out if it's leap
      year = 1601 + quadricentennials * 400 + centennials * 100 + quadrennials * 4 + annuals;
      leap = !(year % 4) && (year % 100 || !(year % 400));
     
      // Calculate the day of the year and the time
      yday = sec / 86400;
      sec %= 86400;
      hour = sec / 3600;
      sec %= 3600;
      min = sec / 60;
      sec %= 60;
     
      // Calculate the month
      for (mday = month = 1; month < 13; month++)
      {
        if (yday < daysSinceJan1st[leap][month])
        {
          mday += yday - daysSinceJan1st[leap][month - 1];
          break;
        }
      } 
    
      
      //printf("\n%d",(int)sec);          // [0,59]
      //printf("\n%d",(int)min);          // [0,59]
      //printf("\n%d",(int)hour);        // [0,23]
      //printf("\n%d",(int)mday);        // [1,31]  (day of month)
      //printf("\n%d",(month));    // [0,11]  (month)
      //printf("\n%d",(int)(year)); // 70+     (year since 1900)
    }