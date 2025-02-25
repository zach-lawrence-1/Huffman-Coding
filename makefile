all: huffman

chess: huffman.h huffman.cpp
	g++ -std=c++17 -pedantic -Wall -Wextra -g -o huffman huffman.h huffman.cpp