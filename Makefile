CC := g++
OBJ = main.o activation.o readIris.o matrixOps.o
TARGET = BasicNN

default: $(TARGET)

$(TARGET): $(OBJ)
	g++ $(OBJ) -o $(TARGET)

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	rm *.o $(TARGET).exe
