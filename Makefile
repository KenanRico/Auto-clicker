#Compiler
CC := gcc

#Target
TARGET := autoclicker.exe

#Flags
STD := -std=c11
WARNING := -Wall

#Make
acmake:
	$(CC) main.c -o $(TARGET) $(FLAGS) $(WARNING)
