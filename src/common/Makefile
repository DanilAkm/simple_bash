cpplint:
	cp ../../materials/linters/CPPLINT.cfg .
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h
	rm CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=unusedFunction --suppress=missingIncludeSystem *.c *.h