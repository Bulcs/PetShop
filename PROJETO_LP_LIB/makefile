INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -ansi -I. -I$(INC_DIR)
ARCHIVE = ar

linux: veterinario.a anfibio.a mamifero.a reptil.a ave.a petfera

veterinario.a: $(SRC_DIR)/veterinario.cpp $(INC_DIR)/veterinario.h $(INC_DIR)/funcionario.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/veterinario.cpp -o $(OBJ_DIR)/veterinario.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/veterinario.o
	@echo "---- [Bibilioteca Veterinario criada em $(LIB_DIR)/$@] ----"

anfibio.a:$(SRC_DIR)/anfibio.cpp $(INC_DIR)/anfibio.h $(INC_DIR)/animal.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/anfibio.cpp -o $(OBJ_DIR)/anfibio.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/anfibio.o
	@echo "---- [Bibilioteca Anfibio criada em $(LIB_DIR)/$@] ----"

mamifero.a:$(SRC_DIR)/mamifero.cpp $(INC_DIR)/mamifero.h $(INC_DIR)/anfibio.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mamifero.cpp -o $(OBJ_DIR)/mamifero.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/mamifero.o
	@echo "---- [Bibilioteca Mamifero criada em $(LIB_DIR)/$@] ----"

reptil.a:$(SRC_DIR)/reptil.cpp $(INC_DIR)/reptil.h $(INC_DIR)/mamifero.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/reptil.cpp -o $(OBJ_DIR)/reptil.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/reptil.o
	@echo "---- [Bibilioteca Reptil criada em $(LIB_DIR)/$@] ----"
ave.a:$(SRC_DIR)/ave.cpp $(INC_DIR)/ave.h $(INC_DIR)/reptil.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ave.cpp -o $(OBJ_DIR)/ave.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/ave.o
	@echo "---- [Bibilioteca Ave criada em $(LIB_DIR)/$@] ----"

petfera:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/veterinario.a $(LIB_DIR)/anfibio.a $(LIB_DIR)/mamifero.a $(LIB_DIR)/reptil.a $(LIB_DIR)/ave.a -o $(OBJ_DIR)/$@

clean:
	@echo "Removendo arquivos executaveis"
	@rm -rf $(OBJ_DIR)/*