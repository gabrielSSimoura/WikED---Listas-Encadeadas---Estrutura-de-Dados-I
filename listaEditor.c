#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEditor.h"

struct celulaEditor
{
    Editor *editor;
    ListaContribuicao *listaContribuicao;
    CelulaEditor *proxima;
};

struct listaEditor
{
    CelulaEditor *Prim;
    CelulaEditor *Ult;
};

/*Inicializa uma Lista de Editor;
 *inputs: (void);
 *outputs: TAD (ListaEditor*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (ListaEditor*) de retorno existente;
*/
ListaEditor *IniciaListaEditor()
{
    ListaEditor *listaEditor = (ListaEditor *)malloc(sizeof(ListaEditor));
    listaEditor->Prim = NULL;
    listaEditor->Ult = NULL;

    return listaEditor;
}

/*Retorna um TAD ListaContribuicao da Lista de Editor;
 *inputs: TAD (ListaEditor*) e string com nome do editor;
 *outputs: TAD (ListaContribuicao*);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: (ListaContribuicao*) de retorno existente;
*/
ListaContribuicao *RetornaListaContribuicaoListaEditor(ListaEditor *listaEditor, char *nome)
{
    CelulaEditor *celulaAtual = RetornaCelulaEditorListaEditor(listaEditor, nome);

    if (celulaAtual)
    {
        return celulaAtual->listaContribuicao;
    }
    else
    {
        return NULL;
    }
}

/*Retorna um TAD CelulaEditor da Lista de Editor;
 *inputs: TAD (ListaEditor*) e string com nome do editor;
 *outputs: TAD (CelulaContribuicao*)  ;
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: (CelulaEditor*) de retorno existente;
*/
CelulaEditor *RetornaCelulaEditorListaEditor(ListaEditor *listaEditor, char *nome)
{
    CelulaEditor *celulaAtual;

    //faz a busca
    for (celulaAtual = listaEditor->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeEditor(celulaAtual->editor), nome) == 0)
        {
            return celulaAtual; //Existe Editor;
        }
    }
    return NULL; //Não Existe Editor com esse nome;
}

/*Retorna um TAD de Editor da Lista de Editor;
 *inputs: TAD (ListaEditor*) e string com nome do editor ;
 *outputs: TAD (Editor*);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: (Editor*) de retorno existente;
*/
Editor *RetornaEditorListaEditor(ListaEditor *listaEditor, char *nome)
{
    CelulaEditor *celulaAtual = RetornaCelulaEditorListaEditor(listaEditor, nome);

    if (celulaAtual)
    {
        return celulaAtual->editor;
    }
    else
    {
        return NULL;
    }
}

/*Insere Contribuição uma celula da Lista de Editor;
 *inputs: TAD (ListaEditor*), (Contribuicao*), string com o nome do editor;
 *outputs: (void);
 *pré-condição TAD (ListaEditor*), (Contribuicao*) existentes: 
 *pós-condição:  Contribuicao adicionada na Celula da Lista de Editor;
*/
void InsereContribuicaoListaContribuicaoListaEditor(ListaEditor *listaEditor, Contribuicao *contribuicao, char *nome)
{
    CelulaEditor *celulaAtual = RetornaCelulaEditorListaEditor(listaEditor, nome);

    if (celulaAtual == NULL)
    {
        printf("ERRO: não foi possivel inserir a contribuição na lista de contribuições do editor %s\n", nome);
        return;
    }

    InsereListaContribuicao(celulaAtual->listaContribuicao, contribuicao, celulaAtual->editor);
}

/*Insere Editor uma celula da Lista de Editor;
 *inputs: TAD (ListaEditor*), (Editor*);
 *outputs: (void);
 *pré-condição TAD (ListaEditor*), (Editor*) existentes: 
 *pós-condição:  Editor adicionado na Celula da Lista de Editor;
*/
void InsereEditorListaEditor(ListaEditor *listaEditor, Editor *editor)
{
    CelulaEditor *novoEditor = (CelulaEditor *)malloc(sizeof(CelulaEditor));
    novoEditor->editor = editor;
    novoEditor->listaContribuicao = IniciaListaContribuicao();

    if (listaEditor->Prim == NULL)
    {
        listaEditor->Prim = novoEditor;
        listaEditor->Ult = novoEditor;
    }
    listaEditor->Ult->proxima = novoEditor;
    listaEditor->Ult = novoEditor;
    novoEditor->proxima = NULL;
}

/*Retira uma celula da Lista de Editor;
 *inputs: TAD (ListaEditor*), string com o  nome do editor;
 *outputs: (void);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaContribuição*) modificada;
*/
void RetiraListaEditor(ListaEditor *listaEditor, char *nome)
{
    CelulaEditor *celulaAtual;
    CelulaEditor *celulaAnterior = NULL;

    //faz a busca

    for (celulaAtual = listaEditor->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeEditor(celulaAtual->editor), nome) == 0)
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
    if (celulaAtual == listaEditor->Prim && celulaAtual == listaEditor->Ult)
    {
        listaEditor->Prim = listaEditor->Ult = NULL;
    }

    else if (celulaAtual == listaEditor->Prim)
    {
        listaEditor->Prim = celulaAtual->proxima;
    }

    else if (celulaAtual == listaEditor->Ult)
    {
        listaEditor->Ult = celulaAnterior;
        listaEditor->Ult->proxima = NULL;
    }
    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);
}

/*Imprime a Lista de Editor
 *inputs: TAD (ListaEditor*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaEditor*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaEditor*) não modificada;
*/
void ImprimeListaEditor(FILE *paginaFile, FILE *logFile, ListaEditor *listaEditor)
{
    CelulaEditor *celulaAtual;

    for (celulaAtual = listaEditor->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        ImprimeListaContribuicao(paginaFile, logFile, celulaAtual->listaContribuicao);
    };
}

/*Verifica pelo nome se o Editor existe ou não na Lista de Editor
 *inputs: TAD (ListaEditor*), string com o nome do editor;
 *outputs: (int);
 *pré-condição: (ListaEditor*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
int BuscaEditorListaEditor(ListaEditor *listaEditor, char *nome)
{
    CelulaEditor *celulaAtual;

    //faz a busca
    for (celulaAtual = listaEditor->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeEditor(celulaAtual->editor), nome) == 0)
        {
            return 1; //Existe Editor;
        }
    }
    return 0; //Não Existe Editor;
}

/*Apaga a Lista de Editor;
 *inputs: TAD (ListaEditor*);
 *outputs: (void);
 *pré-condição TAD (ListaEditor*) existente: 
 *pós-condição:  (ListaEditor*) apagada;
*/
void ApagaListaEditor(ListaEditor *listaEditor)
{

    CelulaEditor *celulaAtual = listaEditor->Prim;
    CelulaEditor *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;
        if (celulaAtual)
        {
            if (celulaAtual->listaContribuicao)
            {
                ApagaCelulaListaContribuicao(celulaAtual->listaContribuicao);
            }
            if (celulaAtual->editor)
            {
                ApagaEditor(celulaAtual->editor);
            }
            free(celulaAtual);
        }

        celulaAtual = celulaSeguinte;
    }

    free(listaEditor);
}