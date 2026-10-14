#include <stdio.h>
#include <locale.h>
#define TAM 20

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //  pilha[]        = caminho atual (base no indice 0, topo em 'nivel')
    //  profundidade[] = profundidade de cada estado da pilha (mesma posição do estado)
    //  filho[]        = quantos filhos de cada nivel ja foram tentados (0, 1 ou 2)
    //  nivel          = profundidade atual (onde esta o topo da pilha)

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

    // Lê o estado inicial (0 a 100) e repete a pergunta se não for um número válido
    do
    {
        printf("\n\nDigite o estado inicial (0-100): ");

        if (scanf("%d", &estadoInicial) != 1)
        {
            printf("\nDigite apenas numeros!");
            while (getchar() != '\n');
            estadoInicial = -1;    // valor inválido só para repetir a pergunta (o 0 agora é válido)
        }
        else if (estadoInicial < 0 || estadoInicial > 100)
        {
            printf("\nEstado inicial invalido! Digite de 0 a 100.");
        }
    } while (estadoInicial < 0 || estadoInicial > 100);

    // O limite máximo é o maior possível para a pilha de 20 posições (TAM - 1 = 19)
    limite = TAM - 1;

    printf("\n\n-------------------------------------------------------------------------");

    printf("\n\nESTADO INICIAL = %d", estadoInicial);
    printf("\nLIMITE MAXIMO = %d", limite);

    for (int limiteAtual = 0; limiteAtual <= limite; limiteAtual++)
    {
        printf("\n\n-------------------------------------------------------------------------");

        printf("\n\nBUSCA COM LIMITE = %d", limiteAtual);

        // limpa a pilha, as profundidades e os filhos, e poe o estado inicial na base da pilha
        for (i = 0; i <= limiteAtual; i++)
        {
            pilha[i] = -1;
            profundidade[i] = -1;
            filho[i] = 0;
        }

        pilha[0] = estadoInicial;
        profundidade[0] = 0;    // o estado inicial está na profundidade 0

        printf("\n\nPILHA INICIAL");

        for (i = limiteAtual; i >= 0; i--)
        {
            printf("\n[%d] = %d (profundidade %d)", i, pilha[i], profundidade[i]);
        }

        // ----------------------------------------------------------------------------------------
        // Busca em Profundidade

        int nivel = 0;

        while (nivel >= 0)
        {
            estado = pilha[nivel];

            // Verificar se é primo ou não
            primo = 0;    // = 0 então não é primo

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
                printf("\nNivel = %d", profundidade[nivel]);

                encontrado = 1;
                break;
            }

            // -----------------------------------------------------------------------------------------------
            // Chegou no limite: este estado não pode ter filhos, então volta para o pai

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

                nivel--;    // volta um nivel na pilha(vai do filho para o pai)
                continue;    // Volta pro inicio do while
            }

            // Filho: Estado - 5
            if (filho[nivel] == 0)
            {
                filho[nivel] = 1;

                if (estado - 5 >= 0)    // o -5 não pode passar da casa 0
                {
                    pilha[nivel + 1] = estado - 5;
                    profundidade[nivel + 1] = profundidade[nivel] + 1;    // a profundidade do filho é a do pai + 1
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d - 5 = %d", estado, estado, pilha[nivel + 1]);
                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d (profundidade %d)", j, pilha[j], profundidade[j]);
                    }

                    nivel++;    // O filho vira o novo pai
                    continue;    // Volta pro inicio do while, tendo o filho como novo pai
                }
            }

            // Filho: Estado + 2
            if (filho[nivel] == 1)
            {
                filho[nivel] = 2;

                if (estado + 2 <= 100)    // o +2 não pode passar da casa 100
                {
                    pilha[nivel + 1] = estado + 2;
                    profundidade[nivel + 1] = profundidade[nivel] + 1;    // a profundidade do filho é a do pai + 1
                    filho[nivel + 1] = 0;

                    printf("\n\nEstado %d -> %d + 2 = %d", estado, estado, pilha[nivel + 1]);

                    printf("\n\nPILHA");

                    for (j = limiteAtual; j >= 0; j--)
                    {
                        printf("\n[%d] = %d (profundidade %d)", j, pilha[j], profundidade[j]);
                    }

                    nivel++;    // O filho vira o novo pai
                    continue;    // Volta pro inicio do while, tendo o filho como novo pai
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
            profundidade[nivel] = -1;
            filho[nivel] = 0;

            nivel--;    // Volta um nivel na pilha(o filho sai e voltamos para o pai)
        }

        // Se achou o objetivo, não precisa aumentar o limite
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
