TARGET = test

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

LIB_PATH = ..

LIB = $(LIB_PATH)/libgs.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(LIB_PATH)/include

RM = rm -f


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ) $(LIB)
	$(CC) $(OBJ) -lcriterion -L$(LIB_PATH) -lgs -o $(TARGET)

$(LIB):
	make -C $(LIB_PATH)

.PHONY: clean
clean:
	make -C $(LIB_PATH) clean
	$(RM) $(OBJ)

.PHONY: fclean
fclean:
	make -C $(LIB_PATH) fclean
	$(RM) $(OBJ) $(TARGET)

.PHONY: re
re: fclean all
