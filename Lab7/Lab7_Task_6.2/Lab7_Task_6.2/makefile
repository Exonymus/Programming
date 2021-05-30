main: main.cpp
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 main.cpp shopSystem.cpp test.cpp -o Lab7

test: main.cpp test.cpp
	g++ -o ../Lab7_Test test.cpp shopSystem.cpp main.cpp -D TEST

checkcov:
	gcovr -r .