CC = g++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors -l mingw32
INCLUDE_PATH = -Iinclude/
LIBS_PATH = -Llib/SDL2 -Llib/lua
SRC_FILES = src/*.cpp src/Game/*.cpp src/Logger/*.cpp src/ECS/*.cpp src/AssetStore/*.cpp
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -llua54
OBJ_NAME = output/main
OUTDIR = output

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(LIBS_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	make build
	make copy-dlls
	make exec

exec: output/main.exe
	./output/main

copy-dlls: $(wildcard external/windows/dll/*.dll)
	cp $? output

clean:
	rm -rf ${OUTDIR}/* 