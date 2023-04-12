CC=gcc
CFLAGS=-Wall -Wextra -Werror 

NAME=so_long

SRCS=CC=gcc
CFLAGS=-Wall -Wextra -Werror 

NAME=so_long

SRCS=so_long.c image.c key.c map.c gnl/get_next_line.c gnl/get_next_line_utils.c \
	Libft/ft_bzero.c Libft/ft_calloc.c Libft/ft_itoa.c Libft/ft_memset.c \
	so_Long_utl/check_everything.c so_Long_utl/ft_strdup_without_newline.c so_Long_utl/ft_strjoin_without_newline.c \
	so_long_utl/lose_game.c so_Long_utl/print_error.c so_Long_utl/print.c so_Long_utl/put_image.c so_long_utl/win_game.c\

BSRCS=bonus/so_long_bonus.c bonus/image_bonus.c bonus/key_bonus.c bonus/map_bonus.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c \
	 bonus/Libft/ft_bzero.c bonus/Libft/ft_calloc.c bonus/Libft/ft_itoa.c bonus/Libft/ft_memset.c \
	 bonus/so_long_bonus_utl/check_everything_bonus.c bonus/so_long_bonus_utl/ft_strdup_without_newline_bonus.c bonus/so_long_bonus_utl/print_bonus.c \
	 bonus/so_long_bonus_utl/ft_strjoin_without_newline_bonus.c bonus/so_long_bonus_utl/lose_game_bonus.c bonus/so_long_bonus_utl/print_error_bonus.c \
	 bonus/so_long_bonus_utl/put_image_bonus.c bonus/so_long_bonus_utl/win_game_bonus.c \

BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(OBJCTS) -o $(NAME)

all: $(NAME)

bonus : $(BOBJCTS)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(BOBJCTS) -o so_long_bonus

clean:
		rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
		rm -f $(NAME) so_long_bonus
		
re: fclean all