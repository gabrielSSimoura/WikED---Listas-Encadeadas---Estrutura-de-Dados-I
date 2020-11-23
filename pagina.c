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

/*Inicializa Pagina;
 *inputs: nome do Arquivo dessa Pagina;
 *outputs: (Pagina*) devidamente inicializada e alocada;
 *pré-condição: string existente;
 *pós-condição: (Pagina*) de retorno existente;
*/
Pagina *InicializaPagina(char *nomePagina, char *nomeArquivo)
{
    Pagina *novaPagina = (Pagina *)malloc(sizeof(Pagina));
    novaPagina->nomePagina = strdup(nomePagina);
    novaPagina->nomeArquivo = strdup(nomeArquivo);

    return novaPagina;
}

/*Retorna o nome de uma Pagina;
 *inputs: TAD Pagina existente;
 *outputs: (char*) com o nome da Pagina;
 *pré-condição: (Pagina*) existente, com string nome existente;
 *pós-condição: (Pagina*) não modificado;
*/
char *RetornaNomePagina(Pagina *pagina)
{
    return pagina->nomePagina;
}

/*Retorna o nome do arquivo de uma Pagina;
 *inputs: TAD Pagina existente;
 *outputs: (char*) com o nome do arquivo de uma Pagina;
 *pré-condição: (Pagina*) existente, com string arquivo existente;
 *pós-condição: (Pagina*) não modificado, string de retorno existente;
*/
char *RetornaNomeArquivoPagina(Pagina *pagina)
{
    return pagina->nomeArquivo;
}

/*Imprime a Pagina desejada
 *inputs: TAD Pagina existente, arquivo da Página, arquivo de log;
 *outputs: (void);
 *pré-condição: (Pagina*), arquivo da Página, arquivo de log, existentes;
 *pós-condição: (Pagina*) não modificado;
*/
void ImprimePagina(FILE *logFile, FILE *fileEntrada, Pagina *pagina)
{
    if (pagina == NULL)
    {
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", pagina->nomePagina);
    }
    fprintf(fileEntrada, "%s\n", pagina->nomePagina);
}

/*Apaga a pagina desejada
 *inputs: TAD pagina existente;
 *outputs: (void) - pagina Apagada;
 *pré-condição: (Pagina*) existente;
 *pós-condição: (Pagina*) Apagada;
*/
void ApagaPagina(Pagina *pagina)
{
    if (pagina)
    {

        if (pagina->nomePagina)
        {
            free(pagina->nomePagina);
        }
        if (pagina->nomeArquivo)
        {
            free(pagina->nomeArquivo);
        }

        free(pagina);
    }
}