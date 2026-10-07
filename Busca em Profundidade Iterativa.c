#include <stdio.h>
#include <locale.h>
#define TAM 100

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    int estadoInicial;
    int limite;
    int estado;
    int encontrado = 0;
    int primo;
    int pilha[TAM];
    int filho[TAM];

    printf("\n\n-------------------------------------------------------------------------");

    printf("\n\nDigite o estado inicial (1-100): ");
    scanf("%d", &estadoInicial);

    if (estadoInicial < 1 || estadoInicial > 100)
    {
        printf("\n\nEstado inicial invalido!");
        return 1;
    }

    printf("\n\n-------------------------------------------------------------------------");

    printf("\n\nDigite o limite maximo: ");
    scanf("%d", &limite);

    if (limite < 0 || limite >= TAM)
    {
        printf("\n\nLimite invalido!");
        return 1;
    }

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
            filho[i] = 0;
        }

        pilha[0] = estadoInicial;

        printf("\n\nPILHA INICIAL");

        for (i = limiteAtual; i >= 0; i--)
        {
            printf("\n[%d] = %d", i, pilha[i]);
        }

        // BUSCA EM PROFUNDIDADE

        int nivel = 0;

        while (nivel >= 0)
        {
            estado = pilha[nivel];

            // VERIFICA SE O ESTADO E PRIMO

            primo = 0;

            int primos[25] = {
                2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67,
                71, 73, 79, 83, 89, 97
            };

            for (i = 0; i < 25; i++)
            {
                if (estado == primos[i])
                {
                    primo = 1;
                    break;
                }
            }

            // OBJETIVO ENCONTRADO

            if (primo == 1)
            {
                printf("\n\n-------------------------------------------------------------------------");

                printf("\n\nOBJETIVO ENCONTRADO!");
                printf("\nEstado = %d", estado);
                printf("\nNivel = %d", nivel);

                printf("\n\nCAMINHO ENCONTRADO");

                for (i = 0; i <= nivel; i++)
                {
                    printf("\n[%d] = %d", i, pilha[i]);
                }

                encontrado = 1;
                break;
            }

            // CHEGOU NO LIMITE

            if (nivel == limiteAtual)
            {
                printf("\n\nNivel %d atingiu o limite.", nivel);

                if (nivel > 0)
                {
                    printf("\n\n-------------------------------------------------------------------------");
                    printf("\n<<< RETORNANDO AO NIVEL %d >>>", nivel - 1);
                    printf("\nVoltando para o no: %d", pilha[nivel - 1]);
                    printf("\nExplorando o restante do nivel %d", nivel);
                    printf("\n-------------------------------------------------------------------------");
                }

                pilha[nivel] = -1;
                filho[nivel] = 0;

                nivel--;

                continue;
            }

            // PRIMEIRO FILHO: ESTADO - 5

            if (filho[nivel] == 0)
            {
                filho[nivel] = 1;

                if (estado - 5 > 0)
                {
                    pilha[nivel + 1] = estado - 5;
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d - 5 = %d",
                           estado,
                           estado,
                           pilha[nivel + 1]);

                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d", j, pilha[j]);
                    }

                    nivel++;

                    continue;
                }
            }

            // SEGUNDO FILHO: ESTADO + 2

            if (filho[nivel] == 1)
            {
                filho[nivel] = 2;

                if (estado + 2 <= 100)
                {
                    pilha[nivel + 1] = estado + 2;
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d + 2 = %d",
                           estado,
                           estado,
                           pilha[nivel + 1]);

                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d", j, pilha[j]);
                    }

                    nivel++;

                    continue;
                }
            }

            // NAO POSSUI MAIS FILHOS

            if (nivel > 0)
            {
                printf("\n\n-------------------------------------------------------------------------");
                printf("\n<<< RETORNANDO AO NIVEL %d >>>", nivel - 1);
                printf("\nVoltando para o no: %d", pilha[nivel - 1]);
                printf("\nNao ha mais filhos para explorar no no: %d", estado);
                printf("\n-------------------------------------------------------------------------");
            }

            pilha[nivel] = -1;
            filho[nivel] = 0;

            nivel--;
        }

        // Se encontrou, encerra as iteracoes
        if (encontrado == 1)
        {
            break;
        }

        printf("\n\n-------------------------------------------------------------------------");

        printf("\n\nNenhum objetivo encontrado com limite %d.", limiteAtual);
    }

    // RESULTADO FINAL

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

