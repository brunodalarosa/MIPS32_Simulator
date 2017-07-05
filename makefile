simulador: simulador.c tradutor.c lexic.l parser.y utils.c
	bison -d parser.y
	flex lexic.l
	cc -o $@ simulador.c tradutor.c parser.tab.c lex.yy.c utils.c -lfl -I.

clean:
	rm ./simulador
