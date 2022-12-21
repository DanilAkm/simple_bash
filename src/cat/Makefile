CC = gcc
CCF =$(CC) -Wall -Wextra -Werror #-std=c11 -pedantic

s21_cat: s21_cat.o printf_file.o validator.o parse_cat.o
	$(CCF) *.o -o s21_cat

s21_cat.o: s21_cat.c s21_cat.h
	$(CCF) -c s21_cat.c -o s21_cat.o

printf_file.o: printf_file.c s21_cat.h
	$(CCF) -c printf_file.c -o printf_file.o

validator.o: ../common/validator.c ../common/utils.h
	$(CCF) -c ../common/validator.c -o validator.o

parse_cat.o: parse_cat.c
	$(CCF) -c parse_cat.c -o parse_cat.o

cpplint:
	cp ../../materials/linters/CPPLINT.cfg .
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h
	rm CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

test: s21_cat
	chmod +x test.sh
	./test.sh

clean:
	rm -rf *.o ../common/*.o s21_cat
