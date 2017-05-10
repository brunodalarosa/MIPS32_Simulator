tradutor: tradutor.c lexic.l parser.y
	bison -d parser.y
	flex lexic.l
	cc -o $@ tradutor.c parser.tab.c lex.yy.c -lfl

clean:
	rm ./tradutor
