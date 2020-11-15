#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPagina.h"

struct celulaPagina
{
    Pagina *pagina;
    ListaContribuicao *listaContribuicao;
    ListaLink *listaLink;
    CelulaPagina *proxima;
};

struct listaPagina
{
    CelulaPagina *Prim;
    CelulaPagina *Ult;
};

ListaPagina *IniciaListaPagina()
{
    ListaPagina *listaPagina = (ListaPagina *)malloc(sizeof(ListaPagina));
    listaPagina->Prim = NULL;
    listaPagina->Ult = NULL;

    return listaPagina;
}

ListaContribuicao *RetornaListaContribuicaoListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->listaContribuicao;
}

ListaLink *RetornaListaLinkListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->listaLink;
}

CelulaPagina *RetornaCelulaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual;

    for (celulaAtual = listaPagina->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomePagina(celulaAtual->pagina), nomePagina) == 0)
        {
            return celulaAtual;
        }
    }

    return NULL;
}

Pagina *RetornaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->pagina;
}

void InsereListaPagina(ListaPagina *listaPagina, Pagina *pagina)
{
    CelulaPagina *novaPagina = (CelulaPagina *)malloc(sizeof(CelulaPagina));
    novaPagina->pagina = pagina;

    novaPagina->listaContribuicao = IniciaListaContribuicao();
    novaPagina->listaLink = IniciaListaLink();

    if (listaPagina->Prim == NULL)
    {
        listaPagina->Prim = novaPagina;
        listaPagina->Ult = novaPagina;
    }
    listaPagina->Ult->proxima = novaPagina;
    listaPagina->Ult = novaPagina;
    novaPagina->proxima = NULL;
};

void RetiraCelulaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual;
    CelulaPagina *celulaAnterior = NULL;

    //faz a busca
    for (celulaAtual = listaPagina->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomePagina(celulaAtual->pagina), nomePagina) == 0)
        {
            break;
        }

        celulaAnterior = celulaAtual;
    }

    // Lista Vazia / Não encontrou
    if (celulaAtual == NULL)
    {
        return;
    }

    // Caso for o único elemento da lista;
    if (celulaAtual == listaPagina->Prim && celulaAtual == listaPagina->Ult)
    {
        listaPagina->Prim = listaPagina->Ult = NULL;
    }

    else if (celulaAtual == listaPagina->Prim)
    {
        listaPagina->Prim = celulaAtual->proxima;
    }

    else if (celulaAtual == listaPagina->Ult)
    {
        listaPagina->Ult = celulaAnterior;
        listaPagina->Ult->proxima = NULL;
    }
    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }
    ApagaListaLink(celulaAtual->listaLink);
    AlteraStatusListaContribuicao(celulaAtual->listaContribuicao);
    ApagaCelulaListaContribuicao(celulaAtual->listaContribuicao);

    free(celulaAtual);
}

void RetiraLinkListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual;

    for (celulaAtual = listaPagina->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        RetiraListaLink(celulaAtual->listaLink, nomePagina);
    }
}

int BuscaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual;

    for (celulaAtual = listaPagina->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {

        if (strcmp(RetornaNomePagina(celulaAtual->pagina), nomePagina) == 0)
        {
            return 1; //Existe Pagina
        }
    }
    return 0; //Não Existe
}

void ImprimeCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina)
{
    CelulaPagina *celulaAtual;

    for (celulaAtual = listaPagina->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        ImprimePaginaCompletaListaPagina(logFile, listaPagina, RetornaNomePagina(celulaAtual->pagina));
    };
}

void ImprimePaginaCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaPagina = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);
    char nomeArquivoPagina[30] = "outputs/";
    strcat(nomeArquivoPagina, RetornaNomeArquivoPagina(celulaPagina->pagina));
    FILE *filePagina = fopen(nomeArquivoPagina, "w");

    if (celulaPagina == NULL)
    {
        printf("ERRO: página de nome %s não encontrada\n", nomePagina);
        fprintf(logFile, "ERRO: página de nome %s não encontrada\n", nomePagina);

        return;
    }

    ImprimePagina(logFile, filePagina, celulaPagina->pagina);
    ImprimeHistoricoListaContribuicao(logFile, filePagina, celulaPagina->listaContribuicao);
    ImprimeListaLink(logFile, filePagina, celulaPagina->listaLink);
    ImprimeListaContribuicao(filePagina, logFile, celulaPagina->listaContribuicao);
    printf("\n");
    fprintf(filePagina, "\n");

    fclose(filePagina);
}

void ApagaListaPagina(ListaPagina *listaPagina)
{
    CelulaPagina *celulaAtual = listaPagina->Prim;
    CelulaPagina *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;
        free(celulaAtual);
        celulaAtual = celulaSeguinte;
    }

    free(listaPagina);
}
