NAME1 = client
NAME2 = servor

BONUS1 = clientBONUS
BONUS2 = servorBONUS

CC = cc
CFLAGS	= -Wall -Wextra -Werror 

SRC1 = client.c 
SRC2 = servor.c ft_printf.c fonc.c heex.c

SRC3 = clientbonis.c 
SRC4 = servorbonis.c ft_printfBONUS.c  foncBONUS.c heex.c

OBJ1= $(SRC1:.c=.o)
OBJ2= $(SRC2:.c=.o)

OBJ1BONUS= $(SRC3:.c=.o)
OBJ2BONUS= $(SRC4:.c=.o)


all: $(NAME1) $(NAME2)

bonus: $(BONUS1) $(BONUS2)

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

$(BONUS1): $(OBJ1BONUS)
	$(CC) $(CFLAGS) $(OBJ1BONUS) -o $(BONUS1)

$(BONUS2): $(OBJ2BONUS)
	$(CC) $(CFLAGS) $(OBJ2BONUS) -o $(BONUS2)

clean:
	rm -rf $(OBJ1)  $(OBJ2) $(OBJ1BONUS) $(OBJ2BONUS)

fclean: clean
	rm -rf $(NAME1) $(NAME2) $(BONUS1) $(BONUS2)

re: fclean all

.PHONY: all clean fclean re bonus
