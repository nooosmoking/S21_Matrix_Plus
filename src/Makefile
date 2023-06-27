GCC = gcc
LDFLAGS = -c 
SOURCE := $(shell find ./source  -iname "*.cc" )
TEST_SOURCE := $(shell find ./tests  -iname "*.cc" )
HEADER_SOURCE := $(shell find . -iname "*.h" )

ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -lgtest --coverage -lstdc++
else
	TEST_FLAGS  = -lgtest -lstdc++ -std=c++17 --coverage -lsubunit  
endif

ERROR_FLAGS  =  -Wextra -Wall -Werror -Wuninitialized -Winit-self -Wmaybe-uninitialized -fsanitize=address

all: clean s21_matrix_oop.a test

s21_matrix_oop.a: clean
	$(GCC) $(LDFLAGS) $(ERROR_FLAGS) $(SOURCE)
	ar rc $@  *.o
	ranlib $@

test: ${SOURCE} ${TEST_SOURCE} ${HEADER_SOURCE}
	$(GCC) $(TEST_FLAGS)  $^ -o $@  'pkg-config --cflags --libs gtest'  -I /usr/include/c++/12 -L /usr/local/lib 
	./$@

gcov_report: test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

leaks: test
	leaks -atExit -- ./test

cppcheck: $(SOURCE) $(TEST_SOURCE)
	cppcheck $^;

format: ${SOURCE} ${HEADER_SOURCE}
	cp .././materials/linters/.clang-format .
	clang-format -i -style=google $^;
	rm .clang-format

valgrind: test
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./test
	valgrind --leak-check=full --leak-resolution=high ./test

clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf s21_test
