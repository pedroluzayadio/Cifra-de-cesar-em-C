#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "criptografia.h"
#include "sequencias.h"
#include "arquivos.h"

#define MAX_LETRAS 15

void limparBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void converterMaiusculas(char palavra[])
{
    int i;
    for (i = 0; palavra[i] != '\0'; i++)
        palavra[i] = (char)toupper((unsigned char)palavra[i]);
}

int palavraValida(char palavra[])
{
    int i;
    for (i = 0; palavra[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)palavra[i]))
            return 0;
    }
    return 1;
}

void mostrarMenu(void)
{
    printf("\n========================================\n");
    printf("       SISTEMA DE CRIPTOGRAFIA          \n");
    printf("========================================\n");
    printf("1 - Criptografar palavra\n");
    printf("2 - Gerar sequencia matematica\n");
    printf("3 - Visualizar ultimo resultado\n");
    printf("4 - Visualizar log de execucao\n");
    printf("5 - Sair\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");
}

int main(void)
{
    int opcao;
    int shift;
    int tipo;
    int tamanho;
    int sequencia[MAX_LETRAS];
    char palavra[MAX_LETRAS + 1];
    char resultado[MAX_LETRAS + 1];

    do
    {
        mostrarMenu();

        if (scanf("%d", &opcao) != 1)
        {
            printf("\nEntrada invalida.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (opcao)
        {
            case 1:
                printf("\nDigite uma palavra de ate 15 letras: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = '\0';

                tamanho = (int)strlen(palavra);

                if (tamanho < 1 || tamanho > MAX_LETRAS)
                {
                    printf("\nErro: a palavra deve possuir entre 1 e 15 letras.\n");
                    break;
                }

                if (!palavraValida(palavra))
                {
                    printf("\nErro: utilize somente letras, sem acentos ou caracteres especiais.\n");
                    break;
                }

                converterMaiusculas(palavra);

                printf("Digite o valor do SHIFT: ");
                if (scanf("%d", &shift) != 1)
                {
                    printf("\nSHIFT invalido.\n");
                    limparBuffer();
                    break;
                }

                printf("\nEscolha a sequencia matematica:\n");
                printf("1 - Progressao Aritmetica (PA)\n");
                printf("2 - Progressao Geometrica (PG)\n");
                printf("3 - Fibonacci\n");
                printf("4 - Numeros Primos\n");
                printf("Opcao: ");

                if (scanf("%d", &tipo) != 1)
                {
                    printf("\nOpcao invalida.\n");
                    limparBuffer();
                    break;
                }

                switch (tipo)
                {
                    case 1:
                        gerarPA(sequencia, tamanho, 1, 2);
                        break;
                    case 2:
                        gerarPG(sequencia, tamanho, 1, 2);
                        break;
                    case 3:
                        gerarFibonacci(sequencia, tamanho);
                        break;
                    case 4:
                        gerarPrimos(sequencia, tamanho);
                        break;
                    default:
                        printf("\nOpcao de sequencia invalida.\n");
                        continue;
                }

                criptografar(palavra, resultado, tamanho, shift, sequencia);

                printf("\n===== RESULTADO =====\n");
                printf("Palavra original: %s\n", palavra);
                printf("SHIFT: %d\n", shift);
                printf("Tipo de sequencia: %s\n", nomeSequencia(tipo));
                printf("Sequencia utilizada: ");

                for (int i = 0; i < tamanho; i++)
                {
                    printf("%d", sequencia[i]);
                    if (i < tamanho - 1)
                        printf(", ");
                }

                printf("\nPalavra criptografada: %s\n", resultado);

                salvarResultado(palavra, resultado, shift, tipo, tamanho);
                salvarLog(palavra, resultado, shift, tipo, tamanho);

                printf("\nResultado salvo com sucesso!\n");
                break;

            case 2:
                printf("\nDigite a quantidade de termos (1 a 15): ");
                if (scanf("%d", &tamanho) != 1)
                {
                    printf("\nQuantidade invalida.\n");
                    limparBuffer();
                    break;
                }

                if (tamanho < 1 || tamanho > MAX_LETRAS)
                {
                    printf("\nQuantidade invalida. Use entre 1 e 15.\n");
                    break;
                }

                printf("\nEscolha a sequencia:\n");
                printf("1 - Progressao Aritmetica\n");
                printf("2 - Progressao Geometrica\n");
                printf("3 - Fibonacci\n");
                printf("4 - Numeros Primos\n");
                printf("Opcao: ");

                if (scanf("%d", &tipo) != 1)
                {
                    printf("\nOpcao invalida.\n");
                    limparBuffer();
                    break;
                }

                switch (tipo)
                {
                    case 1:
                        gerarPA(sequencia, tamanho, 1, 2);
                        break;
                    case 2:
                        gerarPG(sequencia, tamanho, 1, 2);
                        break;
                    case 3:
                        gerarFibonacci(sequencia, tamanho);
                        break;
                    case 4:
                        gerarPrimos(sequencia, tamanho);
                        break;
                    default:
                        printf("\nOpcao invalida.\n");
                        continue;
                }

                printf("\nSequencia gerada: ");
                for (int i = 0; i < tamanho; i++)
                {
                    printf("%d", sequencia[i]);
                    if (i < tamanho - 1)
                        printf(", ");
                }
                printf("\n");
                break;

            case 3:
                visualizarResultado();
                break;

            case 4:
                visualizarLog();
                break;

            case 5:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
