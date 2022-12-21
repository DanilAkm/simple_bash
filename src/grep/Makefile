CC = gcc
CCF =$(CC) -Wall -Wextra -Werror #-std=c11 -pedantic -fsanitize=address

s21_grep: s21_grep.o parse_grep.o validator.o print_grep.o get_file_regex.o
	$(CCF) *.o -o s21_grep

s21_grep.o: s21_grep.c
	$(CCF) -c s21_grep.c

parse_grep.o: parse_grep.c
	$(CCF) -c parse_grep.c

validator.o: ../common/validator.c
	$(CCF) -c ../common/validator.c

print_grep.o: print_grep.c
	$(CCF) -c print_grep.c

get_file_regex.o: get_file_regex.c
	$(CCF) -c get_file_regex.c

cpplint:
	cp ../../materials/linters/CPPLINT.cfg .
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h
	rm CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

memory: s21_grep
	leaks --atExit -- ./s21_grep -e for -e while -f pattern s21_grep.c Makefile print_grep.c -n
	rm -rf *.o s21_grep

test_ez:
	chmod +x test.sh
	./test.sh

test: s21_grep
	chmod +x test_improved.sh
	./test_improved.sh

clean:
	rm -rf *.o s21_grep

rb: clean s21_grep
