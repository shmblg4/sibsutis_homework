EXEC = console_app
CC = gcc 
CFLAGS = -Wall -Werror -I./src/simple-pc-lib -I./src/myTerm -I./src/myBigChars
SC_LIB = libsimplepc.a
MT_LIB = libmyTerm.a
BC_LIB = libmyBigChars.a

BIN_PATH = ./bin/
OBJ_PATH = ./obj/
SRC_PATH = ./src/
LIB_PATH = ./lib/

SC_LIB_SRC_PATH = $(SRC_PATH)simple-pc-lib/
SC_LIB_OBJ_PATH = $(OBJ_PATH)src/simple-pc-lib/
MT_LIB_SRC_PATH = $(SRC_PATH)myTerm/
MT_LIB_OBJ_PATH = $(OBJ_PATH)src/myTerm/
BC_LIB_SRC_PATH = $(SRC_PATH)myBigChars/
BC_LIB_OBJ_PATH =$(OBJ_PATH)src/myBigChars/
CONSOLE_PATH = $(SRC_PATH)console/
CONSOLE_OBJ_PATH = $(OBJ_PATH)src/console/

LIB_SRC = $(wildcard $(SC_LIB_SRC_PATH)*.c)
LIB_OBJ = $(patsubst $(SC_LIB_SRC_PATH)%.c, $(SC_LIB_OBJ_PATH)%.o, $(LIB_SRC))

MT_LIB_SRC = $(wildcard $(MT_LIB_SRC_PATH)*.c)
MT_LIB_OBJ = $(patsubst $(MT_LIB_SRC_PATH)%.c, $(MT_LIB_OBJ_PATH)%.o, $(MT_LIB_SRC))

BC_LIB_SRC = $(wildcard $(BC_LIB_SRC_PATH)*.c)
BC_LIB_OBJ = $(patsubst $(BC_LIB_SRC_PATH)%.c, $(BC_LIB_OBJ_PATH)%.o, $(BC_LIB_SRC))

all: $(SC_LIB) $(MT_LIB) $(BC_LIB) $(EXEC)

$(SC_LIB): $(LIB_OBJ)
	@mkdir -p $(LIB_PATH)
	ar rcs $(LIB_PATH)$(SC_LIB) $(LIB_OBJ)

$(SC_LIB_OBJ_PATH)%.o: $(SC_LIB_SRC_PATH)%.c
	@mkdir -p $(SC_LIB_OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $<

$(MT_LIB): $(MT_LIB_OBJ)
	@mkdir -p $(LIB_PATH)
	ar rcs $(LIB_PATH)$(MT_LIB) $(MT_LIB_OBJ)

$(MT_LIB_OBJ_PATH)%.o: $(MT_LIB_SRC_PATH)%.c
	@mkdir -p $(MT_LIB_OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BC_LIB): $(BC_LIB_OBJ)
	@mkdir -p $(LIB_PATH)
	ar rcs $(LIB_PATH)$(BC_LIB) $(BC_LIB_OBJ)

$(BC_LIB_OBJ_PATH)%.o: $(BC_LIB_SRC_PATH)%.c
	@mkdir -p $(BC_LIB_OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXEC): $(CONSOLE_OBJ_PATH)$(EXEC).o
	@mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) $< -o $(BIN_PATH)$(EXEC) -L$(LIB_PATH) -lmyBigChars -lsimplepc -lmyTerm

$(CONSOLE_OBJ_PATH)$(EXEC).o: $(CONSOLE_PATH)$(EXEC).c
	@mkdir -p $(CONSOLE_OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f ./obj/src/simple-pc-lib/*.o
	rm -f ./obj/src/simple-pc/*.o
	rm -f ./obj/src/console/*.o
	rm -f ./obj/src/myTerm/*.o
	rm -f ./obj/src/myBigChars/*.o

run:
	$(BIN_PATH)$(EXEC)	