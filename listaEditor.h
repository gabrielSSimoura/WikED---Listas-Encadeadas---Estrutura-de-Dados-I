#ifndef LISTAEDITOR_H_
#define LISTAEDITOR_H_

#include <stdio.h>

typedef struct celulaEditor CelulaEditor;
typedef struct listaEditor ListaEditor;

#include "editor.h"
#include "listaContribuicao.h"

/*Inicializa uma Lista de Editor;
 *inputs: (void);
 *outputs: TAD (ListaEditor*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (ListaEditor*) de retorno existente;
*/
ListaEditor *IniciaListaEditor();

/*Retorna um TAD ListaContribuicao da Lista de Editor;
 *inputs: TAD (ListaEditor*) e string com nome do editor;
 *outputs: TAD (ListaContribuicao*);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: (ListaContribuicao*) de retorno existente;
*/
ListaContribuicao *RetornaListaContribuicaoListaEditor(ListaEditor *listaEditor, char *nome);

/*Retorna um TAD CelulaEditor da Lista de Editor;
 *inputs: TAD (ListaEditor*) e string com nome do editor;
 *outputs: TAD (CelulaContribuicao*)  ;
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: (CelulaEditor*) de retorno existente;
*/
CelulaEditor *RetornaCelulaEditorListaEditor(ListaEditor *listaEditor, char *nome);

/*Retorna um TAD de Editor da Lista de Editor;
 *inputs: TAD (ListaEditor*) e string com nome do editor ;
 *outputs: TAD (Editor*);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: (Editor*) de retorno existente;
*/
Editor *RetornaEditorListaEditor(ListaEditor *listaEditor, char *nome);

/*Retira uma celula da Lista de Editor;
 *inputs: TAD (ListaEditor*), string com o  nome do editor;
 *outputs: (void);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaContribuição*) modificada;
*/
void RetiraListaEditor(ListaEditor *listaEditor, char *nome);

/*Insere Editor uma celula da Lista de Editor;
 *inputs: TAD (ListaEditor*), (Editor*);
 *outputs: (void);
 *pré-condição TAD (ListaEditor*), (Editor*) existentes: 
 *pós-condição:  Editor adicionado na Celula da Lista de Editor;
*/
void InsereEditorListaEditor(ListaEditor *listaEditor, Editor *editor);

/*Insere Contribuição uma celula da Lista de Editor;
 *inputs: TAD (ListaEditor*), (Contribuicao*), string com o nome do editor;
 *outputs: (void);
 *pré-condição TAD (ListaEditor*), (Contribuicao*) existentes: 
 *pós-condição:  Contribuicao adicionada na Celula da Lista de Editor;
*/
void InsereContribuicaoListaContribuicaoListaEditor(ListaEditor *listaEditor, Contribuicao *contribuicao, char *nome);

/*Verifica pelo nome se o Editor existe ou não na Lista de Editor
 *inputs: TAD (ListaEditor*), string com o nome do editor;
 *outputs: (int);
 *pré-condição: (ListaEditor*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
int BuscaEditorListaEditor(ListaEditor *listaEditor, char *nome);

/*Imprime a Lista de Editor
 *inputs: TAD (ListaEditor*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaEditor*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaEditor*) não modificada;
*/
void ImprimeListaEditor(FILE *paginaFile, FILE *logFile, ListaEditor *listaEditor);

/*Apaga a Lista de Editor;
 *inputs: TAD (ListaEditor*);
 *outputs: (void);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição:  (ListaEditor*) apagada;
*/
void ApagaListaEditor(ListaEditor *listaEditor);

#endif
