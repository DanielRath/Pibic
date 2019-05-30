#Compiler
CC = gcc
CFLAGS = -I include

#Directory of needed files
INC_PATH = include
SRC_PATH = src
OBJ_PATH = obj

#Files needed
INC_FILES = $(wildcard $(INC_PATH)/*.h)
SRC_FILES = $(wildcard $(SRC_PATH)/*.c)
OBJ_FILES = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC_FILES:.c=.o)))


#Executable name
EXEC = Main


#Generate objects files
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_FILES)
	if not exist $(OBJ_PATH) mkdir $(OBJ_PATH)
	$(CC) -c -o $@ $< $(CFLAGS)
	

#Generate executable
$(EXEC): $(OBJ_FILES)
	$(CC) -o $(EXEC) $(OBJ_FILES) $(CFLAGS)



#For debugging purposes (it prints in the screen the value of the desired variable)
ECHO:
	@echo $(OBJ_FILES)
