#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaContribuicao.h"

struct celulaContribuicao
{
    Editor *editor;
    Contribuicao *contribuicao;
    CelulaContribuicao *proxima;
};

struct listaContribuicao
{
    CelulaContribuicao *Prim;
    CelulaContribuicao *Ult;
};

ListaContribuicao *IniciaListaContribuicao()
{
    ListaContribuicao *listaContribuicao = (ListaContribuicao *)malloc(sizeof(ListaContribuicao));
    listaContribuicao->Prim = NULL;
    listaContribuicao->Ult = NULL;

    return listaContribuicao;
}

Editor *RetornaEditorListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeEditor)
{
    CelulaContribuicao *celulaAtual;

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeEditor(celulaAtual->editor), nomeEditor) == 0)
        {
            return celulaAtual->editor;
        }
    }

    return NULL;
}

Contribuicao *RetornaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual = RetornaCelulaContribuicaoListaContribuicao(listaContribuicao, nomeArquivo);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->contribuicao;
}

CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual;

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeArquivoContribuicao(celulaAtual->contribuicao), nomeArquivo) == 0)
        {
            return celulaAtual;
        }
    }

    return NULL;
}

void InsereListaContribuicao(ListaContribuicao *listaContribuicao, Contribuicao *contribuicao, Editor *editor)
{
    CelulaContribuicao *novaContribucao = (CelulaContribuicao *)malloc(sizeof(CelulaContribuicao));
    novaContribucao->contribuicao = contribuicao;
    novaContribucao->editor = editor;

    // Lista Vazia
    if (listaContribuicao->Prim == NULL)
    {

        listaContribuicao->Prim = novaContribucao;
        listaContribuicao->Ult = novaContribucao;
    }

    listaContribuicao->Ult->proxima = novaContribucao;
    listaContribuicao->Ult = novaContribucao;
    novaContribucao->proxima = NULL;
}

void RetiraCelulaListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual = listaContribuicao->Prim;
    CelulaContribuicao *celulaAnterior = NULL;

    //faz a busca
    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeArquivoContribuicao(celulaAtual->contribuicao), nomeArquivo) == 0)
        {
            break;
        }

        celulaAnterior = celulaAtual;
    }

    if (celulaAtual == NULL)
    {
        return;
    }

    // Caso for o único elemento da lista;
    if (celulaAtual == listaContribuicao->Prim && celulaAtual == listaContribuicao->Ult)
    {
        listaContribuicao->Prim = listaContribuicao->Ult = NULL;
    }

    else if (celulaAtual == listaContribuicao->Prim)
    {
        listaContribuicao->Prim = celulaAtual->proxima;
    }

    else if (celulaAtual == listaContribuicao->Ult)
    {
        listaContribuicao->Ult = celulaAnterior;
        listaContribuicao->Ult->proxima = NULL;
    }
    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);
}

void ImprimeListaContribuicao(FILE *paginaFile, FILE *logFile, ListaContribuicao *listaContribuicao)
{

    if (listaContribuicao == NULL)
    {
        printf("ERRO: pagina não possui Lista de Contribuições\n");
        fprintf(logFile, "ERRO: pagina não possui Lista de Contribuições\n");
        return;
    }

    CelulaContribuicao *celula;

    printf("\n--> Textos\n");
    fprintf(paginaFile, "\n--> Textos\n");

    for (celula = listaContribuicao->Prim; celula != NULL; celula = celula->proxima)
    {
        if (RetornaStatusContribuicao(celula->contribuicao))
        {
            continue;
        }

        printf("\n-------- %s (%s) --------\n\n", RetornaNomeArquivoContribuicao(celula->contribuicao), RetornaNomeEditor(celula->editor));
        fprintf(paginaFile, "\n-------- %s (%s) --------\n\n", RetornaNomeArquivoContribuicao(celula->contribuicao), RetornaNomeEditor(celula->editor));
        ImprimeArquivoContribuicao(logFile, paginaFile, RetornaNomeArquivoContribuicao(celula->contribuicao));
        printf("\n");
        fprintf(paginaFile, "\n");
    };
}

void ImprimeHistoricoListaContribuicao(FILE *logFile, FILE *fileEntrada, ListaContribuicao *listaContribuicao)
{

    if (listaContribuicao == NULL)
    {
        printf("ERRO: pagina não possui histórico de Contribuições\n");
        fprintf(logFile, "ERRO: pagina não possui histórico de Contribuições\n");
        return;
    }

    CelulaContribuicao *celulaAtual;

    printf("\n--> Historico de contribuicoes\n");
    fprintf(fileEntrada, "\n--> Historico de contribuicoes\n");

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {

        printf("%s %s", RetornaNomeEditor(celulaAtual->editor), RetornaNomeArquivoContribuicao(celulaAtual->contribuicao));
        fprintf(fileEntrada, "%s %s", RetornaNomeEditor(celulaAtual->editor), RetornaNomeArquivoContribuicao(celulaAtual->contribuicao));

        if (RetornaStatusContribuicao(celulaAtual->contribuicao))
        {
            printf(" <<retirada>>\n");
            fprintf(fileEntrada, " <<retirada>>\n");
        }
        else
        {
            printf("\n");
            fprintf(fileEntrada, "\n");
        }
    }
}

void AlteraStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual = RetornaCelulaContribuicaoListaContribuicao(listaContribuicao, nomeArquivo);

    if (celulaAtual == NULL)
    {
        return;
    }

    AlteraStatusContribuicao(celulaAtual->contribuicao);
}

void AlteraStatusListaContribuicao(ListaContribuicao *listaContribuicao)
{
    CelulaContribuicao *celulaAtual;

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {

        AlteraStatusContribuicao(celulaAtual->contribuicao);
    }
}

int RetornaStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual = RetornaCelulaContribuicaoListaContribuicao(listaContribuicao, nomeArquivo);

    if (celulaAtual == NULL)
    {
        return 2;
    }

    return (RetornaStatusContribuicao(celulaAtual->contribuicao));
}

void ApagaCelulaListaContribuicao(ListaContribuicao *listaContribuicao)
{

    CelulaContribuicao *celulaAtual = listaContribuicao->Prim;
    CelulaContribuicao *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;

        if (celulaAtual)
        {
            free(celulaAtual);
        }
        celulaAtual = celulaSeguinte;
    }

    free(listaContribuicao);
}

void ApagaListaContribuicao(ListaContribuicao *listaContribuicao)

{
    CelulaContribuicao *celulaAtual = listaContribuicao->Prim;
    CelulaContribuicao *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;

        if (celulaAtual)
        {
            if (celulaAtual->contribuicao)
            {
                ApagaContribuicao(celulaAtual->contribuicao);
            }
            free(celulaAtual);
        }
        celulaAtual = celulaSeguinte;
    }

    free(listaContribuicao);
}
