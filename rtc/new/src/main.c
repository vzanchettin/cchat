#include <sys/timestamp.h>
#include <sys/videoprints.h>

int main(void)
{
  initVideo(); //Inicializa video  
   
  while (1)
   {
    // Loop infinito para e manter a execução
   }
  
  return 0;
}

// Para teste de escrita colocar o prints sobre abaixo do initVideo();
//printc(3, 5, 0x07, 0x04,'c');
//prints(3, 10, 0x07, 0x04,"teste");

// Códigos de consulta 
//char* timestamp[17];