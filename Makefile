all:
	g++ -o main.o Source.cpp convert.cpp dictionary.cpp
del:
	rm main.o
