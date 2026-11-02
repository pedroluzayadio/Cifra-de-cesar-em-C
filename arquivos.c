#include <stdio.h>
#include <time.h>
#include "arquivos.h"

char* nomeSequencia(int tipo)
{
    switch (tipo)
    {
        case 1:
            return "Progressao Aritmetica";
        case 2:
            return "Progressao Geometrica";
        case 3:
            return "Fibonacci";
        case 4:
            return "Numeros Primos";
        default:
            return "Desconhecida";
    }
}

void salvarResultado(char palavra[], char resultado[],
                     int shift, int tipo, int tamanho)
{
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo de resultado.\n");
        return;
    }

    fprintf(arquivo, "===== RESULTADO DA CRIPTOGRAFIA =====\n\n");
    fprintf(arquivo, "Palavra original: %s\n", palavra);
    fprintf(arquivo, "Palavra codificada: %s\n", resultado);
    fprintf(arquivo, "SHIFT: %d\n", shift);
    fprintf(arquivo, "Tipo de sequencia: %s\n", nomeSequencia(tipo));
    fprintf(arquivo, "Quantidade de letras: %d\n", tamanho);

    fclose(arquivo);
}

void salvarLog(char palavra[], char resultado[],
               int shift, int tipo, int tamanho)
{
    FILE *arquivo = fopen("log_execucao.txt", "a");
    time_t agora;
    struct tm *tempoAtual;

    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo de log.\n");
        return;
    }

    agora = time(NULL);
    tempoAtual = localtime(&agora);

    fprintf(arquivo, "\n========================================\n");
    fprintf(arquivo, "DATA: %02d/%02d/%04d %02d:%02d:%02d\n",
            tempoAtual->tm_mday,
            tempoAtual->tm_mon + 1,
            tempoAtual->tm_year + 1900,
            tempoAtual->tm_hour,
            tempoAtual->tm_min,
            tempoAtual->tm_sec);

    fprintf(arquivo, "Palavra original: %s\n", palavra);
    fprintf(arquivo, "SHIFT: %d\n", shift);
    fprintf(arquivo, "Sequencia: %s\n", nomeSequencia(tipo));
    fprintf(arquivo, "Resultado: %s\n", resultado);
    fprintf(arquivo, "Quantidade de letras: %d\n", tamanho);
    fprintf(arquivo, "========================================\n");

    fclose(arquivo);
}

void visualizarResultado(void)
{
    FILE *arquivo = fopen("resultado_criptografia.txt", "r");
    char linha[200];

    if (arquivo == NULL)
    {
        printf("\nNenhum resultado encontrado.\n");
        return;
    }

    printf("\n===== ULTIMO RESULTADO =====\n\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
        printf("%s", linha);

    fclose(arquivo);
}

void visualizarLog(void)
{
    FILE *arquivo = fopen("log_execucao.txt", "r");
    char linha[200];

    if (arquivo == NULL)
    {
        printf("\nNenhum log encontrado.\n");
        return;
    }

    printf("\n===== LOG DE EXECUCAO =====\n\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
        printf("%s", linha);

    fclose(arquivo);
}
