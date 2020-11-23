#ifndef LISTACONTRIBUICAO_H_
#define LISTACONTRIBUICAO_H_

#include <stdio.h>

typedef struct celulaContribuicao CelulaContribuicao;
typedef struct listaContribuicao ListaContribuicao;

#include "contribuicao.h"
#include "editor.h"

/*Inicializa uma Lista de Contribuições;
 *inputs: (void);
 *outputs: TAD (ListaContribuicao*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (ListaContribuicao*) de retorno existente;
*/
ListaContribuicao *IniciaListaContribuicao();

/*Retorna um TAD de Editor da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*) e string com nome do editor ;
 *outputs: TAD (Editor*);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: (Editor*) de retorno existente;
*/
Editor *RetornaEditorListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeEditor);

/*Retorna um TAD Contribuição da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*) e string com nome do arquivo da contribuição ;
 *outputs: TAD (Contribuicao*) ;
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: (Contribuicao*) de retorno existente;
*/
Contribuicao *RetornaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

/*Retorna um TAD CelulaContribuição da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*) e string com nome do arquivo da contribuição ;
 *outputs: TAD (CelulaContribuicao*)  ;
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: (CelulaContribuicao*) de retorno existente;
*/
CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

/*Insere dados em uma celula da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*), (Editor*) e (Contriuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*), (Editor*) e (Contriuicao*) existente: 
 *pós-condição: Celula da Contribuição criada;
*/
void InsereListaContribuicao(ListaContribuicao *listaContribuicao, Contribuicao *contribuicao, Editor *editor);

/*Retira uma celula da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: Celula da Contribuição retirada, (ListaContribuição*) modificada;
*/
void RetiraCelulaListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

/*Imprime a Lista de Contribuição
 *inputs: TAD (ListaContribuicao*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaContribuicao*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaContribuicao*) não modificada;
*/
void ImprimeListaContribuicao(FILE *paginaFile, FILE *logFile, ListaContribuicao *listaContribuicao);

/*Imprime o Histórico de Contribuições da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaContribuicao*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaContribuicao*) não modificada;
*/
void ImprimeHistoricoListaContribuicao(FILE *logFile, FILE *fileEntrada, ListaContribuicao *listaContribuicao);

/*Altera o Status da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição: (ListaContribuicao*) existente;
 *pós-condição:  Status da Lista de Contribuição modificada;
*/
void AlteraStatusListaContribuicao(ListaContribuicao *listaContribuicao);

/*Retorna o Status de uma Contribuiçao da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*), nome do arquivo;
 *outputs: (int);
 *pré-condição: (ListaContribuicao*) existente;
 *pós-condição:  variável inteira existente para receber o valor do status;
*/
int RetornaStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

/*Altera o Status de uma Contribuiçao da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*), nome do arquivo;
 *outputs: (void);
 *pré-condição: (ListaContribuicao*) existente;
 *pós-condição:  Status da Contribuiçao desejada da Lista de Contribuição modificada;
*/
void AlteraStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo);

/*Apaga as celulas da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição:  (ListaContribuição*) esvaziada;
*/
void ApagaCelulaListaContribuicao(ListaContribuicao *listaContribuicao);

/*Apaga a Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição:  (ListaContribuição*) apagada;
*/
void ApagaListaContribuicao(ListaContribuicao *listaContribuicao);

#endif
