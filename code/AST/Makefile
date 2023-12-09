RM		= rm -f

ifdef VERBOSE
DEBUG ?= $(VERBOSE)
endif

all: compo ast_test

compo: out
	flex -o src/lex.yy.c src/scanner.l
	gcc src/lex.yy.c -lfl -o out/compo

ast_test: out
	gcc src/ast_tests.c src/ast.c -lfl -o out/ast_tests

out:
	mkdir -p out

.PHONY: clean re

clean:
	$(RM) out/compo out/ast_tests src/lex.yy.c

re: clean all
