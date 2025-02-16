NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

DEPS = ./include/push_swap.h \

MAN_DIR = ./mandatory
SRC = $(MAN_DIR)/moves/push.c \
	  $(MAN_DIR)/moves/rotate.c \
	  $(MAN_DIR)/moves/r_rotate.c \
	  $(MAN_DIR)/moves/swap.c \
	  $(MAN_DIR)/moves/rest_silent.c \
	  $(MAN_DIR)/parsing/stack_parsing.c \
	  $(MAN_DIR)/parsing/stack_parsing_utils.c \
	  $(MAN_DIR)/sort/chunk_sort.c \
	  $(MAN_DIR)/sort/sort.c \
	  $(MAN_DIR)/sort/sort_utils.c \
	  $(MAN_DIR)/main.c \

OBJ = $(SRC:.c=.o)

BON_DIR = ./bonus
SRC_BONUS = $(BON_DIR)/checker.c \
		$(BON_DIR)/checker_utils.c \
		$(BON_DIR)/checker_list.c \
		$(MAN_DIR)/moves/push.c \
		$(MAN_DIR)/moves/rotate.c \
		$(MAN_DIR)/moves/r_rotate.c \
		$(MAN_DIR)/moves/swap.c \
		$(MAN_DIR)/moves/rest_silent.c \
		$(MAN_DIR)/parsing/stack_parsing.c \
		$(MAN_DIR)/parsing/stack_parsing_utils.c \
		$(MAN_DIR)/sort/chunk_sort.c \
		$(MAN_DIR)/sort/sort.c \
		$(MAN_DIR)/sort/sort_utils.c \

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR = ./libft_utils
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean
