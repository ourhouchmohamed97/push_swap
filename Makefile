CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap_utils.c \
	sort.c \
	stack_parsing.c \
	stack_parsing_utils.c \
	moves/swap.c \
	moves/rotate.c \
	moves/push.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap.a

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean