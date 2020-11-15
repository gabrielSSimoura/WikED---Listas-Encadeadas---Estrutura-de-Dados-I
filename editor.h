#ifndef EDITOR_H_
#define EDITOR_H_

typedef struct editor Editor;

// inicializa Editor
Editor *InicializaEditor(char *nome);

//Imprime os dados do Editor;
void ImprimeEditor(Editor *editor);

//Retorna o nome do editor desejado;
char *RetornaNomeEditor(Editor *editor);

//Apaga o editor desejado
void ApagaEditor(Editor *editor);

#endif //EDITOR_H_