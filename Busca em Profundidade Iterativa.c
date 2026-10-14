#include <stdio.h>
#define TAM 20

int main()
{
    int i, j;
    int estadoInicial;
    int limite;
    int estado;
    int encontrado = 0;
    int primo;
    int pilha[TAM];
    int profundidade[TAM];
    int filho[TAM];

    printf("\n\n-------------------------------------------------------------------------");

    do
    {
        printf("\n\nDigite o estado inicial (0-100): ");

        if (scanf("%d", &estadoInicial) != 1)
        {
            printf("\nDigite apenas numeros!");
            while (getchar() != '\n');
            estadoInicial = -1;
        }
        else
        {
            if (estadoInicial < 0 || estadoInicial > 100)
            {
                printf("\nEstado inicial invalido! Digite de 0 a 100.");
            }
        }
    } while (estadoInicial < 0 || estadoInicial > 100);

    limite = TAM - 1;

    printf("\n\n-------------------------------------------------------------------------");

    printf("\n\nESTADO INICIAL = %d", estadoInicial);
    printf("\nLIMITE MAXIMO = %d", limite);

    for (int limiteAtual = 0; limiteAtual <= limite; limiteAtual++)
    {
        printf("\n\n-------------------------------------------------------------------------");

        printf("\n\nBUSCA COM LIMITE = %d", limiteAtual);

        for (i = 0; i <= limiteAtual; i++)
        {
            pilha[i] = -1;
            profundidade[i] = -1;
            filho[i] = 0;
        }

        pilha[0] = estadoInicial;
        profundidade[0] = 0;

        printf("\n\nPILHA INICIAL");

        for (i = limiteAtual; i >= 0; i--)
        {
            printf("\n[%d] = %d (profundidade %d)", i, pilha[i], profundidade[i]);
        }

        // ----------------------------------------------------------------------------------------

        int nivel = 0;

        int primos[25] = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 53, 59, 61, 67,
            71, 73, 79, 83, 89, 97
        };

        while (nivel >= 0)
        {
            estado = pilha[nivel];

            primo = 0;

            for (i = 0; i < 25; i++)
            {
                if (estado == primos[i])
                {
                    primo = 1;
                    break;
                }
            }

            if (primo == 1)
            {
                printf("\n\n-------------------------------------------------------------------------");

                printf("\n\nOBJETIVO ENCONTRADO!");
                printf("\nEstado = %d", estado);
                printf("\nNivel (numero de acoes) = %d", profundidade[nivel]);

                encontrado = 1;
                break;
            }

            // -----------------------------------------------------------------------------------------------

            if (profundidade[nivel] == limiteAtual)
            {
                printf("\n\nNivel %d atingiu o limite.", profundidade[nivel]);

                if (nivel > 0)
                {
                    printf("\n\n-------------------------------------------------------------------------");
                    printf("\n<<< RETORNANDO AO NIVEL %d >>>", nivel - 1);
                    printf("\nVoltando para o no: %d", pilha[nivel - 1]);
                    printf("\nExplorando o restante do nivel %d", nivel);
                    printf("\n-------------------------------------------------------------------------");
                }

                pilha[nivel] = -1;
                profundidade[nivel] = -1;
                filho[nivel] = 0;

                nivel--;
                continue;
            }

            if (filho[nivel] == 0)
            {
                filho[nivel] = 1;

                if (estado - 5 >= 0)
                {
                    pilha[nivel + 1] = estado - 5;
                    profundidade[nivel + 1] = profundidade[nivel] + 1;
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d - 5 = %d", estado, estado, pilha[nivel + 1]);
                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d (profundidade %d)", j, pilha[j], profundidade[j]);
                    }

                    nivel++;
                    continue;
                }
            }

            if (filho[nivel] == 1)
            {
                filho[nivel] = 2;

                if (estado + 2 <= 100)
                {
                    pilha[nivel + 1] = estado + 2;
                    profundidade[nivel + 1] = profundidade[nivel] + 1;
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d + 2 = %d", estado, estado, pilha[nivel + 1]);

                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d (profundidade %d)", j, pilha[j], profundidade[j]);
                    }

                    nivel++;
                    continue;
                }
            }

            if (nivel > 0)
            {
                printf("\n\n-------------------------------------------------------------------------");
                printf("\n<<< RETORNANDO AO NIVEL %d >>>", nivel - 1);
                printf("\nVoltando para o no: %d", pilha[nivel - 1]);
                printf("\nNao ha mais filhos para explorar no no: %d", estado);
                printf("\n-------------------------------------------------------------------------");
            }

            pilha[nivel] = -1;
            profundidade[nivel] = -1;
            filho[nivel] = 0;

            nivel--;
        }

        if (encontrado == 1)
        {
            break;
        }

        printf("\n\n-------------------------------------------------------------------------");

        printf("\n\nNenhum objetivo encontrado com limite %d.", limiteAtual);
    }

    printf("\n\n-------------------------------------------------------------------------");

    if (encontrado == 1)
    {
        printf("\n\nBUSCA FINALIZADA COM SUCESSO!");
    }
    else
    {
        printf("\n\nNENHUMA SOLUCAO ENCONTRADA.");
        printf("\nLimite maximo utilizado: %d", limite);
    }

    printf("\n\n-------------------------------------------------------------------------");

    printf("\n\n");

    return 0;
}
