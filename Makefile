CPPFLAGS =-ansi -pedantic –Wall –std=c++11

exec: main.o Traj.o TrajSimp.o TrajComp.o Cata.o
	g++ -o exec main.o Traj.o TrajComp.o TrajSimp.o Cata.o  

main.o: main.cpp
	g++ -c  main.cpp

TrajComp.o:TrajComp.cpp TrajComp.h
	g++ -c TrajComp.cpp

TrajSimp.o:TrajSimp.cpp TrajSimp.h
	g++ -c TrajSimp.cpp

Traj.o:Traj.cpp Traj.h
	g++ -c Traj.cpp 

Cata.o:Cata.cpp Cata.h
	g++ -c Cata.cpp 

clean:
	rm exec main.o Traj.o TrajComp.o TrajSimp.o Cata.o

