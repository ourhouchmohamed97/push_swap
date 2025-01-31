CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ft_atoi.c \
	  ft_memcpy.c \
	  ft_split.c \
	  ft_strdup.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strchr.c \
	  ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = libft.a

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