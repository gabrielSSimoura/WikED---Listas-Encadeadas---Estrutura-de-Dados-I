#ifndef LISTACONTRIBUICAO_H_
#define LISTACONTRIBUICAO_H_

#include <stdio.h>

typedef struct celulaContribuicao CelulaContribuicao;
typedef struct listaContribuicao ListaContribuicao;

#include "contribuicao.h"
#include "editor.h"

ListaContribuicao *IniciaListaContribuicao();

Editor *RetornaEditorListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeEditor);

Contribuicao *RetornaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

void InsereListaContribuicao(ListaContribuicao *listaContribuicao, Contribuicao *contribuicao, Editor *editor);

void RetiraCelulaListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

void ImprimeListaContribuicao(FILE *paginaFile, FILE *logFile, ListaContribuicao *listaContribuicao);

void ImprimeHistoricoListaContribuicao(FILE *logFile, FILE *fileEntrada, ListaContribuicao *listaContribuicao);

void AlteraStatusListaContribuicao(ListaContribuicao *listaContribuicao);

int RetornaStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

void AlteraStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

void ApagaCelulaListaContribuicao(ListaContribuicao *listaContribuicao);

void ApagaListaContribuicao(ListaContribuicao *listaContribuicao);

#endif
