#ifndef TIMESTAMP_H
#define TIMESTAMP_H

// getTimestamp pega o valor inteiro de uma timestamp
extern void getTimestamp(int* timestamp);
// retorna uma string com o o seguinte formato [dia/mês/ano hora:minutos]
extern unsigned char*  toString(int* timestamp);

#endif

