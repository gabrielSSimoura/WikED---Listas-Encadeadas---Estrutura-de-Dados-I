#ifndef LISTAPAGINA_H_
#define LISTAPAGINA_H_

typedef struct celulaPagina CelulaPagina;
typedef struct listaPagina ListaPagina;

#include "pagina.h"
#include "listaContribuicao.h"
#include "listaLink.h"

ListaPagina *IniciaListaPagina();

ListaContribuicao *RetornaListaContribuicaoListaPagina(ListaPagina *listaPagina, char *nomePagina);

CelulaPagina *RetornaCelulaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

ListaLink *RetornaListaLinkListaPagina(ListaPagina *listaPagina, char *nomePagina);

Pagina *RetornaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

void RetiraCelulaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

void RetiraLinkListaPagina(ListaPagina *listaPagina, char *nomePagina);

void InsereListaPagina(ListaPagina *listaPagina, Pagina *pagina);

int BuscaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

void ImprimeCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina);

void ImprimePaginaCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina, char *nomePagina);

void ApagaListaPagina(ListaPagina *listaPagina);

#endif
//Verifica
//Retorna Celula