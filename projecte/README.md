## To compile:

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


## To execute:

#### Basic Individual Tests:

```shell
./asl ../jps/jp_chkt_01.asl
```

#### TVM Tests:

```shell
./asl ../examples/jp_genc_01.asl > code.t
../tvm/tvm code.t < ../examples/jp_genc_01.in
```



