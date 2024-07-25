NAME := libftprintf.a

SRC := ft_print_percent.c \
	ft_print_upper_x.c \
	ft_printc.c \
	ft_printd.c \
	ft_printf.c \
	ft_printp.c \
	ft_prints.c \
	ft_printu.c \
	ft_printx.c

SRC_OBJS = $(SRC:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

all: $(NAME)
$(NAME): $(SRC_OBJS)
	@$(AR) $(NAME) $(SRC_OBJS)
%.o: %.c
	@$(CC) -c $^ -o $@
clean:
	@$(RM) $(SRC_OBJS) $(BONUS_OBJS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
