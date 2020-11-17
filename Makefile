#
# Makefile
#
# Trabalho 1
# Estrutura de Dados 1
#

wiked: main.c contribuicao.c editor.c listaLink.c pagina.c listaEditor.c listaPagina.c
	gcc -ggdb -std=c99 -Wall -Werror -o wiked.out *.c

clean:
	rm -f *.o a.out core wiked.out

run: 
	valgrind --leak-check=full --show-leak-kinds=all ./wiked.out -s