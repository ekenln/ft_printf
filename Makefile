NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -r
PATH_LIBFT = ../libft/
LIBFT = libft.a

SRCS = ft_printf.c ft_printf_utils.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PATH_LIBFT)$(LIBFT) 
	$(AR) $(NAME) $(OBJ)

$(PATH_LIBFT)$(LIBFT): $(OBJ)
	@make -C $(PATH_LIBFT)
	@cp $(PATH_LIBFT)$(LIBFT) .
	@mv $(LIBFT) $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(PATH_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re