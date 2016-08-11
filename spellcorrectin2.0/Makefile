INC_DIR:=./inc/ ./inc/net/ ./inc/threadpool/
SRC_SIR:=./src/ ./src/net/ ./src/threadpool/
SRCS:=$(wildcard ./src/*.cc) $(wildcard ./src/net/*.cc) $(wildcard ./src/net/*.c) $(wildcard ./src/threadpool/.*cc)
#OBJS:=$(patsubst %.cc, %.cco, $(SRCS)) $(patsubst %.c, %.co, $(SRCS))
LIBS:=-lpthread

CXX:= g++
CXXFLAGS:=-Wall -g -std=c++11 $(addprefix -I, $(INC_DIR)) $(LIBS)

EXE:=./bin/main	

$(EXE):$(SRCS)
	$(CXX) -o $@ $(SRCS) $(CXXFLAGS)
clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
