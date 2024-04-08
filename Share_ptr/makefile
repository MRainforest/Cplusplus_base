SRC=$(wildcard *.cc)
OBJ=$(patsubst %.cc,%.o,$(SRC))
#INCLUDE=../../include/
LINK=
CXX=g++ -g
TARGET=share_ptr
$(TARGET):$(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LINK)
%.o:%.cc
	$(CXX) $< -c $(LINK)
.PHONY:clean
clean:
	-rm $(OBJ) $(TARGET) 