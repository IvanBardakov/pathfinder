CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I$(INC_DIR)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = libmx
LIB = $(LIB_DIR)/libmx.a

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

RES = pathfinder

.PHONY: all libmx pathfinder clean reinstall

all: libmx pathfinder

libmx:
	make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

pathfinder: $(OBJ_FILES) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIB_DIR) -lmx -o $(RES)
aCC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g -I$(INC_DIR)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = libmx
LIB = $(LIB_DIR)/libmx.a

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

RES = pathfinder

.PHONY: all libmx pathfinder clean reinstall

all: libmx pathfinder

libmx:
	make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

pathfinder: $(OBJ_FILES) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIB_DIR) -lmx -o $(RES)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

uninstall:
	rm -rf $(OBJ_DIR) $(RES)
	make -C $(LIB_DIR) uninstall

reinstall: uninstall all

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

uninstall:
	rm -rf $(OBJ_DIR) $(RES)
	make -C $(LIB_DIR) uninstall

reinstall: uninstall all
