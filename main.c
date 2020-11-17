#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEditor.h"
#include "listaContribuicao.h"
#include "listaPagina.h"
#include "listaLink.h"

void INSEREPAGINA(ListaPagina *listaPagina, char *nomePagina, char *nomeArquivo);
void RETIRAPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina);
void INSEREEDITOR(FILE *logFile, ListaEditor *listaEditor, char *nomeEditor);
void INSERELINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada); //To do
void RETIRALINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada); //To do
void INSERECONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo);
void RETIRACONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo);
void FIM(ListaPagina *listaPagina, ListaEditor *listaEditor);
void IMPRIMEPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina);
void IMPRIMEWIKED(FILE *logFile, ListaPagina *listaPagina);
void CAMINHO(FILE *logFile);

int main(int argc, char *argv[])
{

    char funcao[30], parametro1[30];
    char parametro2[30], parametro3[30];

    ListaPagina *listaPagina = IniciaListaPagina();
    ListaEditor *listaEditor = IniciaListaEditor();

    FILE *logFile = fopen("outputs/log.txt", "w");
    FILE *fileEntrada = fopen("inputs/teste.txt", "r");
    //  FILE* fileEntrada = fopen(argv[1], "r");

    if (fileEntrada == NULL)
    {
        printf("ERRO: O arquivo não foi aberto!\n");
        return 1;
    }
    if (logFile == NULL)
    {
        printf("ERRO: O arquivo de logs não foi aberto!\n");
        return 1;
    }

    do
    {
        fscanf(fileEntrada, "%s", funcao);

        if (!strcmp(funcao, "FIM"))
        {
            printf("%s\n", funcao);
            FIM(listaPagina, listaEditor);
            break;
        }

        else if (!strcmp(funcao, "INSEREPAGINA"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            printf("%s ", funcao);
            printf("%s ", parametro1);
            printf("%s\n", parametro2);
            INSEREPAGINA(listaPagina, parametro1, parametro2);
            continue;
        }
        else if (!strcmp(funcao, "RETIRAPAGINA"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            printf("%s ", funcao);
            printf("%s\n", parametro1);

            RETIRAPAGINA(logFile, listaPagina, parametro1);
            continue;
        }
        else if (!strcmp(funcao, "INSEREEDITOR"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            printf("%s ", funcao);
            printf("%s\n", parametro1);

            INSEREEDITOR(logFile, listaEditor, parametro1);
            continue;
        }

        else if (!strcmp(funcao, "INSERECONTRIBUICAO"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            fscanf(fileEntrada, "%s", parametro3);
            printf("%s ", funcao);
            printf("%s ", parametro1);
            printf("%s ", parametro2);
            printf("%s\n", parametro3);
            INSERECONTRIBUICAO(logFile, listaPagina, listaEditor, parametro1, parametro2, parametro3);
            continue;
        }
        else if (!strcmp(funcao, "RETIRACONTRIBUICAO"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            fscanf(fileEntrada, "%s", parametro3);
            printf("%s ", funcao);
            printf("%s ", parametro1);
            printf("%s ", parametro2);
            printf("%s\n", parametro3);
            RETIRACONTRIBUICAO(logFile, listaPagina, listaEditor, parametro1, parametro2, parametro3);
            continue;
        }
        else if (!strcmp(funcao, "INSERELINK"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            printf("%s ", funcao);
            printf("%s ", parametro1);
            printf("%s\n", parametro2);
            INSERELINK(logFile, listaPagina, parametro1, parametro2);
            continue;
        }
        else if (!strcmp(funcao, "RETIRALINK"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            printf("%s ", funcao);
            printf("%s ", parametro1);
            printf("%s\n", parametro2);
            RETIRALINK(logFile, listaPagina, parametro1, parametro2);
            continue;
        }
        else if (!strcmp(funcao, "CAMINHO"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            printf("%s ", funcao);
            printf("%s ", parametro1);
            printf("%s\n", parametro2);
            CAMINHO(logFile);
            continue;
        }
        else if (!strcmp(funcao, "IMPRIMEPAGINA"))
        {
            fscanf(fileEntrada, "%s", parametro1);
            printf("%s ", funcao);
            printf("%s\n", parametro1);
            IMPRIMEPAGINA(logFile, listaPagina, parametro1);
            continue;
        }
        else if (!strcmp(funcao, "IMPRIMEWIKED"))
        {
            printf("%s\n", funcao);
            IMPRIMEWIKED(logFile, listaPagina);
        }

    } while (strcmp(funcao, "FIM"));

    fclose(fileEntrada);
    fclose(logFile);

    return 0;
}

void FIM(ListaPagina *listaPagina, ListaEditor *listaEditor)
{
    ApagaListaPagina(listaPagina);
    ApagaListaEditor(listaEditor);
}

void INSEREPAGINA(ListaPagina *listaPagina, char *nomePagina, char *nomeArquivo)
{
    Pagina *novaPagina = InicializaPagina(nomePagina, nomeArquivo);
    InsereListaPagina(listaPagina, novaPagina);
}

void RETIRAPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina)
{
    Pagina *paginaRetirada = RetornaPaginaListaPagina(listaPagina, nomePagina);
    if (paginaRetirada)
    {
        RetiraCelulaPaginaListaPagina(listaPagina, nomePagina);
        RetiraLinkListaPagina(listaPagina, nomePagina);
        ApagaPagina(paginaRetirada);
    }
    else if (paginaRetirada == NULL)
    {
        printf("ERRO: pagina de nome %s não encontrada\n", nomePagina);
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }
}

void INSEREEDITOR(FILE *logFile, ListaEditor *listaEditor, char *nomeEditor)
{
    int existeEditor = BuscaEditorListaEditor(listaEditor, nomeEditor);

    if (existeEditor)
    {
        printf("ERRO: editor de nome %s já existente\n", nomeEditor);
        fprintf(logFile, "ERRO: editor de nome %s já existente\n", nomeEditor);
        return;
    }
    else
    {
        Editor *novoEditor = InicializaEditor(nomeEditor);
        InsereEditorListaEditor(listaEditor, novoEditor);
    }
}

void INSERELINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada)
{
    //Verificar se as paginas existem
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaAtual) == 0)
    {
        printf("ERRO: pagina de nome %s nao encontrada\n", nomePaginaAtual);
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaAtual);
        return;
    }
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaLinkada) == 0)
    {
        printf("ERRO: pagina de nome %s nao encontrada\n", nomePaginaLinkada);
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaLinkada);
        return;
    }

    ListaLink *listalinkBuscada = RetornaListaLinkListaPagina(listaPagina, nomePaginaAtual);
    if (BuscaLinkListaLink(listalinkBuscada, nomePaginaLinkada) == 1)
    {
        printf("ERRO: Link de nome %s ja existe na página %s/n", nomePaginaLinkada, nomePaginaAtual);
        fprintf(logFile, "ERRO: Link de nome %s ja existe na página %s/n", nomePaginaLinkada, nomePaginaAtual);
        return;
    }
    InsereListaLink(listalinkBuscada, RetornaPaginaListaPagina(listaPagina, nomePaginaLinkada));
}

void RETIRALINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada)
{
    //Verificar se as paginas existem
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaAtual) == 0)
    {
        printf("ERRO: pagina de nome %s nao encontrada\n", nomePaginaAtual);
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaAtual);
        return;
    }
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaLinkada) == 0)
    {
        printf("ERRO: pagina de nome %s nao encontrada\n", nomePaginaLinkada);
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaLinkada);
        return;
    }

    // Verificar se o Link existe
    ListaLink *listalinkBuscada = RetornaListaLinkListaPagina(listaPagina, nomePaginaAtual);
    if (BuscaLinkListaLink(listalinkBuscada, nomePaginaLinkada) == 0)
    {
        printf("ERRO: Link de nome %s não encontrada na página %s\n", nomePaginaLinkada, nomePaginaAtual);
        fprintf(logFile, "ERRO: Link de nome %s não encontrada na página %s\n", nomePaginaLinkada, nomePaginaAtual);
        return;
    }
    RetiraListaLink(listalinkBuscada, nomePaginaLinkada);
}

void INSERECONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo)
{
    if (!BuscaPaginaListaPagina(listaPagina, nomePagina))
    {
        printf("ERRO: pagina de nome %s não encontrada\n", nomePagina);
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }

    if (!BuscaEditorListaEditor(listaEditor, nomeEditor))
    {
        printf("ERRO: editor de nome %s não encontrada\n", nomeEditor);
        fprintf(logFile, "ERRO: editor de nome %s não encontrada\n", nomeEditor);
        return;
    }

    //Buscar se a contribuição já foi adicionada

    Contribuicao *novaContribuicao = InicializaContribuicao(nomeArquivo);
    Editor *editorBuscado = RetornaEditorListaEditor(listaEditor, nomeEditor);
    ListaContribuicao *listaContribuicaoBuscada = RetornaListaContribuicaoListaPagina(listaPagina, nomePagina);
    InsereListaContribuicao(listaContribuicaoBuscada, novaContribuicao, editorBuscado);
    InsereContribuicaoListaContribuicaoListaEditor(listaEditor, novaContribuicao, nomeEditor);
}

void RETIRACONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo)
{
    if (!BuscaPaginaListaPagina(listaPagina, nomePagina))
    {

        printf("ERRO: pagina de nome %s não encontrada\n", nomePagina);
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }

    if (!BuscaEditorListaEditor(listaEditor, nomeEditor))
    {
        printf("ERRO: editor de nome %s não encontrada\n", nomeEditor);
        fprintf(logFile, "ERRO: editor de nome %s não encontrada\n", nomeEditor);
        return;
    }

    //Buscar se há essa contribuição na pagina

    ListaContribuicao *listaContribuicaoPagina = RetornaListaContribuicaoListaPagina(listaPagina, nomePagina);

    if (RetornaStatusContribuicaoListaContribuicao(listaContribuicaoPagina, nomeArquivo) == 2)
    {
        printf("ERRO: contribuição de arquivo %s já retirada previamente\n", nomeArquivo);
        fprintf(logFile, "ERRO: contribuição de arquivo %s já retirada previamente\n", nomeArquivo);

        return;
    }

    //Verificar se ja a contribuiçao ja foi apagada
    ListaContribuicao *listaContribuicaoBuscada = RetornaListaContribuicaoListaEditor(listaEditor, nomeEditor);

    if (RetornaStatusContribuicaoListaContribuicao(listaContribuicaoBuscada, nomeArquivo) == 1)
    {
        printf("ERRO: contribuição de arquivo %s já retirada previamente\n", nomeArquivo);
        fprintf(logFile, "ERRO: contribuição de arquivo %s já retirada previamente\n", nomeArquivo);
        return;
    }
    // Verificar se o editor pode apagar a contribuição
    Editor *editorBuscado = RetornaEditorListaEditor(listaEditor, nomeEditor);
    Editor *editorBuscadoDaListaContribuicao = RetornaEditorListaContribuicao(listaContribuicaoBuscada, nomeEditor); //Problema ao apagar duas vezes

    //Caso nao for o mesmo editor
    if (strcmp(RetornaNomeEditor(editorBuscado), RetornaNomeEditor(editorBuscadoDaListaContribuicao)) != 0)
    {
        printf("dentro if altera\n");
        printf("ERRO: editor de nome %s não tem direito de excluir esta contribuição\n", nomeEditor);
        fprintf(logFile, "ERRO: editor de nome %s não tem direito de excluir esta contribuição\n", nomeEditor);
        return;
    }

    //Se o editor for o mesmo
    else if (strcmp(RetornaNomeEditor(editorBuscado), RetornaNomeEditor(editorBuscadoDaListaContribuicao)) == 0)
    {
        AlteraStatusContribuicaoListaContribuicao(listaContribuicaoBuscada, nomeArquivo);
    }
}

void IMPRIMEPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina)
{
    Pagina *paginaRetirada = RetornaPaginaListaPagina(listaPagina, nomePagina);
    if (paginaRetirada)
    {
        ImprimePaginaCompletaListaPagina(logFile, listaPagina, nomePagina);
    }
    else if (paginaRetirada == NULL)
    {
        printf("ERRO: pagina de nome %s não encontrada\n", nomePagina);
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }
}

void IMPRIMEWIKED(FILE *logFile, ListaPagina *listaPagina)
{
    ImprimeCompletaListaPagina(logFile, listaPagina);
}

void CAMINHO(FILE *logFile)
{
    printf("ERRO: Essa funcao (CAMINHO) está disponivel apenas na versao premium\n");
    fprintf(logFile, "ERRO: Essa funcao (CAMINHO) está disponivel apenas na versao premium\n");
    return;
}
