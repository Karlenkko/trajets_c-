CPPFLAGS=-ansi -pedantic –Wall –std=c++11
REAl=main.cpp Traj.cpp TrajSimp.cpp TrajComp.cpp Cata.cpp
OBJ=$(REAL:.cpp=.o)
EXE=exec

all: ${EXE} clean

main.o: ${REAL}
	g++ ${CPPFLAGS} -c ${REAL}

${EXE}: ${OBJ}
	g++ ${CPPFLAGS} -o ${EXE} ${OBJ}

clean:
	rm ${EXE} *.o

