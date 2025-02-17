NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

DEPS = ./libft/libft.h ./printf/ft_printf.h ./get_next_line/get_next_line.h

LIBFT_SRCS = ./libft/ft_atoi.c \
	  ./libft/ft_memcpy.c \
	  ./libft/ft_split.c \
	  ./libft/ft_strdup.c \
	  ./libft/ft_strlcpy.c \
	  ./libft/ft_strlen.c \
	  ./libft/ft_strchr.c \
	  ./libft/ft_isdigit.c \
	  ./libft/ft_strncmp.c \
	  ./libft/ft_lstnew_bonus.c \
	  ./libft/ft_lstadd_front_bonus.c \
	  ./libft/ft_lstsize_bonus.c \
	  ./libft/ft_lstlast_bonus.c \
	  ./libft/ft_lstadd_back_bonus.c \
	  ./libft/ft_lstclear_bonus.c \

PRINTF_SRCS = ./printf/ft_printf.c \
		./printf/ft_putstr.c \
		./printf/ft_putnbr.c \
		./printf/ft_putchar.c \
		./printf/ft_puthexa.c \
		./printf/ft_putaddr.c \
		./printf/ft_putnbr_unsigned.c \

GNL_SRCS = ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

SRC = $(LIBFT_SRCS) $(PRINTF_SRCS) $(GNL_SRCS)

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
