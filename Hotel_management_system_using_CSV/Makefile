output: main.o Room.o hotelManager.o
	g++ main.o Room.o hotelManager.o -o output

main.o: main.cpp
	g++ -c main.cpp

Room.o: Room.cpp Room.h
	g++ -c Room.cpp

hotelManager.o: hotelManager.cpp hotelManager.h
	g++ -c hotelManager.cpp

clean: 
	rm *.o output
