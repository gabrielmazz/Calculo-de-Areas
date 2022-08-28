CC = g++
CFLAGS = -O2 -march=native
NAME = areas
NAME_MODULE = extras

run:
	clear
	$(CC) $(NAME).cpp $(NAME_MODULE).cpp -o $(NAME)
	./$(NAME)