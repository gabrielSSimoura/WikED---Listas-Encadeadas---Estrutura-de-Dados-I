#ifndef EDITOR_H_
#define EDITOR_H_

typedef struct editor Editor;

/*Inicializa editor;
 *inputs: nome  desse editor;
 *outputs: (Editor*) devidamente inicializado e alocado;
 *pré-condição: string existente;
 *pós-condição: (Editor*) de retorno existente;
*/
Editor *InicializaEditor(char *nome);

/*Retorna o nome de um editor;
 *inputs: TAD editor existente;
 *outputs: (char*) com o nome da editor;
 *pré-condição: (Editor*) existente, com string nome existente;
 *pós-condição: (Editor*) não modificado;
*/
char *RetornaNomeEditor(Editor *editor);

/*Apaga o editor desejado
 *inputs: TAD editor existente;
 *outputs: (void) - editor Apagada;
 *pré-condição: (Editor*) existente;
 *pós-condição: (Editor*) Apagada;
*/
void ApagaEditor(Editor *editor);

#endif //EDITOR_H_