CC = g++
CFLAGS = -std=c++11 -Wall -pedantic

SOURCE_CPP = map_test.cpp 
TARGET_PY = dict_test.py
PLOT = plot.py

DIR_OUT = out_files
FILE_OUT_CPP = $(DIR_OUT)/map_test_out.txt
FILE_OUT_PY = $(DIR_OUT)/dict_test_out.txt

ifeq ($(OS), Windows_NT)
	RM = del
	TARGET_CPP = map_test.exe
else
	RM = rm
	TARGET_CPP = map_test
endif

all:
	$(CC) $(CFLAGS) -o $(TARGET_CPP) $(SOURCE_CPP)

clean:
	$(RM) *.exe

run: all
	$(TARGET_CPP) > $(FILE_OUT_CPP)
	python $(TARGET_PY) > $(FILE_OUT_PY)
	python $(PLOT)