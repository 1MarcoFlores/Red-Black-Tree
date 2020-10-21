all: clean main specs

main: 
	gcc -g -Wall -lm main.c -o main.app
	./main.app < input.txt > output.tmp 
	diff --side-by-side --report-identical-files output.txt output.tmp 
specs:
	gcc -g -Wall -lm specs.c -o specs.app -std=c99
	./specs.app 

clean:
	rm -rf *.app *.tmp
