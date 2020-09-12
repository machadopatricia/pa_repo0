#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaEstatica.h"
#include "FilaEstatica.h"
//#include "PilhaDinamica.h"
//#include "FilaDinamica.h"

int main()
{
    Pilha * guiche0 = criaPilha();
    Pilha * guiche1 = criaPilha();
    Fila * fila0 = criaFila();
    Fila * fila1 = criaFila();

    char vet[30] = {};
    char vetCar[] = "carrega";
    char vetChega[] = "chega";
    int G, A, B, N;
    int T = 0;

    scanf("%s", vet);

    //se 'fim' for o primeiro caso, imprime zero ingressos vendidos.
    if(!strcmp(vet, "fim"))
            printf("Ingressos vendidos: 0.\n");

    while(strcmp(vet, "fim"))
    {
        char vetP[25];
        int i = 0;
        int cont  = 0;

        //se for para carregar, insere ingressos no guiche desejado
        if(!strcmp(vet, vetCar))
        {
            scanf("%d %d %d", &G, &A, &B);

            if(G == 0)
            {
                for(i=A; i<=B; i++)
                {
                    //enquanto o guiche nao estiver cheio, insere cada numero de ingressos
                    if(!cheiaPilha(guiche0))
                    {
                        pushPilha(guiche0, i);
                        cont++;//contador de ingressos carregados no guiche
                    }
                    else
                        break;
                }
            }
            else
            {
                for(i=A; i<=B; i++)
                    if(!cheiaPilha(guiche1))
                    {
                        pushPilha(guiche1, i);
                        cont++;
                    }
                    else
                        break;
            }

            //Caso seja inserido um valor maior que o limite,
            //o 'cont' garante que a qtde de ingressos carregados apresentada seja somente a inserida no guiche
            printf("%d ingresso(s) carregado(s) no guiche %d.\n", cont, G);
        }
        //caso 'chega' insere a pessoa na fila 0 ou a de menor tamanho
        else if(!strcmp(vet, vetChega))
        {
            scanf("%s %d", vetP, &N);

            //se a fila0 for maior que a fila1 e não estiver cheia, pessoa entra na fila0
            if(tamFila(fila0) <= tamFila(fila1) && (!cheiaFila(fila0)))
            {
                pushFila(fila0, vetP, N);
                printf("%s entrou na fila 0.\n", vetP);
            }
            //se passar da primeira condição, a fila 1 é menor. se ela nao estiver cheia, pessoa entra na fila1
            else if(!cheiaFila(fila1))
            {
                pushFila(fila1, vetP, N);
                printf("%s entrou na fila 1.\n", vetP);
            }
            else//duas filas cheias, pessoas desistem
                printf("%s desistiu, filas cheias.\n", vetP);
        }
        //se for a opcao 'vende'
        else
        {
            scanf("%d", &G);

            //checa se a fila esta vazia e, caso nao esteja, recebe o nome da pessoa na frente e
            //faz pop na fila com a quantidade de ingressos que ela quer comprar.
            if(G == 0)
            {
                if(vaziaFila(fila0))
                    printf("Fila 0 vazia!\n");
                else
                {
                    strcpy(vetP, nomeFila(fila0));
                    int k = popFila(fila0);

                    //se o guiche estiver vazio, imprime aviso.
                    //caso contrario, vende os ingressos desejados enquanto o guiche não estiver vazio.
                    if(vaziaPilha(guiche0))
                        printf("Guiche 0 sem ingressos! %s triste.\n", vetP);
                    else
                    {
                        for(i=0; i<k; i++)
                        {
                            if(!vaziaPilha(guiche0))
                            {
                                printf("%s comprou ingresso #%d.\n", vetP, popPilha(guiche0));
                                T++;//contador de total de ingressos vendidos
                            }
                        }
                    }
                }
            }
            else
            {
                if(vaziaFila(fila1))
                    printf("Fila 1 vazia!\n");
                else
                {
                    strcpy(vetP, nomeFila(fila1));
                    int k = popFila(fila1);

                    if(vaziaPilha(guiche1))
                        printf("Guiche 1 sem ingressos! %s triste.\n", vetP);
                    else
                        for(i=0; i<k; i++)
                        {
                            if(!vaziaPilha(guiche1))
                            {
                                printf("%s comprou ingresso #%d.\n", vetP, popPilha(guiche1));
                                T++;
                            }
                        }
                }
            }
        }

        //faz nova leitura e checa caso 'fim'
        scanf("%s", vet);

        if(!strcmp(vet, "fim"))
            printf("Ingressos vendidos: %d.\n", T);
    }

    //desaloca memoria
    apagaPilha(guiche0);
    apagaPilha(guiche1);
    apagaFila(fila0);
    apagaFila(fila1);

    return 0;

}
