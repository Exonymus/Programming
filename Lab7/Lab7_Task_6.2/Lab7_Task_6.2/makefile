main: main.cpp
	g++ main.cpp shopSystem.cpp -o Lab7

test: main.cpp test.cpp
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 test.cpp main.cpp shopSystem.cpp -o Lab7_Test -D TEST

checkCov:
	token: 9e6fa2e6-b250-46e1-aed0-2cef039414a7
	gcov -r .

clear:
	rm main.gcda main.gcno shopSystem.gcda shopSystem.gcno test.gcda test.gcno Lab7_Test
