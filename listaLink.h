#ifndef LISTALINK_H_
#define LISTALINK_H_

#include <stdio.h>

typedef struct celulaLink CelulaLink;
typedef struct listaLink ListaLink;

#include "listaPagina.h"

/*Inicializa uma Lista de Link;
 *inputs: (void);
 *outputs: TAD (LinstaLink*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (LinstaLink*) de retorno existente;
*/
ListaLink *IniciaListaLink();

/*Retorna um TAD Pagina da Lista de Link;
 *inputs: TAD (ListaLink*) e string com nome da página ;
 *outputs: TAD (Pagina*);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição: (Pagina*) de retorno existente;
*/
Pagina *RetornaPaginaListaLink(ListaLink *listaLink, char *nomePagina);

/*Retorna uma celula da Lista de Link;
 *inputs: TAD (ListaLink*) e string com nome da página ;
 *outputs: TAD (CelulaLink*);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição: (CelulaLink*) de retorno existente;
*/
CelulaLink *RetornaCelulaLinkListaLink(ListaLink *listaLink, char *nomePagina);

/*Verifica pelo nome se a Pagina existe ou não na Lista de LInk
 *inputs: TAD (ListaLink*), string com o nome da pagina;
 *outputs: (int);
 *pré-condição: (ListaLink*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
int BuscaLinkListaLink(ListaLink *listaLink, char *nomeLink);

/*Retira uma celula da Lista de Link;
 *inputs: TAD (ListaLink*), string com o  nome da Pagina;
 *outputs: (void);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaLink*) modificada;
*/
void RetiraListaLink(ListaLink *listaLink, char *nomePagina);

/*Insere Pagina uma celula da Lista de Link;
 *inputs: TAD (ListaLink*), (Pagina*);
 *outputs: (void);
 *pré-condição TAD (ListaLink*), (Pagina*) existentes: 
 *pós-condição:  Pagina adicionado na Celula da Lista de Link;
*/
void InsereListaLink(ListaLink *listaLink, Pagina *pagina);

/*Imprime a Lista de Link
 *inputs: TAD (ListaLink*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaLink*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaLink*) não modificada;
*/
void ImprimeListaLink(FILE *logFile, FILE *fileEntrada, ListaLink *listaLink);

/*Busca os Caminhos na Lista de Link;
 *inputs: TAD (ListaLink*), (ListaPagina*), (Pagina*);
 *outputs: (void);
 *pré-condição TAD (ListaLink*), (ListaPagina*) e (Pagina*) existentes: 
 *pós-condição:  verificaçao se há caminho ou não de uma página à outra;
*/
void CaminhoListaLink(ListaPagina *listaPagina, ListaLink *paginasPercorridas, Pagina *paginaAtual);

/*Apaga a Lista de Link;
 *inputs: TAD (ListaLink*);
 *outputs: (void);
 *pré-condição TAD (ListaLink*) existente: 
 *pós-condição:  (ListaLink*) apagada;
*/
void ApagaListaLink(ListaLink *listaLink);

#endif
