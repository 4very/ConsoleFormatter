# makefile made to compile https://github.com/sommea/ConsoleFormatter

output = "formatter"

formatter: base.o
	@g++ -o $(output) base.o

base.o: base.cpp
	@g++ -c -o base.o base.cpp

clean:
	@rm *.o $(output)

run:
	@./$(output)