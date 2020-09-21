.PHONY: all clean

CPP = g++ 
MATRIX_FLAGS = -Iinclude/
CPP_FLAGS = -std=c++14 -g -o

# create build directory
CREATE_DIR : $(shell mkdir -p ./build)

# compile /examples dir with options to compile single
%: $(CREATE_DIR) ./examples/%.cpp
	@# @echo compiling $@.cpp
	@$(CPP) $^ $(MATRIX_FLAGS) $(CPP_FLAGS) ./build/$@
	@echo executable ./build/$@ created. 


# or all files 
all: $(patsubst ./examples/%.cpp, %, $(wildcard ./examples/*.cpp))

clean: 
	rm -rf ./build
	@echo built binaries cleared.

