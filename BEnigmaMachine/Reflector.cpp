#include "pch.h"
#include "Reflector.h"


Reflector::Reflector()
{
	reflectorLeft = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	reflectorRight = "??????????????????????????";
	reflectorType = "?";
}

// Methods for set and get reflector properties
void Reflector::setReflectorType(string type, string reflectorIn) {
	reflectorRight = reflectorIn;
	reflectorType = type;
}

string Reflector::getReflectorType() {
	return reflectorType;
}

string Reflector::getReflectorLeft() {
	return reflectorLeft;
}

string Reflector::getReflectorRight() {
	return reflectorRight;
}

// input Method
char Reflector::inputChar(char input) {
	return reflectorRight.at(reflectorLeft.find(input));
}