CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
LDFLAGS=-lcheck -lpthread -lrt -lm -lsubunit 
C_FILES=*.c 
O_FILES=$(patsubst %.c, %.o, $(C_FILES))
TESTS_SOURCE=tests/*.c
BRANCHES=--rc lcov_branch_coverage=1

all: s21_string.a

s21_string.a: all_functions
	ar rcs s21_string.a $(O_FILES)
	ranlib s21_string.a

all_functions: $(C_FILES)
	gcc -c $(CFLAGS) $(C_FILES)

test: s21_string.a
	$(CC)  tests/*.c *.c $(LDFLAGS) --coverage -I. -o test
	./test

gcov_report: test
	./test
	lcov --capture --directory . --output-file test.info $(BRANCHES)
	lcov --remove test.info '/usr/include/*' '*/tests/*' --output-file test.info $(BRANCHES)
	genhtml test.info --output-directory coverage_report $(BRANCHES)
	open google-chrome coverage_report/index.html

clang-i:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.c tests/*.c *.h tests/*.h

clang-n:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c tests/*.c *.h tests/*.h

valgrind-test:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --quiet ./test

# --quiet

clean:
	rm -rf *.o *.gcda *.gcno test *.a
	rm -rf coverage_report test.info .clang-format
  
rebuild: clean all
