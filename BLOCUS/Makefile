NAME = Blocus
SRC = menu.c \
options.c \
bouton.c \
main.c

OBJ = $(SRC:%.c=%.o)
RM = rm -f


all: $(NAME)

$(NAME): $(OBJ)
    gcc $(OBJ) -o $(NAME) -lgraph

clean: $(RM) $(OBJ)

fclean: clean $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re