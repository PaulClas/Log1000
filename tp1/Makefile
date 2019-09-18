
obj=$(subst src,build,$(src:.cpp=.o))
trg=build/pari.out

all:$(trg)
	mkdir -p site
	cp build/*.o site
	cp build/*.out site
	cp data/*.txt site

build/pari.out:build/main.o build/SomeKeyHash.o build/HashMap.o
	g++ build/main.o build/SomeKeyHash.o build/HashMap.o -o build/pari.out

build/main.o:src/main.cpp 
	g++ -c src/main.cpp -o build/main.o

build/SomeKeyHash.o:src/SomeKeyHash.cpp src/SomeKeyHash.h
	g++ -c src/SomeKeyHash.cpp -o build/SomeKeyHash.o

build/HashMap.o:src/HashMap.cpp src/HashMap.h src/HashNode.h src/SomeKeyHash.h
	g++ -c src/HashMap.cpp -o build/HashMap.o

vars:
	@echo "trg = $(trg)"


clean:
	rm -rf build/*.o build/*.out
mrproper: clean
	rm -r -f site
