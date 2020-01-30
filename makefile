BOOST=-I/usr/local/boost

all:
	g++ $(BOOST) main.cpp -o main.exe
