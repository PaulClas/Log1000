
article: Joueur.o Equipe.o main.o
	g++ -o FIFA main.o Joueur.o Equipe.o

Equipe.o: Equipe.cpp Equipe.h
	g++ -o Equipe.o -c Equipe.cpp 

Joueur.o: Joueur.cpp Joueur.h Equipe.h
	g++ -o Joueur.o -c Joueur.cpp

main.o: main.cpp Joueur.h Equipe.h
	g++ -o main.o -c main.cpp 
 
clean: 
	rm *.o
	rm FIFA
