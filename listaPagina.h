#ifndef LISTAPAGINA_H_
#define LISTAPAGINA_H_

typedef struct celulaPagina CelulaPagina;
typedef struct listaPagina ListaPagina;

#include "pagina.h"
#include "listaContribuicao.h"
#include "listaLink.h"

/*Inicializa uma Lista de Pagina;
 *inputs: (void);
 *outputs: TAD (LinstaPagina*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (LinstaPagina*) de retorno existente;
*/
ListaPagina *IniciaListaPagina();

/*Retorna um TAD ListaContribuicao da Lista de Pagina;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (ListaContribuicao*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (ListaContribuicao*) de retorno existente;
*/
ListaContribuicao *RetornaListaContribuicaoListaPagina(ListaPagina *listaPagina, char *nomePagina);

/*Retorna um TAD CelulaPagina da Lista de Link;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (CelulaPagina*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (CelulaPagina*) de retorno existente;
*/
CelulaPagina *RetornaCelulaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

/*Retorna um TAD ListaLink da Lista de Pagina;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (ListaLink*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (ListaLink*) de retorno existente;
*/
ListaLink *RetornaListaLinkListaPagina(ListaPagina *listaPagina, char *nomePagina);

/*Retorna um TAD Pagina da Lista de Pagina;
 *inputs: TAD (ListaPagina*) e string com nome da página ;
 *outputs: TAD (Pagina*);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: (Pagina*) de retorno existente;
*/
Pagina *RetornaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

/*Retira uma celula da Lista de Pagina;
 *inputs: TAD (ListaPagina*), string com o  nome da Pagina;
 *outputs: (void);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaPagina*) modificada;
*/
void RetiraCelulaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

/*Retira uma Pagina da lista de Link da Lista de Pagina;
 *inputs: TAD (ListaPagina*), string com o nome da Pagina;
 *outputs: (void);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição: Pagina da Lista de Link da Lista de Pagina retirada, (ListaPagina*) modificada;
*/
void RetiraLinkListaPagina(ListaPagina *listaPagina, char *nomePagina);

/*Insere Pagina uma celula da Lista de Pagina;
 *inputs: TAD (ListaPagina*), (Pagina*);
 *outputs: (void);
 *pré-condição TAD (ListaPagina*), (Pagina*) existentes: 
 *pós-condição:  Pagina adicionado na Celula da Lista de Pagina;
*/
void InsereListaPagina(ListaPagina *listaPagina, Pagina *pagina);

/*Verifica pelo nome se a Pagina existe ou não na Lista de Pagina
 *inputs: TAD (ListaPagina*), string com o nome da pagina;
 *outputs: (int);
 *pré-condição: (ListaPagina*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
int BuscaPaginaListaPagina(ListaPagina *listaPagina, char *nomePagina);

/*Percorre a Lista Imprimindo as paginas da lista de pagina
 *inputs: TAD (ListaPagina*) existente, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaPagina* e arquivo de log existentes;
 *pós-condição: (ListaPagina*) não modificada;
*/
void ImprimeCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina);

/*Imprime uma pagina da lista de pagina com todos os seus dados
 *inputs: TAD (ListaPagina*) existente, arquivo de log, nome da paginaa;
 *outputs: (void);
 *pré-condição: (ListaPagina* e arquivo de log existentes;
 *pós-condição: (ListaPagina*) não modificada;
*/
void ImprimePaginaCompletaListaPagina(FILE *logFile, ListaPagina *listaPagina, char *nomePagina);

/*Apaga a Lista de Pagina;
 *inputs: TAD (ListaPagina*);
 *outputs: (void);
 *pré-condição TAD (ListaPagina*) existente: 
 *pós-condição:  (ListaPagina*) apagada;
*/
void ApagaListaPagina(ListaPagina *listaPagina);

#endif
