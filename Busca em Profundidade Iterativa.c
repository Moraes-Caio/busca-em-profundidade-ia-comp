#include <stdio.h>
#include <locale.h>
#define TAM 100

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    //  pilha[]  = caminho atual (base no indice 0, topo em 'nivel')
    //  filho[]  = quantos filhos de cada nivel ja foram tentados (0, 1 ou 2)
    //  nivel    = profundidade atual (onde esta o topo da pilha)
    
    int i, j;
    int estadoInicial;
    int limite;
    int estado;
    int encontrado = 0;
    int primo;
    int pilha[TAM];
    int filho[TAM];

    printf("\n\n-------------------------------------------------------------------------");
    
    do
    {
        printf("\n\nDigite o estado inicial (1-100): ");

        if (scanf("%d", &estadoInicial) != 1)
        {
            printf("\nDigite apenas numeros!");
            while (getchar() != '\n');
            estadoInicial = 0;
        }
        else if (estadoInicial < 1 || estadoInicial > 100)
        {
            printf("\nEstado inicial invalido! Digite de 1 a 100.");
        }
    } while (estadoInicial < 1 || estadoInicial > 100);

    printf("\n\n-------------------------------------------------------------------------");
    
    do
    {
        printf("\n\nDigite o limite maximo: ");

        if (scanf("%d", &limite) != 1)
        {
            printf("\nDigite apenas numeros!");
            while (getchar() != '\n');
            limite = -1;
        }
        else if (limite < 0 || limite >= TAM)
        {
            printf("\nLimite invalido! Digite de 0 a %d.", TAM - 1);
        }
    } while (limite < 0 || limite >= TAM);

    printf("\n\n-------------------------------------------------------------------------");
    
    printf("\n\nESTADO INICIAL = %d", estadoInicial);
    printf("\nLIMITE MAXIMO = %d", limite);

    for (int limiteAtual = 0; limiteAtual <= limite; limiteAtual++)
    {
        printf("\n\n-------------------------------------------------------------------------");

        printf("\n\nBUSCA COM LIMITE = %d", limiteAtual);

        // limpa a pilha e os filhos, e poe o estado inicial na base da pilha
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
        
        // ----------------------------------------------------------------------------------------
        // Busca em Profundidade

        int nivel = 0;

        while (nivel >= 0)
        {
            estado = pilha[nivel];
            
            // Verificar se é primo ou não

            primo = 0;      // = 0 então não é primo

            int primos[25] = {
                2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67,
                71, 73, 79, 83, 89, 97
            };

            for (i = 0; i < 25; i++)
            {
                if (estado == primos[i])
                {
                    primo = 1;    // = 1 então é primo
                    break;
                }
            }

            // Objetivo Encontrado

            if (primo == 1)
            {
                printf("\n\n-------------------------------------------------------------------------");

                printf("\n\nOBJETIVO ENCONTRADO!");
                printf("\nEstado = %d", estado);
                printf("\nNivel = %d", nivel);

                printf("\n\nCAMINHO ENCONTRADO");
                
                encontrado = 1;
                break;
            }

            // -----------------------------------------------------------------------------------------------
            
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

                nivel--;  // volta um nivel na pilha(vai do filho para o pai)
                continue;   // Volta pro inicio do while
            }

            // Filho: Estado - 5

            if (filho[nivel] == 0)
            {
                filho[nivel] = 1;

                if (estado - 5 > 0)
                {
                    pilha[nivel + 1] = estado - 5;
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d - 5 = %d", estado, estado, pilha[nivel + 1]);
                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d", j, pilha[j]);
                    }

                    nivel++;   // O filho vira o novo pai
                    continue;  // Volta pro inicio do while, tendo o filho como novo pai
                }
            }
            
            // Filho: Estado + 2

            if (filho[nivel] == 1)
            {
                filho[nivel] = 2;

                if (estado + 2 <= 100)
                {
                    pilha[nivel + 1] = estado + 2;
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d + 2 = %d", estado, estado, pilha[nivel + 1]);

                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d", j, pilha[j]);
                    }

                    nivel++;   // O filho vira o novo pai
                    continue;  // Volta pro inicio do while, tendo o filho como novo pai
                }
            }

            // Não possui mais filhos(já passou pelos dois if de filhos)

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

            nivel--;   // Volta um nivel na pilha(o filho sai e voltamos para o pai)
        }

        if (encontrado == 1)
        {
            break;
        }

        printf("\n\n-------------------------------------------------------------------------");

        printf("\n\nNenhum objetivo encontrado com limite %d.", limiteAtual);
    }


    // Final

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
