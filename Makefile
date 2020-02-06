#Makefile for “read_file” C++ application
#Created by Xingyang Zhou 31/1/2020

read_file: read_file.cpp
	g++ -std=c++11 -Wall $^ -o $@

clean:
	rm -f *o read_file
