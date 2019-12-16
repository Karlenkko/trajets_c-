CPPFLAGS=-ansi -pedantic -Wall -std=c++11
REAL=main.cpp Traj.cpp TrajSimp.cpp TrajComp.cpp Cata.cpp
OBJ=$(REAL:.cpp=.o)
EXE=exec

all: exec clean

main.o: ${REAL}
	g++ ${CPPFLAGS} -c ${REAL}

exec: ${OBJ}
	g++ ${CPPFLAGS} -o exec ${OBJ}

clean:
	rm *.o

