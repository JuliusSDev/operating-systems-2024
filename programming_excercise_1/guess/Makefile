
all: main.c guess.c
	gcc -std=c17 -Wall -Wextra -Werror -o game main.c guess.c
	./game

# Clean up build files
clean:
	rm -f game

.PHONY: all clean