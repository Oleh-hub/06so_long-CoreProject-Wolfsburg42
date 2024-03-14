CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g -O3

NAME			:= so_long
SRCS			:=	so_long.c	\
					99utils.c
OBJS			:= $(SRCS:.c=.o)
OBJS_DIR		:= objs/
OBJS_PREFIXED	:= $(addprefix $(OBJS_DIR), $(OBJS))

MLX_DIR 		:= ./minilibx_macos
MLX_FLAGS 		:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm

LIBFT_DIR		:= ./libft/
LIBFT_FLAGS		:= -L$(LIBFT_DIR) -lft
LIBFT			:= $(LIBFT_DIR)libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_PREFIXED)
	$(CC) $(OBJS_PREFIXED) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
#	 $(CC) $(OBJS_PREFIXED) $(LIBFT_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) $@

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) $@

re: fclean all

$(LIBFT):
	make -C $(LIBFT_DIR) all bonus

$(OBJS_DIR)%.o : %.c so_long.h
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@
#	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

valgrind:
#	valgrind --leak-check=full --show-leak-kinds=all \
			--track-origins=yes ./so_long maps/rectangular.ber
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all \
--track-origins=yes ./so_long maps/rectangular.ber
#	valgrind --read-var-info=yes --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose --log-file=valgrind-out.txt \
	./so_long maps/rectangular.ber

norm:
#	@norminette $(SRCS) so_long.h $(LIBPATH)
	@norminette $(SRCS) so_long.h