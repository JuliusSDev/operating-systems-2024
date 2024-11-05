all: 
	gcc -std=c17 -Wall -Wextra -Werror -o palindrom palindrom.c

run: all palindrom.c
	./palindrom otto,olaf,marcel,anna,uwe,klaus,shrek,fiora,rentner 0:9

format-check:
	clang-format -Werror -n -style='{BasedOnStyle: Google, IndentWidth: 4}' palindrom.c

format:
	clang-format -i -style='{BasedOnStyle: Google, IndentWidth: 4}' palindrom.c

clean:
	rm -rf palindrom
