#ifndef PAGINA_H_
#define PAGINA_H_

typedef struct pagina Pagina;

// inicializa Pagina
Pagina *InicializaPagina(char *nomePagina, char *nomeArquivo);

//Imprime os dados do Pagina;
void ImprimePagina(FILE *logFile, FILE *fileEntrada, Pagina *pagina);

//Retorna o nome da Pagina desejado;
char *RetornaNomePagina(Pagina *pagina);

//Retorna o nome do arquivo da  Pagina desejado;
char *RetornaNomeArquivoPagina(Pagina *pagina);

//Apaga a Pagina desejado
void ApagaPagina(Pagina *pagina);

#endif //PAGINA_H_