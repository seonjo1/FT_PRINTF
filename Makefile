NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLGS = ar rusc

SRCS = 
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARFLGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $<

clean :
	rm -f $(OBJS)

fclean : 
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all
