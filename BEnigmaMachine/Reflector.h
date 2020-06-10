#pragma once

#include <string>
using namespace std;

class Reflector 
{
private:
	// rotorLeft is the input, right is the output (only the rotorRight is rotate)
	string reflectorLeft, reflectorRight;
	string reflectorType;
public:
	Reflector();

	// Methods for setting up reflector
	string getReflectorType();
	void setReflectorType(string type, string reflectorIn);

	string getReflectorLeft();
	string getReflectorRight();

	// Input Method
	char inputChar(char input);
};

