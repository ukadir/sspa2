# use g++ with C++11 support
CXX=g++
CXXFLAGS=-Wall -pedantic -O0 -g -std=c++11
OUTFILES=BSTTest SuccessorTest

all: $(OUTFILES)

BSTTest: BSTTest.cpp BST.cpp
	$(CXX) $(CXXFLAGS) -o BSTTest BSTTest.cpp BST.cpp

SuccessorTest: SuccessorTest.cpp BST.cpp
	$(CXX) $(CXXFLAGS) -o SuccessorTest SuccessorTest.cpp BST.cpp

clean:
	$(RM) $(OUTFILES) *.o