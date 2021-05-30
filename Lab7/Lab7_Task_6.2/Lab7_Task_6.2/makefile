main: main.cpp
	g++ -ansi -o ../Lab7 main.cpp shopSystem.cpp

test: main.cpp test.cpp
	g++ -o ../Lab7_Test test.cpp shopSystem.cpp main.cpp -D TEST

checkcov:
	gcov library