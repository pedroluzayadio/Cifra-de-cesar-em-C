#include "sequencias.h"

static int ehPrimo(int numero)
{
    int i;

    if (numero < 2)
        return 0;

    for (i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
            return 0;
    }

    return 1;
}

void gerarPA(int sequencia[], int tamanho, int primeiro, int razao)
{
    int i;

    for (i = 0; i < tamanho; i++)
        sequencia[i] = primeiro + i * razao;
}

void gerarPG(int sequencia[], int tamanho, int primeiro, int razao)
{
    int i;

    if (tamanho <= 0)
        return;

    sequencia[0] = primeiro;

    for (i = 1; i < tamanho; i++)
        sequencia[i] = sequencia[i - 1] * razao;
}

void gerarFibonacci(int sequencia[], int tamanho)
{
    int i;

    if (tamanho >= 1)
        sequencia[0] = 1;

    if (tamanho >= 2)
        sequencia[1] = 1;

    for (i = 2; i < tamanho; i++)
        sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
}

void gerarPrimos(int sequencia[], int tamanho)
{
    int numero = 2;
    int quantidade = 0;

    while (quantidade < tamanho)
    {
        if (ehPrimo(numero))
        {
            sequencia[quantidade] = numero;
            quantidade++;
        }

        numero++;
    }
}
