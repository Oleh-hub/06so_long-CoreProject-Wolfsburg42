#libft
DIR_PRINTF	:= 	ft_printf/
NAME		:=	libft.a
SRCS		:=	ft_isalpha.c			\
				ft_isdigit.c			\
				ft_isalnum.c			\
				ft_isascii.c			\
				ft_isprint.c			\
				ft_strlen.c				\
				ft_memset.c				\
				ft_bzero.c				\
				ft_memcpy.c				\
				ft_memmove.c			\
				ft_strlcpy.c			\
				ft_toupper.c			\
				ft_tolower.c			\
				ft_strchr.c				\
				ft_strrchr.c			\
				ft_strncmp.c			\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_calloc.c				\
				ft_strdup.c				\
				ft_strjoin.c			\
				ft_strtrim.c			\
				ft_strmapi.c			\
				ft_putchar_fd.c			\
				ft_putstr_fd.c			\
				ft_putendl_fd.c			\
				ft_strlcat.c			\
				ft_strnstr.c			\
				ft_striteri.c			\
				ft_itoa.c				\
				ft_atoi.c				\
				ft_split.c				\
				ft_substr.c				\
				ft_putnbr_fd.c 			\
				ft_atol.c				\
				$(DIR_PRINTF)ft_printf.c\
				$(DIR_PRINTF)upxx_out.c	
				
SRCS_BONUS	:=	ft_lstnew.c				\
				ft_lstadd_front.c		\
				ft_lstsize.c			\
				ft_lstlast.c			\
				ft_lstadd_back.c		\
				ft_lstdelone.c 			\
				ft_lstclear.c			\
				ft_lstiter.c			\
				ft_lstmap.c


OBJS		:=	$(SRCS:.c=.o)
OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)
CFLAGS		:=  -Wall -Wextra -Werror -g
CC			:=	gcc

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# %.o: %.c
# .c.o:
# 	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)