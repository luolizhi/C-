EXE_DIR :=./bin
INC_DIR :=./include
SRC_DIR :=./src

OBJECT := ./src/main.c ./src/pool_que.c ./src/pool_pthread.c

INCLUDES :=./include/pool_common.h ./include/pool_que.h ./include/pool_pthread.h
$(EXE_DIR)/main: $(OBJECT) $(INCLUDES)
	gcc -g -o $@ $(OBJECT) -l$(INC_DIR) -lpthread
