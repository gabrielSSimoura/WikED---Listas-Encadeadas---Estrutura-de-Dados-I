#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*Inicializa uma Lista de Link;
 *inputs: (void);
 *outputs: TAD (LinstaLink*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (LinstaLink*) de retorno existente;
*/
ListaLink *IniciaListaLink()
{
    ListaLink *listaLink = (ListaLink *)malloc(sizeof(ListaLink));
    listaLink->Prim = NULL;
    listaLink->Ult = NULL;

    return listaLink;
}

/*Retorna um TAD Pagina da Lista de Link;
 *inputs: TAD (ListaLink*) e string com nome da página ;
 *outputs: TAD (Pagina*);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição: (Pagina*) de retorno existente;
*/
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

/*Retorna uma celula da Lista de Link;
 *inputs: TAD (ListaLink*) e string com nome da página ;
 *outputs: TAD (CelulaLink*);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição: (CelulaLink*) de retorno existente;
*/
CelulaLink *RetornaCelulaLinkListaLink(ListaLink *listaLink, char *nomePagina)
{
    CelulaLink *celulaAtual;

    for (celulaAtual = listaLink->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomePagina(celulaAtual->pagina), nomePagina) == 0)
        {
            return celulaAtual;
        }
    }
    return NULL;
}

/*Verifica pelo nome se a Pagina existe ou não na Lista de LInk
 *inputs: TAD (ListaLink*), string com o nome da pagina;
 *outputs: (int);
 *pré-condição: (ListaLink*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
int BuscaLinkListaLink(ListaLink *listaLink, char *nomeLink)
{
    CelulaLink *celulaAtual;

    for (celulaAtual = listaLink->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomePagina(celulaAtual->pagina), nomeLink) == 0)
        {
            return 1; //Existe
        }
    }
    return 0; //Não existe
}

/*Insere Pagina uma celula da Lista de Link;
 *inputs: TAD (ListaLink*), (Pagina*);
 *outputs: (void);
 *pré-condição TAD (ListaLink*), (Pagina*) existentes: 
 *pós-condição:  Pagina adicionado na Celula da Lista de Link;
*/
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

/*Retira uma celula da Lista de Link;
 *inputs: TAD (ListaLink*), string com o  nome da Pagina;
 *outputs: (void);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaLink*) modificada;
*/
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

/*Imprime a Lista de Link
 *inputs: TAD (ListaLink*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaLink*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaLink*) não modificada;
*/
void ImprimeListaLink(FILE *logFile, FILE *fileEntrada, ListaLink *listaLink)
{

    if (listaLink == NULL)
    {
        fprintf(logFile, "ERRO: pagina não possui lista de Link\n");
        return;
    }

    CelulaLink *celula;
    fprintf(fileEntrada, "\n--> Links\n");

    for (celula = listaLink->Prim; celula != NULL; celula = celula->proxima)
    {
        if (celula)
        {
            fprintf(fileEntrada, "%s %s\n", RetornaNomePagina(celula->pagina), RetornaNomeArquivoPagina(celula->pagina));
        }
    };
}

/*Busca os Caminhos na Lista de Link;
 *inputs: TAD (ListaLink*), (ListaPagina*), (Pagina*);
 *outputs: (void);
 *pré-condição TAD (ListaLink*), (ListaPagina*) e (Pagina*) existentes: 
 *pós-condição:  verificaçao se há caminho ou não de uma página à outra;
*/
void CaminhoListaLink(ListaPagina *listaPagina, ListaLink *paginasPercorridas, Pagina *paginaAtual)
{
    //Insere a pagina atual na lista de links das paginas percorridas;
    InsereListaLink(paginasPercorridas, paginaAtual);

    //Retorna lista de links da página atual;
    ListaLink *novaListaLink = RetornaListaLinkListaPagina(listaPagina, RetornaNomePagina(paginaAtual));
    CelulaLink *celulaAtual;

    //Faz a busca
    for (celulaAtual = novaListaLink->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        //Se não encontrar a pagina na lista de percorridas, então ela é adicionada;
        if (RetornaCelulaLinkListaLink(paginasPercorridas, RetornaNomePagina(celulaAtual->pagina)) == NULL)
        {
            CaminhoListaLink(listaPagina, paginasPercorridas, celulaAtual->pagina);
        }
    }
}

/*Apaga a Lista de Link;
 *inputs: TAD (ListaLink*);
 *outputs: (void);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição:  (ListaLink*) apagada;
*/
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
