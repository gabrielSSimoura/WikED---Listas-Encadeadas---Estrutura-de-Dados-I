#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pagina
{
    char *nomePagina;
    char *nomeArquivo;
};

#include "pagina.h"

// inicializa Pagina
Pagina *InicializaPagina(char *nomePagina, char *nomeArquivo)
{
    Pagina *novaPagina = (Pagina *)malloc(sizeof(Pagina));
    novaPagina->nomePagina = strdup(nomePagina);
    novaPagina->nomeArquivo = strdup(nomeArquivo);

    return novaPagina;
}

//Retorna o nome da Pagina desejado;
char *RetornaNomePagina(Pagina *pagina)
{
    return pagina->nomePagina;
}

//Retorna o nome do arquivo da  Pagina desejado;
char *RetornaNomeArquivoPagina(Pagina *pagina)
{
    return pagina->nomeArquivo;
}

//Imprime os dados do Pagina;
void ImprimePagina(FILE *logFile, FILE *fileEntrada, Pagina *pagina)
{
    if (pagina == NULL)
    {
        printf("ERRO: pagina de nome %s não encontrada\n", pagina->nomePagina);
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", pagina->nomePagina);
    }
    printf("%s\n", pagina->nomePagina);
    fprintf(fileEntrada, "%s\n", pagina->nomePagina);
}

//Apaga a Pagina desejado
void ApagaPagina(Pagina *pagina)
{
    if (pagina)
    {
        free(pagina->nomePagina);
        free(pagina->nomeArquivo);
        free(pagina);
    }
}