SRC=$(wildcard *.cc)
OBJ=$(patsubst %.cc,%.o,$(SRC))
TARGET=unique_ptr
CXX=g++ -g
$(TARGET):$(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)
%.o:%.cc
	$(CXX) $< -c
.PHONY:clean
clean:
	-rm $(OBJ) $(TARGET) 