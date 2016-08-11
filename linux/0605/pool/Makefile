EXE_DIR :=./bin
INC_DIR :=./include
SRC_DIR :=./src
OBJECTS :=$(wildcard $(SRC_DIR)/*.c)
INCLUDES :=$(wildcar $(INC_DIR)/*.h)							  
$(EXE_DIR)/main:$(OBJECTS) $(INCLUDES)
	gcc -g -o $@ $(OBJECTS) -I$(INC_DIR) -lpthread
