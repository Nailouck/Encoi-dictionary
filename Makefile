all:
	g++ -o main convert.cpp err_proc.cpp dictionary.cpp file_miner.cpp Source.cpp
	./main
	rm main
