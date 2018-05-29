#!/bin/bash

CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

animation: main.cpp Animation.cpp
	$(CC) -o animation main.cpp Animation.cpp $(LIBS)


.PHONY: run

run:
	./animation
