all: s21_cat s21_grep


s21_cat:
	cd cat && $(MAKE) cat

s21_grep:
	cd grep && $(MAKE) grep

cpplint:
	cd cat && $(MAKE) cpplint
	cd grep && $(MAKE) cpplint
	cd common && $(MAKE) cpplint

cppcheck:
	cd cat && $(MAKE) cppcheck
	cd grep && $(MAKE) cppcheck
	cd common && $(MAKE) cppcheck

tests:
	cd cat && $(MAKE) test
	cd grep && $(MAKE) test

clean:
	cd cat && $(MAKE) clean
	cd grep && $(MAKE) clean