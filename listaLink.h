#ifndef LISTALINK_H_
#define LISTALINK_H_

#include <stdio.h>

typedef struct listaLink ListaLink;

#include "pagina.h"

ListaLink *IniciaListaLink();

Pagina *RetornaPaginaListaLink(ListaLink *listaLink, char *nomePagina);

int BuscaLinkListaLink(ListaLink *listaLink, char *nomeLink);

void RetiraListaLink(ListaLink *listaLink, char *nomePagina);

void InsereListaLink(ListaLink *listaLink, Pagina *pagina);

void ImprimeListaLink(FILE *logFile, FILE *fileEntrada, ListaLink *listaLink);

void ApagaListaLink(ListaLink *listaLink);

#endif
