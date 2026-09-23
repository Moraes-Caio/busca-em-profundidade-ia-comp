#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 100

// ---------------------------------------------------------
// Verifica se o número é primo
// ---------------------------------------------------------
int ehPrimo(int x)
{
    int primos[25] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97
    };

    for (int i = 0; i < 25; i++)
    {
        if (primos[i] == x)
        {
            return 1;
        }
    }

    return 0;
}

// ---------------------------------------------------------
// Mostra a identação de acordo com o nível
// ---------------------------------------------------------
void mostrarNivel(int nivel)
{
    for (int i = 0; i < nivel; i++)
    {
        printf("    ");
    }
}

// ---------------------------------------------------------
// Busca em profundidade limitada
// ---------------------------------------------------------
int buscaProfundidade(int estado, int nivel, int limite)
{
    // Mostra o estado atual
    mostrarNivel(nivel);
    printf("Nivel %d -> Estado: %d\n", nivel, estado);

    // Verifica se encontrou o objetivo
    if (ehPrimo(estado))
    {
        mostrarNivel(nivel);
        printf("*** OBJETIVO ENCONTRADO: %d ***\n", estado);

        return 1;
    }

    // -----------------------------------------------------
    // Verifica se chegou ao limite
    // -----------------------------------------------------
    if (nivel == limite)
    {
        mostrarNivel(nivel);
        printf(">>> LIMITE %d ATINGIDO <<<\n", limite);

        return 0;
    }

    // -----------------------------------------------------
    // Primeiro filho: estado - 5
    // -----------------------------------------------------
    if (estado - 5 > 0)
    {
        mostrarNivel(nivel);
        printf("\nMudando para o Estado: %d - 5 = %d\n",
               estado, estado - 5);

        if (buscaProfundidade(estado - 5,nivel + 1,limite))
        {
            return 1;
        }

        // Voltou do primeiro filho
        mostrarNivel(nivel);
        printf("\n<<< RETORNANDO para o estado %d <<<\n",
               estado);
    }

    // -----------------------------------------------------
    // Segundo filho: estado + 2
    // -----------------------------------------------------
    if (estado + 2 <= 100)
    {
        mostrarNivel(nivel);
        printf("\nMudando para o Estado: %d + 2 = %d\n",
               estado, estado + 2);

        if (buscaProfundidade(estado + 2,nivel + 1,limite))
        {
            return 1;
        }

        // Voltou do segundo filho
        mostrarNivel(nivel);
        printf("\n<<< RETORNANDO para o estado %d <<<\n",
               estado);
    }

    return 0;
}

// ---------------------------------------------------------
// Busca em profundidade limitada iterativa
// ---------------------------------------------------------
int buscaIterativa(int estadoInicial, int limiteMaximo)
{
    int limite;

    for (limite = 0; limite <= limiteMaximo; limite++)
    {
        printf("\n\n");
        printf("==================================================\n");
        printf("        NOVA ITERACAO - LIMITE = %d\n", limite);
        printf("==================================================\n\n");

        if (buscaProfundidade(estadoInicial,0,limite))
        {
            printf("\nSolucao encontrada com limite %d!\n",
                   limite);

            return 1;
        }

        printf("\n");
        printf("--------------------------------------------------\n");
        printf("Fim da busca com limite %d.\n", limite);
        printf("Aumentando o limite...\n");
        printf("--------------------------------------------------\n");
    }

    return 0;
}

// ---------------------------------------------------------
// Programa principal
// ---------------------------------------------------------
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int estadoInicial;
    int limiteMaximo;

    printf("\n\n");
    printf("==================================================\n");
    printf("     BUSCA EM PROFUNDIDADE LIMITADA ITERATIVA\n");
    printf("==================================================\n");

    printf("\nDigite o estado inicial (1-100): ");
    scanf("%d", &estadoInicial);

    if (estadoInicial < 1 || estadoInicial > 100)
    {
        printf("\nEstado inicial invalido!\n");
        return 1;
    }

    printf("Digite o limite maximo: ");
    scanf("%d", &limiteMaximo);

    if (limiteMaximo < 0 || limiteMaximo >= TAM)
    {
        printf("\nLimite invalido!\n");
        return 1;
    }

    printf("\nEstado inicial: %d", estadoInicial);
    printf("\nLimite maximo: %d\n", limiteMaximo);

    // Executa a busca
    if (!buscaIterativa(estadoInicial,limiteMaximo))
    {
        printf("\n");
        printf("==================================================\n");
        printf("Nenhuma solucao encontrada dentro do limite.\n");
        printf("==================================================\n");
    }

    printf("\n");

    return 0;
}
