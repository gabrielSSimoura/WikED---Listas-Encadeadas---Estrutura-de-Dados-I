#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RETIRADA 1
#define NAORETIRADA 0
#define MAX 30

struct contribuicao
{
    char *nomeArquivo; // Ponteiro para o nome do arquivo da contribuição
    int status;        // RETIRADA, NAORETIRADA;
};

#include "contribuicao.h"

/*Inicializa Contribuição;
 *inputs: nome do Arquivo dessa contribuição;
 *outputs: (Contribuição*) devidamente inicializado e alocado;
 *pré-condição: string existente;
 *pós-condição: (Contribuicao*) de retorno existente;
*/
Contribuicao *InicializaContribuicao(char *nomeArquivo)
{
    Contribuicao *contribuicao = (Contribuicao *)malloc(sizeof(Contribuicao));
    contribuicao->nomeArquivo = strdup(nomeArquivo);
    contribuicao->status = NAORETIRADA; //Define o status

    return contribuicao;
}

/*Retorna o nome do Arquivo de uma Contribuição;
 *inputs: TAD Contribuição existente;
 *outputs: (char*) com o nome da Contribuição;
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: string de retorno existente;
*/
char *RetornaNomeArquivoContribuicao(Contribuicao *contribuicao)
{

    return contribuicao->nomeArquivo;
}

/*Imprime os dados do arquivo de uma Contribuição;
 *inputs: arquivo de log e arquivo da página, nome do Arquivo da contribuição;
 *outputs: (void), arquivo da página com as informações da contribuição gravada nele;
 *pré-condição: arquivos da página e de log existentes;
 *pós-condição: (Contribuicao*) não modificado;
*/
void ImprimeArquivoContribuicao(FILE *logFile, FILE *paginaFile, char *nomeArquivoContribuicao)
{
    char elemento, rota[MAX];
    strcpy(rota, nomeArquivoContribuicao);

    FILE *fileContribuicao = fopen(rota, "r"); //Abre arquivo da contribuiçao para leitura
    if (fileContribuicao == NULL)
    {
        fprintf(logFile, "ERRO: arquivo de nome %s não encontrada\n", nomeArquivoContribuicao);
        return;
    }

    while ((elemento = fgetc(fileContribuicao)) != EOF) //Lê cada caracter do arquivo da contibuição e imprime no arquivo da página
    {
        fputc(elemento, paginaFile);
    }

    fclose(fileContribuicao);
}

/*Retorna o status da Contribuição;
 *inputs: TAD Contribuição existente;
 *outputs: (int) com o valor do status da contribuição (RETIRADA = 1; NAORETIRADA = 0);
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: variável (int) de retorno existente;
*/
int RetornaStatusContribuicao(Contribuicao *contribuicao)
{
    return contribuicao->status;
}

/*Altera o status da Contribuição;
 *inputs: TAD Contribuição existente;
 *outputs: (void);
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: status da contribuição modificado;
*/
void AlteraStatusContribuicao(Contribuicao *contribuicao)
{
    if (RetornaStatusContribuicao(contribuicao) == RETIRADA)
    {
        contribuicao->status = NAORETIRADA;
    }
    else if (RetornaStatusContribuicao(contribuicao) == NAORETIRADA)
    {
        contribuicao->status = RETIRADA;
    }
}

/*Apaga a Contribuição desejada
 *inputs: TAD Contribuição existente;
 *outputs: (void);
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: (Contribuicao*) Apagada;
*/
void ApagaContribuicao(Contribuicao *contribuicao)
{
    if (contribuicao)
    {
        free(contribuicao->nomeArquivo); //Verifica se existe o ponteiro para o nome do arquivo
    }
    free(contribuicao);
}