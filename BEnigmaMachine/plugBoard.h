#pragma once

#include <string>
using namespace std;

class plugBoard
{
private:
	string left, right;
	int pairCounter;
public:
	plugBoard();

	// get Methods
	string getLeft();
	string getRight();
	void setPair(string inputPair);
	void resetPair();
	char crossPlugBoard(char inputChar);
};

