CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ../Joueur.cpp ../Equipe.cpp
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

FIFATests: JoueurTest.h main.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm FIFATests

