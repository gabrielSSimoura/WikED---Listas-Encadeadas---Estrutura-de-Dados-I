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

ListaEditor *IniciaListaEditor()
{
    ListaEditor *listaEditor = (ListaEditor *)malloc(sizeof(ListaEditor));
    listaEditor->Prim = NULL;
    listaEditor->Ult = NULL;

    return listaEditor;
}

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

void InsereContribuicaoListaContribuicaoListaEditor(ListaEditor *listaEditor, Contribuicao *contribuicao, char *nome)
{
    CelulaEditor *celulaAtual = RetornaCelulaEditorListaEditor(listaEditor, nome);

    if (celulaAtual == NULL)
    {
        printf("ERRO: não foi possivel inserir a contribuição na lista de contribuições do editor %s\n", nome);
        // fprintf(logFile, "ERRO: não foi possivel inserir a contribuição na lista de contribuições do editor %s\n", nome);
        return;
    }

    InsereListaContribuicao(celulaAtual->listaContribuicao, contribuicao, celulaAtual->editor);
}

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

void ImprimeListaEditor(FILE *paginaFile, FILE *logFile, ListaEditor *listaEditor)
{
    CelulaEditor *celulaAtual;

    for (celulaAtual = listaEditor->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        ImprimeEditor(celulaAtual->editor);
        ImprimeListaContribuicao(paginaFile, logFile, celulaAtual->listaContribuicao);
    };
}

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

void ApagaListaEditor(ListaEditor *listaEditor)
{

    CelulaEditor *celulaAtual = listaEditor->Prim;
    CelulaEditor *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        if (celulaAtual)
        {
            if (celulaAtual->editor)
            {
                ApagaEditor(celulaAtual->editor);
            }
            if (celulaAtual->listaContribuicao)
            {
                ApagaListaContribuicao(celulaAtual->listaContribuicao);
            }
            free(celulaAtual);
        }
        celulaSeguinte = celulaAtual->proxima;
        celulaAtual = celulaSeguinte;
    }

    free(listaEditor);
}