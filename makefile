
all:	prediction.o
	./predictors short_trace1.txt test.txt

prediction.o:	predictions
	g++ OneBitBP.o TwoBitBP.o Gshare.o project.o -o predictors

predictions:	OneBitBP.h OneBitBP.cpp TwoBitBP.h TwoBitBP.cpp Gshare.h Gshare.cpp project.cpp
	g++ -c OneBitBP.cpp
	g++ -c TwoBitBP.cpp
	g++ -c Gshare.cpp
	g++ -c project.cpp

clean:
	rm *.o predictors
