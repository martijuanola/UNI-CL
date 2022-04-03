## To execute:

#### DISC UPC:

- Executar des de terminal: 

```shell
cat $HOME/assig/cl/tcshrc.CL-GRAU.antlr4 >> ~/.tcshrc && source ~/.tcshrc
```

- Modificar Makefile:

```makefile
ANTLR_ROOT := $(HOME)/assig/cl/runtime
```

- Modificar .sh:

```bash
export $HOME/assig/cl/runtime/lib
```



#### HOME LINUX:

 - Modificar Makefile:

```makefile
ANTLR_ROOT := /usr
```

 - Modificar .sh:

```bash
export LD_LIBRARY_PATH=/usr
```





