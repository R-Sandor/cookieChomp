TARGET=chomp
OBJS=chomp.o game.o cookie.o player.o humanPlayer.o computerPlayer.o
CPPFLAGS=-g

$(TARGET): $(OBJS)
	g++ $(CPPFLAGS) -o $(TARGET) $(OBJS)


all: $(TARGET) chomp1

chomp1: chomp1.cpp
	g++ -o chomp1 $(CPPFLAGS) chomp1.cpp

chomp.o: chomp.cpp game.h humanPlayer.h computerPlayer.h game.h cookie.h
	g++ $(CPPFLAGS) -c $*.cpp

game.o: game.h game.cpp cookie.h
	g++ $(CPPFLAGS) -c $*.cpp

cookie.o: cookie.h cookie.cpp
	g++ $(CPPFLAGS) -c $*.cpp

humanPlayer.o: humanPlayer.h humanPlayer.cpp game.h cookie.h
	g++ $(CPPFLAGS) -c $*.cpp

computerPlayer.o: computerPlayer.h computerPlayer.cpp game.h cookie.h
	g++ $(CPPFLAGS) -c $*.cpp


clean:
	rm $(TARGET) $(OBJS)

sanity: $(TARGET)
	./$(TARGET) 1 < test0.in > test0.out
	@if /usr/bin/cmp test0.out test0.expected; then \
            echo PASSED Sanity Check ;\
          else \
            echo failed sanity check ;\
          fi

