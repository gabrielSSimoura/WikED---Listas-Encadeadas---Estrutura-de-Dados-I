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

/*Inicializa uma Lista de Pagina;
 *inputs: (void);
 *outputs: TAD (LinstaPagina*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (LinstaPagina*) de retorno existente;
*/
ListaPagina *IniciaListaPagina()
{
    ListaPagina *listaPagina = (ListaPagina *)malloc(sizeof(ListaPagina));
    listaPagina->Prim = NULL;
    listaPagina->Ult = NULL;

    return listaPagina;
}

/*Retorna um TAD ListaContribuicao da Lista de Pagina;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (ListaContribuicao*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (ListaContribuicao*) de retorno existente;
*/
ListaContribuicao *RetornaListaContribuicaoListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->listaContribuicao;
}

/*Retorna um TAD ListaLink da Lista de Pagina;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (ListaLink*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (ListaLink*) de retorno existente;
*/
ListaLink *RetornaListaLinkListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->listaLink;
}

/*Retorna um TAD CelulaPagina da Lista de Link;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (CelulaPagina*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (CelulaPagina*) de retorno existente;
*/
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

/*Retorna um TAD Pagina da Lista de Pagina;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (Pagina*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (Pagina*) de retorno existente;
*/
Pagina *RetornaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->pagina;
}

/*Insere Pagina uma celula da Lista de Pagina;
 *inputs: TAD (ListaPagina*), (Pagina*);
 *outputs: (void);
 *pré-condição TAD (ListaPagina*), (Pagina*) existentes: 
 *pós-condição:  Pagina adicionado na Celula da Lista de Pagina;
*/
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

/*Retira uma celula da Lista de Pagina;
 *inputs: TAD (ListaPagina*), string com o  nome da Pagina;
 *outputs: (void);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaPagina*) modificada;
*/
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
    ApagaListaContribuicao(celulaAtual->listaContribuicao);

    free(celulaAtual);
}

/*Retira uma Pagina da lista de Link da Lista de Pagina;
 *inputs: TAD (ListaPagina*), string com o nome da Pagina;
 *outputs: (void);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: Pagina da Lista de Link da Lista de Pagina retirada, (ListaPagina*) modificada;
*/
void RetiraLinkListaPagina(ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaAtual;

    for (celulaAtual = listaPagina->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        RetiraListaLink(celulaAtual->listaLink, nomePagina);
    }
}

/*Verifica pelo nome se a Pagina existe ou não na Lista de Pagina
 *inputs: TAD (ListaPagina*), string com o nome da pagina;
 *outputs: (int);
 *pré-condição: (ListaPagina*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
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

/*Percorre a Lista Imprimindo as paginas da lista de pagina
 *inputs: TAD (ListaPagina*) existente, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaPagina* e arquivo de log existentes;
 *pós-condição: (ListaPagina*) não modificada;
*/
void ImprimeCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina)
{
    CelulaPagina *celulaAtual;

    for (celulaAtual = listaPagina->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        ImprimePaginaCompletaListaPagina(logFile, listaPagina, RetornaNomePagina(celulaAtual->pagina));
    };
}

/*Imprime uma pagina da lista de pagina com todos os seus dados
 *inputs: TAD (ListaPagina*) existente, arquivo de log, nome da paginaa;
 *outputs: (void);
 *pré-condição: (ListaPagina* e arquivo de log existentes;
 *pós-condição: (ListaPagina*) não modificada;
*/
void ImprimePaginaCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina, char *nomePagina)
{
    CelulaPagina *celulaPagina = RetornaCelulaPaginaListaPagina(listaPagina, nomePagina);
    char nomeArquivoPagina[30];
    strcpy(nomeArquivoPagina, RetornaNomeArquivoPagina(celulaPagina->pagina));
    FILE *filePagina = fopen(nomeArquivoPagina, "w");

    if (celulaPagina == NULL)
    {
        fprintf(logFile, "ERRO: página de nome %s não encontrada\n", nomePagina);

        return;
    }

    ImprimePagina(logFile, filePagina, celulaPagina->pagina);
    ImprimeHistoricoListaContribuicao(logFile, filePagina, celulaPagina->listaContribuicao);
    ImprimeListaLink(logFile, filePagina, celulaPagina->listaLink);
    ImprimeListaContribuicao(filePagina, logFile, celulaPagina->listaContribuicao);

    fclose(filePagina);
}

/*Apaga a Lista de Pagina;
 *inputs: TAD (ListaPagina*);
 *outputs: (void);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição:  (ListaPagina*) apagada;
*/
void ApagaListaPagina(ListaPagina *listaPagina)
{
    CelulaPagina *celulaAtual = listaPagina->Prim;
    CelulaPagina *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;

        if (celulaAtual)
        {
            if (celulaAtual->listaContribuicao)
            {
                ApagaListaContribuicao(celulaAtual->listaContribuicao);
            }
            if (celulaAtual->listaLink)
            {
                ApagaListaLink(celulaAtual->listaLink);
            }
            if (celulaAtual->pagina)
            {
                ApagaPagina(celulaAtual->pagina);
            }
            free(celulaAtual);
        }
        celulaAtual = celulaSeguinte;
    }

    free(listaPagina);
}
