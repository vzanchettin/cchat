# RTC (real-time clock)

### Organização das pastas:

#### A pasta new, contam o a versão do código que pega a hora do RTC e retorna uma string do seguinte formato: "[dia/mês/ano hoara:minutos]". Alem de já conter a implementação das bibliotecas de escrita em video.

#### Na pasta old, temos o código antigo que utiliza a biblioteca TIME_H para a aquisição e para a conversão da hora para timestamp e timestamp para hora. Mas a mesma não pode ser utilizada pois não é possiveil a utilização de bibliotecas externas ou que dependem do sistema operacional.

#### Já na pasta testes, temos o código que realiza a conversão de uma data/hora para timestamp, mas não realiza o processo inverso nesse momento. OBS: Assim que realizar o restante dos ajustes os códigos da pasta seram inseridos no restante dos códigos da pasta new. 

### OBS:

#### A hora retornada pelo registrador, no código da pasta new, esta vindo com 3 hora a mais, pela questão do fuso  horário. Isso vai ser ajustado quando for terminado a questão da conversão do timestap na pasta testes.
