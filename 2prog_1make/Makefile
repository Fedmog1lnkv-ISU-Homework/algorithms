CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
SOURCE_1 = first.cpp 
SOURCE_2 = second.cpp
FILE = data.txt

ifeq ($(OS), Windows_NT)
	RM = del
	TARGET_1 = main_1.exe
	TARGET_2 = main_2.exe
else
	RM = rm
	TARGET_1 = main_1
	TARGET_2 = main_2
endif

all:
	$(CC) $(CFLAGS) -o $(TARGET_1) $(SOURCE_1)
	$(CC) $(CFLAGS) -o $(TARGET_2) $(SOURCE_2)

clean:
	echo $(OS)
	$(RM) $(TARGET)

run: all
	$(TARGET_1) 5 $(FILE) 
	$(TARGET_2) $(FILE)
