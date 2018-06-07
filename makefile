#!/bin/bash

CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lstdc++fs

animation: *.cpp
	$(CC) -o animation *.cpp $(LIBS)


.PHONY: run

run:
	./animation
