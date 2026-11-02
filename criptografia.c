#include "criptografia.h"

/*
 * Aplica duas camadas:
 * 1) Cifra de Cesar com SHIFT fixo.
 * 2) Deslocamento adicional da sequencia matematica.
 *
 * Deslocamento total = SHIFT + sequencia[i]
 */
void criptografar(char palavra[], char resultado[], int tamanho,
                  int shift, int sequencia[])
{
    int i;
    int deslocamento;
    int novaPosicao;

    for (i = 0; i < tamanho; i++)
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            deslocamento = shift + sequencia[i];

            /*
             * O operador % 26 faz a letra voltar ao inicio
             * do alfabeto quando ultrapassa Z.
             */
            novaPosicao = (palavra[i] - 'A' + deslocamento) % 26;

            if (novaPosicao < 0)
                novaPosicao += 26;

            resultado[i] = (char)('A' + novaPosicao);
        }
        else
        {
            resultado[i] = palavra[i];
        }
    }

    resultado[tamanho] = '\0';
}
