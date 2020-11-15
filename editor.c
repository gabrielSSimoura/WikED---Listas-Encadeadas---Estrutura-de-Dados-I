#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

struct editor
{
    char *nome;
};

// inicializa Editor
Editor *InicializaEditor(char *nome)
{
    Editor *editor = (Editor *)malloc(sizeof(Editor));
    editor->nome = strdup(nome);

    return editor;
}

//Imprime os dados do Editor;
void ImprimeEditor(Editor *editor)
{
    if (editor)
    {
        printf("%s\n", editor->nome);
    }
}

//Retorna o nome do editor desejado;
char *RetornaNomeEditor(Editor *editor)
{
    return editor->nome;
}

//Apaga o editor desejado
void ApagaEditor(Editor *editor)
{
    if (editor)
    {
        free(editor->nome);
    }
    free(editor);
}
