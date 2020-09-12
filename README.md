# pa_repo0
Pilha e Fila - Venda de Ingressos

Detalhes de implementação:
As pilhas e filas do programa são controladas através de quatro ponteiros: guiche0, guiche1, fila0 e fila1.
Para "carrega", as informações de ingresso são inseridas e é definido o guiche onde eles serão carregados. o laço for checa se o guiche está cheio, e e nao estiver, insere os ingressos.
Para "chega", é checado qual a menor fila (se as duas forem do mesmo tamanho, a pessoa fica na fila 0) e se elas estão cheias.
Para "vende", é definido o guiche onde será vendida quantidade de ingressos armazenadas na fila. É checado se a fila está vazia e, se não estiver, o nome da primeira pessoa na fila é salvo num vetor auxiliar e é dado "pop" na fila, salvando a qtde de ingressos desejada em outra variavel auxiliar (k). Checa-se se a pilha está vazia e então um laço é percorrido k vezes, imprimindo a compra do ingresso e dando "pop" na pilha que guarda o numero do respectivo ingresso.
O programa é executado enquanto nao se digita a palavra "fim".
As quatro bibliotecas tem as mesmas funções, necessitando apenas mudar o include no main.c.
