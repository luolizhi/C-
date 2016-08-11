EXE_DIR :=./bin
INC_DIR :=./include
SRC_DIR :=./src

OJECTS := ./src/main.c ./src/pool_que.c ./src/pool_pthread.c

INCLUDES :=./include/pool_common.h ./include/pool_que.h ./include/pool_pthread.h
$(EXE_DIR)/main: $(OJECTS) $(INCLUDES)
	gcc -g -o $@ $(OJECTS) -I$(INC_DIR) -lpthread
