main: main.cpp
	g++ main.cpp shopSystem.cpp -o Lab7

test: main.cpp test.cpp
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 test.cpp main.cpp shopSystem.cpp -o Lab7_Test -D TEST

checkCov:
	gcov test.cpp

clear:
	rm main.gcda main.gcno shopSystem.gcda shopSystem.gcno test.gcda test.gcno Lab7_Test
