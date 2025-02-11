NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAN_DIR = ./mandatory
SRC = $(MAN_DIR)/moves/push.c \
	  $(MAN_DIR)/moves/rotate.c \
	  $(MAN_DIR)/moves/r_rotate.c \
	  $(MAN_DIR)/moves/swap.c \
	  $(MAN_DIR)/parsing/stack_parsing.c \
	  $(MAN_DIR)/parsing/stack_parsing_utils.c \
	  $(MAN_DIR)/sort/chunk_sort.c \
	  $(MAN_DIR)/sort/sort.c \
	  $(MAN_DIR)/sort/sort_utils.c \
	  $(MAN_DIR)/main.c \


OBJ = $(SRC:.c=.o)

BONUS = checker
BON_DIR = ./bonus
SRC_BONUS = 

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR = ./libft_utils/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./libft_utils/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

%.o: %.c $(LIBFT_)libft.h $(BON_DIR)/.h 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) include/push_swap.h
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o (BONUS)

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: clean