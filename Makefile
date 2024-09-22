TARGET = libgs.a

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CC = gcc -O3

CFLAGS = -Wall -Werror -Wextra -Iinclude

RM = rm -f


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $(TARGET) $(OBJ)

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean:
	$(RM) $(OBJ) $(TARGET)

.PHONY: re
re: fclean all
