main: main.cpp
	g++ main.cpp shopSystem.cpp -o Lab7

test: main.cpp test.cpp
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 test.cpp main.cpp shopSystem.cpp -o Lab7_Test -D TEST

checkCov:
	gcov test.cpp main.cpp shopSystem.cpp

clear:
	rm -rf *.o *.gcno *.gcda Lab7_Test
