#ifndef PAGINA_H_
#define PAGINA_H_

typedef struct pagina Pagina;

/*Inicializa Pagina;
 *inputs: nome do Arquivo dessa Pagina;
 *outputs: (Pagina*) devidamente inicializada e alocada;
 *pré-condição: string existente;
 *pós-condição: (Pagina*) de retorno existente;
*/
Pagina *InicializaPagina(char *nomePagina, char *nomeArquivo);

/*Imprime a Pagina desejada
 *inputs: TAD Pagina existente, arquivo da Página, arquivo de log;
 *outputs: (void);
 *pré-condição: (Pagina*), arquivo da Página, arquivo de log, existentes;
 *pós-condição: (Pagina*) não modificado;
*/
void ImprimePagina(FILE *logFile, FILE *fileEntrada, Pagina *pagina);

/*Retorna o nome de uma Pagina;
 *inputs: TAD Pagina existente;
 *outputs: (char*) com o nome da Pagina;
 *pré-condição: (Pagina*) existente, com string nome existente;
 *pós-condição: (Pagina*) não modificado, string de retorno existente;
*/
char *RetornaNomePagina(Pagina *pagina);

/*Retorna o nome do arquivo de uma Pagina;
 *inputs: TAD Pagina existente;
 *outputs: (char*) com o nome do arquivo de uma Pagina;
 *pré-condição: (Pagina*) existente, com string arquivo existente;
 *pós-condição: (Pagina*) não modificado, string de retorno existente;
*/
char *RetornaNomeArquivoPagina(Pagina *pagina);

/*Apaga a pagina desejada
 *inputs: TAD pagina existente;
 *outputs: (void) - pagina Apagada;
 *pré-condição: (Pagina*) existente;
 *pós-condição: (Pagina*) Apagada;
*/
void ApagaPagina(Pagina *pagina);

#endif //PAGINA_H_