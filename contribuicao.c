#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RETIRADA 1
#define NAORETIRADA 0
#define MAX 30

struct contribuicao
{
    char *nomeArquivo;
    int status; // RETIRADA, NAORETIRADA;
};

#include "contribuicao.h"

// inicializa Contribuicao
Contribuicao *InicializaContribuicao(char *nomeArquivo)
{
    Contribuicao *contribuicao = (Contribuicao *)malloc(sizeof(Contribuicao));
    contribuicao->nomeArquivo = strdup(nomeArquivo);
    contribuicao->status = NAORETIRADA;

    return contribuicao;
}

//Imprime os dados da Contribuicao;
void ImprimeContribuicao(Contribuicao *contribuicao)
{
    if (RetornaStatusContribuicao(contribuicao) == NAORETIRADA && contribuicao)
    {
        printf("%s\n", RetornaNomeArquivoContribuicao(contribuicao));
        //printf("%s\n", RetornaTextoContribuicao(contribuicao));
    }
}

//Retorna o nome do arquivo da Contribuição;
char *RetornaNomeArquivoContribuicao(Contribuicao *contribuicao)
{
    return contribuicao->nomeArquivo;
}

//Imprime a Contribuição no arquivo da pagina;
void ImprimeArquivoContribuicao(FILE *logFile, FILE *paginaFile, char *nomeArquivoContribuicao)
{
    char elemento, rota[MAX] = "inputs/";
    strcat(rota, nomeArquivoContribuicao);

    FILE *fileContribuicao = fopen(rota, "r");
    if (fileContribuicao == NULL)
    {
        printf("ERRO: arquivo de nome %s não encontrada\n", nomeArquivoContribuicao);
        fprintf(logFile, "ERRO: arquivo de nome %s não encontrada\n", nomeArquivoContribuicao);
        return;
    }

    while ((elemento = fgetc(fileContribuicao)) != EOF)
    {
        fputc(elemento, paginaFile);
        printf("%c", elemento);
    }

    fclose(fileContribuicao);
}

//Retorna o status da Contribuição;
int RetornaStatusContribuicao(Contribuicao *contribuicao)
{
    return contribuicao->status;
}

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

//Apaga a Contribuição desejada
void ApagaContribuicao(Contribuicao *contribuicao)
{
    if (contribuicao)
    {

        free(contribuicao->nomeArquivo);

        free(contribuicao);
    }
}