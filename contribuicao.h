#ifndef CONTRIBUICAO_H_
#define CONTRIBUICAO_H_

typedef struct contribuicao Contribuicao;

// inicializa Contribuicao
Contribuicao *InicializaContribuicao(char *nomeArquivo);

//Imprime os dados da Contribuicao;
void ImprimeContribuicao(Contribuicao *contribuicao);

//Retorna o nome do arquivo da Contribuição;
char *RetornaNomeArquivoContribuicao(Contribuicao *contribuicao);

//Imprime a Contribuição no arquivo da pagina;
void ImprimeArquivoContribuicao(FILE *logFile, FILE *paginaFile, char *nomeArquivoContribuicao);

//Retorna o status da Contribuição;
int RetornaStatusContribuicao(Contribuicao *contribuicao);

// Altera o status da Contribuição
void AlteraStatusContribuicao(Contribuicao *contribuicao);

//Apaga a Contribuição desejada
void ApagaContribuicao(Contribuicao *contribuicao);

#endif //CONTRIBUICAO_H_
