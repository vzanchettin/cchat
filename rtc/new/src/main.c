#include <sys/timestamp.h>
#include <sys/videoprints.h>

int main(void){

  initVideo(); //Inicializa video  
  char* timestamp[17]; // Var que vai receber a string data hora formatada

  getDataHora(timestamp); // Busca a data/hora
  prints(3, 10, 0x07, 0x04,timestamp);// Mostra a data hora
 
  while (1){
    // Loop infinito para e manter a execução
   }
  
  return 0;
}
