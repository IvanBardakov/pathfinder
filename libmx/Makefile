CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_NAME = libmx.a

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(LIB_NAME): $(OBJ_FILES)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

reinstall: uninstall $(LIB_NAME)

uninstall: clean
	rm -rf $(LIB_NAME)

.PHONY: clean reinstall uninstall
