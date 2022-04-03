To execute:

DISC UPC:
	- Executar des de terminal: 
							cat $HOME/assig/cl/tcshrc.CL-GRAU.antlr4 >> ~/.tcshrc && source ~/.tcshrc
	- Modificar Makefile: 	ANTLR_ROOT := $(HOME)/assig/cl/runtime
	- Modificar .sh:		export $HOME/assig/cl/runtime/lib

HOME LINUX:
	- Modificar Makefile: 	ANTLR_ROOT := /usr
	- Modificar .sh:		export LD_LIBRARY_PATH=/usr
