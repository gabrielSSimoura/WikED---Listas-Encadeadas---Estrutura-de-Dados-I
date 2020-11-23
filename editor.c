#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

struct editor
{
    char *nome;
};

/*Inicializa editor;
 *inputs: nome do editor;
 *outputs: (Editor*) devidamente inicializado e alocado;
 *pré-condição: string existente;
 *pós-condição: (Editor*) de retorno existente;
*/
Editor *InicializaEditor(char *nome)
{
    Editor *editor = (Editor *)malloc(sizeof(Editor));
    editor->nome = strdup(nome); //Aloca o ponteiro para o nome com o tamanho preciso;

    return editor;
}

/*Retorna o nome de um editor;
 *inputs: TAD editor existente;
 *outputs: (char*) com o nome da editor;
 *pré-condição: (Editor*) existente, com string nome existente;
 *pós-condição: (Editor*) não modificado;
*/
char *RetornaNomeEditor(Editor *editor)
{
    return editor->nome;
}

/*Apaga o editor desejado
 *inputs: TAD editor existente;
 *outputs: (void) - editor Apagada;
 *pré-condição: (Editor*) existente;
 *pós-condição: (Editor*) Apagada;
*/
void ApagaEditor(Editor *editor)
{
    if (editor)
    {
        free(editor->nome); //Verifica se o ponteiro para nome, existe;
    }
    free(editor);
}
