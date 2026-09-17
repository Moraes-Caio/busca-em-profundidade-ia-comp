#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 100

//Função Primo
int ehPrimo(int x)
{
    int primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int i=0; i<25; i++)
    {
        if (primos[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    int atendido;
    int fila_vazia;
    int pilha[TAM];
    int nivel_atual, nivel_prox;
    int limite;

    printf("\n\n-------------------------------------------------------------------------");

        printf("\n\nPor favor digite um número válido para o estado inicial (0-100): ");
        scanf("%d", &pilha[0]);

    printf("\n-------------------------------------------------------------------------");


    printf("\n\nInsira o nível limite: ");
    scanf("%d", &limite);

    printf("\n\n-------------------------------------------------------------------------");

    printf("\n\nPILHA INICIAL");

    // Montando a pilha com -1 para simbolizar vazio
    for(i=limite-1; i>=0; i--)
    {
        if(i != 0)
        {
            pilha[i] = -1;
        }


        printf("\n[%d] = %d", i, pilha[i]);
    }

    printf("\n\n-------------------------------------------------------------------------");

    // Executando ações até a última posição da pilha ser preenchida
    while (pilha[limite-1] == -1)
    {
        for(i=limite-1; i>=0; i--)
        {
            if (nivel_atual < limite)
            {

                if ((pilha[i] != -1) && (i < limite - 1) && (pilha[i+1] == -1))
                {
                    atendido = pilha[i];

                    if (ehPrimo(atendido) == 1)
                    {
                       printf("\n\nPARABÉNS");
                       exit(0);
                    }

                    pilha[i+1] = pilha[i] - 5;
                    pilha[i] = pilha[i] + 2;

                    if (pilha[i+1] <= 0)
                    {
                        pilha[i+1] = -1;
                    }


                    printf("\n\nPilha com atendido = %d", atendido);

                    for (j=limite-1; j>=0; j--)
                    {
                        printf("\n[%d] = %d", j, pilha[j]);
                    }

                    break;
                }
            }
        }
    }

    printf("\n\n-------------------------------------------------------------------------");

    printf("\n\nPILHA FINAL");

    for (i=limite-1; i>=0; i--)
    {
        printf("\n[%d] = %d", i, pilha[i]);
    }

    printf("\n\n-------------------------------------------------------------------------");


    printf("\n\n");
    return 0;
}
