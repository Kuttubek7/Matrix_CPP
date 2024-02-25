CC=g++
CFLAGS=-Wall -Werror -Wextra -std=c++17

all: s21_matrix_oop.a test

s21_matrix_oop.a: 
	$(CC) -c $(CFLAGS) -lstdc++ s21_matrix_oop.cc -o s21_matrix_oop.o -pedantic
	ar rc s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a	
	rm *.o

test: s21_matrix_oop.a 
	$(CC) -c $(CFLAGS) test.cc -o test.o -pedantic -fsanitize=address
	$(CC) test.o -o test -L/path/to/gtest/lib -lgtest -lstdc++ -std=c++17 s21_matrix_oop.a -lm -pedantic -fsanitize=address
	./test

# clang:
# 	cp ../materials/linters/.clang-format ../src/.clang-format;
# 	clang-format -i --style=google *.cc *.h
# 	clang-format -style=Google -n *.cc *.h;
# 	rm .clang-format

# heap_summary: test
# 	valgrind --leak-check=full --track-origins=yes ./test

clean:
	rm -rf a.out *.gch *.o *.a test *.gcno *.gcda 