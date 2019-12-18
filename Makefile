COMP=g++
CPPFLAGS=-ansi -pedantic -Wall -std=c++11
REAL=main.cpp Traj.cpp TrajSimp.cpp TrajComp.cpp Cata.cpp
OBJ=$(REAL:.cpp=.o)
EXE=exec

all: ${EXE} clean

main.o: ${REAL}
	${COMP} ${CPPFLAGS} -c ${REAL}

${EXE}: ${OBJ}
	${COMP} ${CPPFLAGS} -o ${EXE} ${OBJ}

debug: CPPFLAGS += -DMAP
debug: all

clean:
	rm *.o

