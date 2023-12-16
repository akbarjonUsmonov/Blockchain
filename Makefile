CC := gcc
CFLAGS := -g -Wall -Wextra -Werror #-g3 -fsanitize=address
SRC_DIR := blockchain/c
TARGET := my_blockchain

SRC := $(wildcard $(SRC_DIR)/*.c)

all: $(TARGET)

$(TARGET): $(SRC)
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f $(TARGET)

fclean: clean
	@rm -f $(TARGET)

.PHONY: all clean fclean