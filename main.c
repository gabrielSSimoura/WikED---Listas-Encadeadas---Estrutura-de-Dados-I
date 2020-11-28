#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEditor.h"
#include "listaContribuicao.h"
#include "listaPagina.h"
#include "listaLink.h"

void INSEREPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina, char *nomeArquivo);
void RETIRAPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina);
void INSEREEDITOR(FILE *logFile, ListaEditor *listaEditor, char *nomeEditor);
void INSERELINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada); //To do
void RETIRALINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada); //To do
void INSERECONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo);
void RETIRACONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo);
void FIM(ListaPagina *listaPagina, ListaEditor *listaEditor);
void IMPRIMEPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina);
void IMPRIMEWIKED(FILE *logFile, ListaPagina *listaPagina);
void CAMINHO(FILE *logFile, FILE *fileEntrda, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada);

int main(int argc, char *argv[])
{
    //Parâmetros de leitura;
    char funcao[30], parametro1[30];
    char parametro2[30], parametro3[30];

    // FILE *fileEntrada = fopen("entrada.txt", "r");
    FILE *fileEntrada = fopen(argv[1], "r");

    //Verificando a abertura dos arquivos;
    if (fileEntrada == NULL)
    {
        printf("ERRO: O arquivo não foi aberto!\n");
        return 0;
    }

    FILE *logFile = fopen("log.txt", "w");

    if (logFile == NULL)
    {
        printf("ERRO: O arquivo de logs não foi aberto!\n");
        return 0;
    }

    //Tratar Lixo na leitura de arquivos;
    char lixo = '0';

    //Lê o arquivo até encontrar um char válido;
    while (!(lixo >= 'A' && lixo <= 'Z') && !(lixo >= 'a' && lixo <= 'z'))
    {
        fscanf(fileEntrada, "%c", &lixo);
    }

    //Atribuindo o primeiro char válido à primeira posição da string da função;
    funcao[0] = lixo;

    //Lê a primeira função do arquivo de entrada.txt;
    for (int i = 1; lixo != ' '; i++)
    {
        fscanf(fileEntrada, "%c", &lixo);

        if (lixo != ' ')
        {
            funcao[i] = lixo;
        }

        else
        {
            funcao[i] = '\0';
        }
    }

    //Inicializa as listas de páginas e de editores;
    ListaPagina *listaPagina = IniciaListaPagina();
    ListaEditor *listaEditor = IniciaListaEditor();

    //Função constante de leitura e execução do programa até o "FIM" do arquivo;
    //É feita a leitura da função no arquivo de entrada e a função equivalente é chamada, com os parâmetros lidos;
    do
    {

        if (strcmp(funcao, "FIM") == 0)
        {
            FIM(listaPagina, listaEditor);
            break;
        }

        else if (strcmp(funcao, "INSEREPAGINA") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            INSEREPAGINA(logFile, listaPagina, parametro1, parametro2);
            continue;
        }
        else if (strcmp(funcao, "RETIRAPAGINA") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            RETIRAPAGINA(logFile, listaPagina, parametro1);
            continue;
        }
        else if (strcmp(funcao, "INSEREEDITOR") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            INSEREEDITOR(logFile, listaEditor, parametro1);
            continue;
        }
        else if (strcmp(funcao, "RETIRAEDITOR") == 0)
        {
            fprintf(logFile, "ERRO: Função RETIRAEDITOR indisponível no momento\n");
            fscanf(fileEntrada, "%s", parametro1);
            continue;
        }

        else if (strcmp(funcao, "INSERECONTRIBUICAO") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            fscanf(fileEntrada, "%s", parametro3);
            INSERECONTRIBUICAO(logFile, listaPagina, listaEditor, parametro1, parametro2, parametro3);
            continue;
        }
        else if (strcmp(funcao, "RETIRACONTRIBUICAO") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            fscanf(fileEntrada, "%s", parametro3);
            RETIRACONTRIBUICAO(logFile, listaPagina, listaEditor, parametro1, parametro2, parametro3);
            continue;
        }
        else if (strcmp(funcao, "INSERELINK") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            INSERELINK(logFile, listaPagina, parametro1, parametro2);
            continue;
        }
        else if (strcmp(funcao, "RETIRALINK") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);
            RETIRALINK(logFile, listaPagina, parametro1, parametro2);
            continue;
        }
        else if (strcmp(funcao, "CAMINHO") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            fscanf(fileEntrada, "%s", parametro2);

            CAMINHO(logFile, fileEntrada, listaPagina, parametro1, parametro2);
            continue;
        }
        else if (strcmp(funcao, "IMPRIMEPAGINA") == 0)
        {
            fscanf(fileEntrada, "%s", parametro1);
            IMPRIMEPAGINA(logFile, listaPagina, parametro1);
            continue;
        }
        else if (strcmp(funcao, "IMPRIMEWIKED") == 0)
        {
            IMPRIMEWIKED(logFile, listaPagina);
        }

    } while (fscanf(fileEntrada, "%s", funcao) != EOF);

    //Fechando os arquivos abertos;
    fclose(fileEntrada);
    fclose(logFile);

    return 0;
}

//Apagando as listas de Páginas e de Editor;
void FIM(ListaPagina *listaPagina, ListaEditor *listaEditor)
{
    ApagaListaPagina(listaPagina);
    ApagaListaEditor(listaEditor);
}

//Inserindo página na lista de Página;
void INSEREPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina, char *nomeArquivo)
{

    //Verficar se a página já foi inserida
    if (BuscaPaginaListaPagina(listaPagina, nomePagina))
    {
        fprintf(logFile, "ERRO: pagina de nome %s já inserida previamente\n", nomePagina);
        return;
    }

    Pagina *novaPagina = InicializaPagina(nomePagina, nomeArquivo);
    InsereListaPagina(listaPagina, novaPagina);
}

// Retirando uma Página da Lista de Página;
void RETIRAPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina)
{
    Pagina *paginaRetirada = RetornaPaginaListaPagina(listaPagina, nomePagina);

    //Se a página existe, executa as funções de Retirar
    if (paginaRetirada)
    {
        RetiraCelulaPaginaListaPagina(listaPagina, nomePagina);
        RetiraLinkListaPagina(listaPagina, nomePagina);
        ApagaPagina(paginaRetirada);
    }

    //Caso contrário, imprime o log de erro;
    else if (paginaRetirada == NULL)
    {
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }
}

// Inserindo Editor na Lista de Editor;
void INSEREEDITOR(FILE *logFile, ListaEditor *listaEditor, char *nomeEditor)
{
    int existeEditor = BuscaEditorListaEditor(listaEditor, nomeEditor);

    //Se não existir, imprime o log de erro;
    if (existeEditor)
    {
        fprintf(logFile, "ERRO: editor de nome %s já existente\n", nomeEditor);
        return;
    }
    //Caso contrário, executa as funções;
    else
    {
        Editor *novoEditor = InicializaEditor(nomeEditor);
        InsereEditorListaEditor(listaEditor, novoEditor);
    }
}

//Insere Link na Lista de Link de uma Página;
void INSERELINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada)
{
    //Verificar se as paginas existem
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaAtual) == 0)
    {
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaAtual);
        return;
    }
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaLinkada) == 0)
    {
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaLinkada);
        return;
    }

    ListaLink *listalinkBuscada = RetornaListaLinkListaPagina(listaPagina, nomePaginaAtual);

    //Verificar se o link já existe;
    if (BuscaLinkListaLink(listalinkBuscada, nomePaginaLinkada) == 1)
    {
        fprintf(logFile, "ERRO: Link de nome %s ja existe na página %s\n", nomePaginaLinkada, nomePaginaAtual);
        return;
    }
    InsereListaLink(listalinkBuscada, RetornaPaginaListaPagina(listaPagina, nomePaginaLinkada));
}

//Retira o Link da Lista de Link de uma Página
void RETIRALINK(FILE *logFile, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada)
{
    //Verificar se as paginas existem
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaAtual) == 0)
    {
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaAtual);
        return;
    }
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaLinkada) == 0)
    {
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaLinkada);
        return;
    }

    // Verificar se o Link existe
    ListaLink *listalinkBuscada = RetornaListaLinkListaPagina(listaPagina, nomePaginaAtual);
    if (BuscaLinkListaLink(listalinkBuscada, nomePaginaLinkada) == 0)
    {
        fprintf(logFile, "ERRO: Link de nome %s não encontrada na página %s\n", nomePaginaLinkada, nomePaginaAtual);
        return;
    }
    RetiraListaLink(listalinkBuscada, nomePaginaLinkada);
}

// Insere Contribuição na Lista de Contribuição
void INSERECONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo)
{
    // Verifica se a página existe;
    if (!BuscaPaginaListaPagina(listaPagina, nomePagina))
    {
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }

    //Verifica se o Editor existe;
    if (!BuscaEditorListaEditor(listaEditor, nomeEditor))
    {
        fprintf(logFile, "ERRO: editor de nome %s não encontrada\n", nomeEditor);
        return;
    }

    //Buscar se a contribuição já foi adicionada
    ListaContribuicao *listaContribuicaoBuscada = RetornaListaContribuicaoListaPagina(listaPagina, nomePagina);

    if (RetornaStatusContribuicaoListaContribuicao(listaContribuicaoBuscada, nomeArquivo) != 2)
    {
        fprintf(logFile, "ERRO: contribuição de arquivo %s já adicionada previamente\n", nomeArquivo);

        return;
    }

    Contribuicao *novaContribuicao = InicializaContribuicao(nomeArquivo);
    Editor *editorBuscado = RetornaEditorListaEditor(listaEditor, nomeEditor);
    InsereListaContribuicao(listaContribuicaoBuscada, novaContribuicao, editorBuscado);
    InsereContribuicaoListaContribuicaoListaEditor(listaEditor, novaContribuicao, nomeEditor);
}

//Retira a Contribuição da Lista de Contribuiçao;
void RETIRACONTRIBUICAO(FILE *logFile, ListaPagina *listaPagina, ListaEditor *listaEditor, char *nomePagina, char *nomeEditor, char *nomeArquivo)
{
    // Verifica se a Página existe;
    if (!BuscaPaginaListaPagina(listaPagina, nomePagina))
    {
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }
    //Verifica se o Editor existe;
    if (!BuscaEditorListaEditor(listaEditor, nomeEditor))
    {
        fprintf(logFile, "ERRO: editor de nome %s não encontrada\n", nomeEditor);
        return;
    }

    //Buscar se há essa contribuição na pagina;
    ListaContribuicao *listaContribuicaoPagina = RetornaListaContribuicaoListaPagina(listaPagina, nomePagina);

    if (RetornaStatusContribuicaoListaContribuicao(listaContribuicaoPagina, nomeArquivo) == 2)
    {
        fprintf(logFile, "ERRO: contribuição de arquivo %s não encontrada\n", nomeArquivo);

        return;
    }

    //Verificar se ja a contribuiçao ja foi apagada;
    ListaContribuicao *listaContribuicaoBuscada = RetornaListaContribuicaoListaEditor(listaEditor, nomeEditor);

    if (RetornaStatusContribuicaoListaContribuicao(listaContribuicaoBuscada, nomeArquivo) == 1)
    {
        fprintf(logFile, "ERRO: contribuição de arquivo %s já retirada previamente\n", nomeArquivo);
        return;
    }
    // Verificar se o editor pode apagar a contribuição;
    Contribuicao *verificaListaContribuicaoEditor = RetornaContribuicaoListaContribuicao(listaContribuicaoBuscada, nomeArquivo);

    //Caso nao for o mesmo editor
    if (verificaListaContribuicaoEditor == NULL)
    {
        fprintf(logFile, "ERRO: editor de nome %s não tem direito de excluir esta contribuição\n", nomeEditor);
        return;
    }

    //Se o editor for o mesmo
    else if (verificaListaContribuicaoEditor)
    {
        AlteraStatusContribuicaoListaContribuicao(listaContribuicaoBuscada, nomeArquivo);
    }
}

//Imprime uma Página da Lista de Página;
void IMPRIMEPAGINA(FILE *logFile, ListaPagina *listaPagina, char *nomePagina)
{
    Pagina *paginaRetirada = RetornaPaginaListaPagina(listaPagina, nomePagina);
    if (paginaRetirada)
    {
        ImprimePaginaCompletaListaPagina(logFile, listaPagina, nomePagina);
    }
    else if (paginaRetirada == NULL)
    {
        fprintf(logFile, "ERRO: pagina de nome %s não encontrada\n", nomePagina);
        return;
    }
}

//Imprime a Wiked toda;
void IMPRIMEWIKED(FILE *logFile, ListaPagina *listaPagina)
{
    ImprimeCompletaListaPagina(logFile, listaPagina);
}

//Verifica se há caminho entre duas Páginas;
void CAMINHO(FILE *logFile, FILE *fileEntrda, ListaPagina *listaPagina, char *nomePaginaAtual, char *nomePaginaLinkada)
{

    //Verifica se as páginas existem
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaAtual) == 0)
    {
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaAtual);
        return;
    }
    if (BuscaPaginaListaPagina(listaPagina, nomePaginaLinkada) == 0)
    {
        fprintf(logFile, "ERRO: pagina de nome %s nao encontrada\n", nomePaginaLinkada);
        return;
    }

    //Verifica se as Páginas são iguais
    Pagina *paginaAtual = RetornaPaginaListaPagina(listaPagina, nomePaginaAtual);
    Pagina *paginaLinkada = RetornaPaginaListaPagina(listaPagina, nomePaginaLinkada);

    if (strcmp(RetornaNomePagina(paginaAtual), RetornaNomePagina(paginaLinkada)) == 0)
    {
        fprintf(logFile, "ERRO: paginas iguais\n");
        return;
    }

    ListaLink *paginasPercorridas = IniciaListaLink();

    CaminhoListaLink(listaPagina, paginasPercorridas, paginaAtual);

    if (RetornaPaginaListaLink(paginasPercorridas, nomePaginaLinkada) == NULL)
    {

        fprintf(logFile, "ERRO: Não há caminho da página %s para a página %s\n", nomePaginaAtual, nomePaginaLinkada);
    }
    else
    {
        fprintf(logFile, "ALERTA: Há caminho da página %s para a página %s\n", nomePaginaAtual, nomePaginaLinkada);
    }

    ApagaListaLink(paginasPercorridas);
}
