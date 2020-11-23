#ifndef CONTRIBUICAO_H_
#define CONTRIBUICAO_H_

typedef struct contribuicao Contribuicao;

/*Inicializa Contribuição;
 *inputs: nome do Arquivo dessa contribuição;
 *outputs: (Contribuição*) devidamente inicializado e alocado;
 *pré-condição: string existente;
 *pós-condição: (Contribuicao*) de retorno existente;
*/
Contribuicao *InicializaContribuicao(char *nomeArquivo);

/*Retorna o nome do Arquivo de uma Contribuição;
 *inputs: TAD Contribuição existente;
 *outputs: (char*) com o nome da Contribuição;
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: string de retorno existente;
*/
char *RetornaNomeArquivoContribuicao(Contribuicao *contribuicao);

/*Imprime os dados do arquivo de uma Contribuição;
 *inputs: arquivo de log e arquivo da página, nome do Arquivo da contribuição;
 *outputs: (void);
 *pré-condição: arquivos da página e de log existentes;
 *pós-condição: arquivo da página com as informações da contribuição gravada nele;
*/
void ImprimeArquivoContribuicao(FILE *logFile, FILE *paginaFile, char *nomeArquivoContribuicao);

/*Retorna o status da Contribuição;
 *inputs: TAD Contribuição existente;
 *outputs: (int) com o valor do status da contribuição (RETIRADA = 1; NAORETIRADA = 0);
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: variável (int) de retorno existente;
*/
int RetornaStatusContribuicao(Contribuicao *contribuicao);

/*Altera o status da Contribuição;
 *inputs: TAD Contribuição existente;
 *outputs: (void);
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: status da contribuição modificado;
*/
void AlteraStatusContribuicao(Contribuicao *contribuicao);

/*Apaga a Contribuição desejada
 *inputs: TAD Contribuição existente;
 *outputs: (void);
 *pré-condição: (Contribuicao*) existente;
 *pós-condição: (Contribuicao*) Apagada;
*/
void ApagaContribuicao(Contribuicao *contribuicao);

#endif //CONTRIBUICAO_H_
