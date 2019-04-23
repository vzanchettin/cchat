# Teste para definir a base do código que converte a hora para timestamp

### O cógigo toTimestamp, converte uma determindada data e hora para um padão similar ao timestap, este padrão é o utilizado no Windows, após converter para este padrão um calculo realiza a conversão do mesmo para o timestamp. Utilizei um conversor unline para comparar o valor adquirido com o software em questão em relação ao software online que deve usar bibliotecas para o calculo do mesmo. Segue a comparação dos valores:

* 1555935132 --> Valor calculado utilizando o toTimestamp.c
* 1555945932 --> Valor "correto" utilizando o unix-timestamp-converter 

### Link do conversor utilizado
https://awebanalysis.com/pt/unix-timestamp-converter/ 

### Links de apoio

#### * https://stackoverflow.com/questions/21593692/convert-unix-timestamp-to-date-without-system-libs
#### * https://pt.switch-case.com/51663438
#### * https://devkimchi.com/2018/11/04/converting-tick-or-epoch-to-timestamp-in-logic-app/

### OBS: 

#### Ainda não foi codificado, o conversor que pega o valor do timestamp e passa ele para o padrão [dia/mes/ano hoara:data]. O mesmo vai ser chamado de timestampToString.c.