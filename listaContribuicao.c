#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaContribuicao.h"

struct celulaContribuicao
{
    Editor *editor;
    Contribuicao *contribuicao;
    CelulaContribuicao *proxima;
};

struct listaContribuicao
{
    CelulaContribuicao *Prim;
    CelulaContribuicao *Ult;
};

/*Inicializa uma Lista de Contribuições;
 *inputs: (void);
 *outputs: TAD (ListaContribuicao*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (ListaContribuicao*) de retorno existente;
*/
ListaContribuicao *IniciaListaContribuicao()
{
    ListaContribuicao *listaContribuicao = (ListaContribuicao *)malloc(sizeof(ListaContribuicao));
    listaContribuicao->Prim = NULL;
    listaContribuicao->Ult = NULL;

    return listaContribuicao;
}

/*Retorna um TAD de Editor da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*) e string com nome do arquivo ;
 *outputs: TAD (Editor*);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: (Editor*) de retorno existente;
*/
Editor *RetornaEditorListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeEditor)
{
    CelulaContribuicao *celulaAtual;

    //Faz a busca pelo editor de nome = nomeEditor, na lista de contribuição

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeEditor(celulaAtual->editor), nomeEditor) == 0)
        {
            return celulaAtual->editor;
        }
    }

    return NULL;
}

/*Retorna um TAD Contribuição da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*) e string com nome do arquivo da contribuição ;
 *outputs: TAD (Contribuicao*) ;
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: (Contribuicao*) de retorno existente;
*/
Contribuicao *RetornaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    //Chama uma função que Retorna a Celula Buscada pelo nome de arquivo
    CelulaContribuicao *celulaAtual = RetornaCelulaContribuicaoListaContribuicao(listaContribuicao, nomeArquivo);

    if (celulaAtual == NULL)
    {
        return NULL;
    }

    return celulaAtual->contribuicao;
}

/*Retorna um TAD CelulaContribuição da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*) e string com nome do arquivo da contribuição ;
 *outputs: TAD (CelulaContribuicao*)  ;
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: (CelulaContribuicao*) de retorno existente;
*/
CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual;

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeArquivoContribuicao(celulaAtual->contribuicao), nomeArquivo) == 0)
        {
            return celulaAtual;
        }
    }

    return NULL;
}

/*Insere dados em uma celula da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*), (Editor*) e (Contriuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*), (Editor*) e (Contriuicao*) existente: 
 *pós-condição: Celula da Contribuição criada;
*/
void InsereListaContribuicao(ListaContribuicao *listaContribuicao, Contribuicao *contribuicao, Editor *editor)
{
    CelulaContribuicao *novaContribucao = (CelulaContribuicao *)malloc(sizeof(CelulaContribuicao));
    novaContribucao->contribuicao = contribuicao;
    novaContribucao->editor = editor;

    // Lista Vazia
    if (listaContribuicao->Prim == NULL)
    {

        listaContribuicao->Prim = novaContribucao;
        listaContribuicao->Ult = novaContribucao;
    }

    listaContribuicao->Ult->proxima = novaContribucao;
    listaContribuicao->Ult = novaContribucao;
    novaContribucao->proxima = NULL;
}

/*Retira uma celula da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição: Celula da Contribuição retirada, (ListaContribuição*) modificada;
*/
void RetiraCelulaListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual = listaContribuicao->Prim;
    CelulaContribuicao *celulaAnterior = NULL;

    //faz a busca
    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeArquivoContribuicao(celulaAtual->contribuicao), nomeArquivo) == 0)
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
    if (celulaAtual == listaContribuicao->Prim && celulaAtual == listaContribuicao->Ult)
    {
        listaContribuicao->Prim = listaContribuicao->Ult = NULL;
    }

    else if (celulaAtual == listaContribuicao->Prim)
    {
        listaContribuicao->Prim = celulaAtual->proxima;
    }

    else if (celulaAtual == listaContribuicao->Ult)
    {
        listaContribuicao->Ult = celulaAnterior;
        listaContribuicao->Ult->proxima = NULL;
    }
    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);
}

/*Imprime a Lista de Contribuição
 *inputs: TAD (ListaContribuicao*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaContribuicao*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaContribuicao*) não modificada;
*/
void ImprimeListaContribuicao(FILE *paginaFile, FILE *logFile, ListaContribuicao *listaContribuicao)
{

    if (listaContribuicao == NULL)
    {
        fprintf(logFile, "ERRO: pagina não possui Lista de Contribuições\n");
        return;
    }

    CelulaContribuicao *celula;

    fprintf(paginaFile, "\n--> Textos");

    for (celula = listaContribuicao->Prim; celula != NULL; celula = celula->proxima)
    {
        if (RetornaStatusContribuicao(celula->contribuicao))
        {
            continue;
        }

        fprintf(paginaFile, "\n\n-------- %s (%s) --------\n\n", RetornaNomeArquivoContribuicao(celula->contribuicao), RetornaNomeEditor(celula->editor));
        ImprimeArquivoContribuicao(logFile, paginaFile, RetornaNomeArquivoContribuicao(celula->contribuicao));
        fprintf(paginaFile, "\n");
    };
}

/*Imprime o Histórico de Contribuições da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaContribuicao*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaContribuicao*) não modificada;
*/
void ImprimeHistoricoListaContribuicao(FILE *logFile, FILE *fileEntrada, ListaContribuicao *listaContribuicao)
{

    if (listaContribuicao == NULL)
    {
        fprintf(logFile, "ERRO: pagina não possui histórico de Contribuições\n");
        return;
    }

    CelulaContribuicao *celulaAtual;

    fprintf(fileEntrada, "\n--> Historico de contribuicoes\n");

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {

        fprintf(fileEntrada, "%s %s", RetornaNomeEditor(celulaAtual->editor), RetornaNomeArquivoContribuicao(celulaAtual->contribuicao));

        if (RetornaStatusContribuicao(celulaAtual->contribuicao))
        {
            fprintf(fileEntrada, " <<retirada>>\n");
        }
        else
        {
            fprintf(fileEntrada, "\n");
        }
    }
}

/*Altera o Status de uma Contribuiçao da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*), nome do arquivo;
 *outputs: (void);
 *pré-condição: (ListaContribuicao*) existente;
 *pós-condição:  Status da Contribuiçao desejada da Lista de Contribuição modificada;
*/
void AlteraStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual = RetornaCelulaContribuicaoListaContribuicao(listaContribuicao, nomeArquivo);

    if (celulaAtual == NULL)
    {
        return;
    }

    AlteraStatusContribuicao(celulaAtual->contribuicao);
}

/*Altera o Status da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição: (ListaContribuicao*) existente;
 *pós-condição:  Status da Lista de Contribuição modificada;
*/
void AlteraStatusListaContribuicao(ListaContribuicao *listaContribuicao)
{
    CelulaContribuicao *celulaAtual;

    for (celulaAtual = listaContribuicao->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {

        AlteraStatusContribuicao(celulaAtual->contribuicao);
    }
}

/*Retorna o Status de uma Contribuiçao da Lista de Contribuição
 *inputs: TAD (ListaContribuicao*), nome do arquivo;
 *outputs: (int);
 *pré-condição: (ListaContribuicao*) existente;
 *pós-condição:  variável inteira existente para receber o valor do status;
*/
int RetornaStatusContribuicaoListaContribuicao(ListaContribuicao *listaContribuicao, char *nomeArquivo)
{
    CelulaContribuicao *celulaAtual = RetornaCelulaContribuicaoListaContribuicao(listaContribuicao, nomeArquivo);

    if (celulaAtual == NULL)
    {
        return 2;
    }

    return (RetornaStatusContribuicao(celulaAtual->contribuicao));
}

/*Apaga as celulas da Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição:  (ListaContribuição*) esvaziada;
*/
void ApagaCelulaListaContribuicao(ListaContribuicao *listaContribuicao)
{

    CelulaContribuicao *celulaAtual = listaContribuicao->Prim;
    CelulaContribuicao *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;

        if (celulaAtual)
        {
            free(celulaAtual);
        }
        celulaAtual = celulaSeguinte;
    }

    free(listaContribuicao);
}

/*Apaga a Lista de Contribuição;
 *inputs: TAD (ListaContribuicao*);
 *outputs: (void);
 *pré-condição TAD (ListaContribuicao*) existente: 
 *pós-condição:  (ListaContribuição*) apagada;
*/
void ApagaListaContribuicao(ListaContribuicao *listaContribuicao)

{
    CelulaContribuicao *celulaAtual = listaContribuicao->Prim;
    CelulaContribuicao *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;

        if (celulaAtual)
        {
            if (celulaAtual->contribuicao)
            {
                ApagaContribuicao(celulaAtual->contribuicao);
            }
            free(celulaAtual);
        }
        celulaAtual = celulaSeguinte;
    }

    free(listaContribuicao);
}
