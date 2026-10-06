CXX = g++

all: bin/testHashTable bin/testBSTree bin/testBSTreeDict

bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h ListLinked.h List.h Node.h
	mkdir -p bin
	$(CXX) -o bin/testHashTable testHashTable.cpp

bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	$(CXX) -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h BSNode.h Dict.h TableEntry.h
	mkdir -p bin
	$(CXX) -o bin/testBSTreeDict testBSTreeDict.cpp

test: all
	./bin/testHashTable
	./bin/testBSTree
	./bin/testBSTreeDict

clean:
	rm -rf *.o *.gch bin

.PHONY: all test clean
