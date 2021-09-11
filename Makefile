NAME = libftprintf.a

SRC = 	putstr.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_printf.c\
		intg.c\
		hexa.c\
		paddr.c\
		
OB = $(SRC:.c=.o)
HEADER = ft_printf.h
FLAG = 
RM = rm -f

$(NAME):
	gcc $(FLAG) -c $(SRC) -I ./includes
	ar -rc $(NAME) $(OB)
	ranlib $(NAME)

all: $(NAME)

clean:
	${RM} ${OB}

fclean:	clean 
	${RM} ${NAME}

re: 	fclean all
.PHONY: all clean fclean re
