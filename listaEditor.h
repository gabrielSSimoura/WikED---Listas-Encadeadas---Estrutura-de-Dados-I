#ifndef LISTAEDITOR_H_
#define LISTAEDITOR_H_

#include <stdio.h>

typedef struct celulaEditor CelulaEditor;
typedef struct listaEditor ListaEditor;

#include "editor.h"
#include "listaContribuicao.h"

ListaEditor *IniciaListaEditor();

ListaContribuicao *RetornaListaContribuicaoListaEditor(ListaEditor *listaEditor, char *nome);

CelulaEditor *RetornaCelulaEditorListaEditor(ListaEditor *listaEditor, char *nome);

Editor *RetornaEditorListaEditor(ListaEditor *listaEditor, char *nome);

void RetiraListaEditor(ListaEditor *listaEditor, char *nome);

void InsereEditorListaEditor(ListaEditor *listaEditor, Editor *editor);

void InsereContribuicaoListaContribuicaoListaEditor(ListaEditor *listaEditor, Contribuicao *contribuicao, char *nome);

int BuscaEditorListaEditor(ListaEditor *listaEditor, char *nome);

void ImprimeListaEditor(FILE *paginaFile, FILE *logFile, ListaEditor *listaEditor);

void ApagaListaEditor(ListaEditor *listaEditor);

#endif
