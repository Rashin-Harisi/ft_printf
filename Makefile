NAME		= libftprintf.a

SRC			= ft_printf.c\
			  check_flags_bonus.c\
			  helper_print_decimal.c\
			  ft_uitoa.c\
			  print_char.c\
			  print_decimal.c\
			  print_hex_big.c\
			  print_hex_small.c\
			  ft_hex_convert.c\
			  print_pointer.c\
			  print_string.c\
			  print_unsigned.c
OBJ			= $(SRC:.c=.o)

LIBFT_PATH  = ./libft
LIBFT		= $(LIBFT_PATH)/libft.a


CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

bonus: all


$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all bonus clean fclean re 
