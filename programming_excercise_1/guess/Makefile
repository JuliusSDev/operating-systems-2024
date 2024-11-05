
all: main.c guess.c
	gcc -std=c17 -Wall -Wextra -Werror -o game main.c guess.c

run: all main.c guess.c
	./game

format-check:
	clang-format -Werror -n -style='{BasedOnStyle: Google, IndentWidth: 4}' main.c guess.c

format:
	clang-format -i -style='{BasedOnStyle: Google, IndentWidth: 4}' main.c guess.c
	
# Clean up build files
clean:
	rm -f game

.PHONY: all clean