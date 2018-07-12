INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -ansi -I. -I$(INC_DIR)
ARCHIVE = ar

linux: veterinario.a animal.a  petfera

veterinario.a: $(SRC_DIR)/veterinario.cpp $(INC_DIR)/veterinario.h $(INC_DIR)/funcionario.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/veterinario.cpp -o $(OBJ_DIR)/veterinario.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/veterinario.o
	@echo "---- [Bibilioteca Veterinario criada em $(LIB_DIR)/$@] ----"

animal.a:$(SRC_DIR)/anfibio.cpp $(SRC_DIR)/mamifero.cpp $(SRC_DIR)/reptil.cpp $(SRC_DIR)/ave.cpp $(INC_DIR)/anfibio.h $(INC_DIR)/animal.h $(INC_DIR)/mamifero.h $(INC_DIR)/reptil.h $(INC_DIR)/ave.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/anfibio.cpp -o $(OBJ_DIR)/anfibio.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mamifero.cpp -o $(OBJ_DIR)/mamifero.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/reptil.cpp -o $(OBJ_DIR)/reptil.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ave.cpp -o $(OBJ_DIR)/ave.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/anfibio.o $(OBJ_DIR)/mamifero.o $(OBJ_DIR)/reptil.o $(OBJ_DIR)/ave.o
	@echo "---- [Bibilioteca Animais criada em $(LIB_DIR)/$@] ----"

petfera:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/veterinario.a $(LIB_DIR)/animal.a -o $(OBJ_DIR)/$@

clean:
	@echo "Removendo arquivos executaveis"
	@rm -rf $(OBJ_DIR)/*