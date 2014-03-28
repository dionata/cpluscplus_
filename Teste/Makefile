
CC = g++
CFLAGS = -c -Wall -Iinclude 
LIB = -lpthread
LDFLAGS =
#SRC = $(wildcard SRC/*.cpp) #rever
SRC = main.cpp socketcliente_test.cpp socketserver.cpp Teste01.cpp Teste02.cpp teste03.cpp \
      socketcliente.cpp  socketclinte_test.cpp   socketserver_test.cpp  Teste01_test.cpp  Teste02_test.cpp  teste03_test.cpp

BIN = bin
TMP = tmp
OBJ=$(foreach S, $(SRC), $(TMP)/$(S:.cpp=.o))
#OBJ = $(subst .c,.o, $(subst /SRC/,/tmp/, $(SRC)))

EXEC = server

all: $(BIN) $(TMP) $(EXEC) install

$(EXEC):$(OBJ)
	@echo "Gerando $(EXEC)"
	$(CC) $(LDFLAGS) $(LIB) $^ -o $(EXEC)

$(TMP)/%.o:SRC/%.cpp
	@echo "Compilando $<"
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

$(BIN):
	@echo "Criando o diretorio BIN"
	@mkdir -p $(BIN)
$(TMP):
	@echo "Criando o diretorio OBJ"
	@mkdir -p $(TMP)
install:
	@mv server bin
clean:
	@echo "Removendo arquivos..."
	@rm -rf $(TMP)
	@rm -rf $(BIN)
