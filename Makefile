#Change the right side to "Debug" or "Release" for each mode
TAR := Debug

#Compiler options for Debug and Release
ifeq ($(TAR), Debug)
	OPTS = -Wall -g
else
	OPTS = -Wall
endif


#Location of object files
OBJ_DIR := obj
OBJ_PATH := $(OBJ_DIR)/$(TAR)


#gets all the .c files and .o files
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,$(OBJ_PATH)/%.o,$(SRC))

#Name of executable -- will be the name of the directory where the make command is called (should be same as project name)
BIN_DIR := bin
EXE_PATH := $(BIN_DIR)/$(TAR)
EXE = $(EXE_PATH)/$(notdir $(shell pwd))

all: $(EXE)

run:
	$(EXE) $(ARGS)
#Linker rule
#Links all .o files into executable
# $@ is the target of the rule, ie $(EXE)
# $^ is the dependencies of the rule, ie $(OBJ)
$(EXE) : $(OBJ) | $(EXE_PATH)
	gcc $(OPTS) -o $@ $^

#Compiler rule
#Compiles all the needed .o files from the .c files of the same name
#% is a wildcard similar to *
#$< is the second half of the % statement, ie %.c (so its the relevant .c file)
$(OBJ) : $(OBJ_PATH)/%.o : %.c | $(OBJ_PATH)
	gcc $(OPTS) -o $@ -c $<

$(OBJ_PATH): | $(OBJ_DIR)
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(EXE_PATH): | $(BIN_DIR)
	mkdir $@
$(BIN_DIR):
	mkdir $@

clean:
	rm -r $(OBJ) $(EXE)
