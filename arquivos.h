#ifndef ARQUIVOS_H
#define ARQUIVOS_H

char* nomeSequencia(int tipo);

void salvarResultado(char palavra[], char resultado[], int shift,
                     int tipo, int tamanho);

void salvarLog(char palavra[], char resultado[], int shift,
               int tipo, int tamanho);

void visualizarResultado(void);
void visualizarLog(void);

#endif
