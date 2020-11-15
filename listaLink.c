#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celulaLink CelulaLink;

#include "listaLink.h"

struct celulaLink
{
    Pagina *pagina;
    CelulaLink *proxima;
};

struct listaLink
{
    CelulaLink *Prim;
    CelulaLink *Ult;
};

ListaLink *IniciaListaLink()
{
    ListaLink *listaLink = (ListaLink *)malloc(sizeof(ListaLink));
    listaLink->Prim = NULL;
    listaLink->Ult = NULL;

    return listaLink;
}

Pagina *RetornaPaginaListaLink(ListaLink *listaLink, char *nomePagina)
{
    CelulaLink *celulaAtual;

    for (celulaAtual = listaLink->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomePagina(celulaAtual->pagina), nomePagina) == 0)
        {
            return celulaAtual->pagina;
        }
    }
    return NULL;
}

void InsereListaLink(ListaLink *listaLink, Pagina *pagina)
{
    CelulaLink *novaPagina = (CelulaLink *)malloc(sizeof(CelulaLink));
    novaPagina->pagina = pagina;

    // Lista Vazia
    if (listaLink->Prim == NULL)
    {
        listaLink->Prim = novaPagina;
    }

    //Lista Já Existe
    if (listaLink->Ult != NULL)
    {
        listaLink->Ult->proxima = novaPagina;
    }

    listaLink->Ult = novaPagina;
    novaPagina->proxima = NULL;
}

void RetiraListaLink(ListaLink *listaLink, char *nomePagina)
{
    CelulaLink *celulaAtual = listaLink->Prim;
    CelulaLink *celulaAnterior = NULL;

    //faz a busca
    for (celulaAtual = listaLink->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomePagina(celulaAtual->pagina), nomePagina) == 0)
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
    if (celulaAtual == listaLink->Prim && celulaAtual == listaLink->Ult)
    {
        listaLink->Prim = listaLink->Ult = NULL;
    }

    else if (celulaAtual == listaLink->Prim)
    {
        listaLink->Prim = celulaAtual->proxima;
    }

    else if (celulaAtual == listaLink->Ult)
    {
        listaLink->Ult = celulaAnterior;
        listaLink->Ult->proxima = NULL;
    }
    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);
}

void ImprimeListaLink(FILE *logFile, FILE *fileEntrada, ListaLink *listaLink)
{

    if (listaLink == NULL)
    {
        printf("ERRO: pagina não possui lista de Link\n");
        fprintf(logFile, "ERRO: pagina não possui lista de Link\n");
        return;
    }

    CelulaLink *celula;
    printf("\n--> Links\n");
    fprintf(fileEntrada, "\n--> Links\n");

    for (celula = listaLink->Prim; celula != NULL; celula = celula->proxima)
    {
        if (celula)
        {
            printf("%s %s\n", RetornaNomePagina(celula->pagina), RetornaNomeArquivoPagina(celula->pagina));
            fprintf(fileEntrada, "%s %s\n", RetornaNomePagina(celula->pagina), RetornaNomeArquivoPagina(celula->pagina));
        }
    };
}

void ApagaListaLink(ListaLink *listaLink)
{
    CelulaLink *celulaAtual = listaLink->Prim;
    CelulaLink *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;

        if (celulaAtual)
        {
            free(celulaAtual);
        }

        celulaAtual = celulaSeguinte;
    }

    free(listaLink);
}
