#include <sys/timedate.h>
#include <sys/videoprints.h>

int main(void){

  initVideo(); //Inicializa video  

  char vet;
  
  //getDia(vet);
  //getMes(vet);
  //getAno(vet);
  getHora(vet);
  
  //getMinuto(vet);
  //getSegundo(vet);

  prints(3, 10, 0x07, 0x04, vet);// Mostra a data hora
 
  while (1){
    // Loop infinito para e manter a execução
   }
  
  return 0;
}
