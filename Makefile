NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLGS = ar rusc

SRCS = ft_printf_number.c ft_printf.c ft_printf_pointer.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARFLGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $<

clean :
	rm -f $(OBJS)

fclean : 
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
