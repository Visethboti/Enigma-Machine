#pragma once

#include "Rotor.h"
#include "Reflector.h"

class EnigmaMachine {
private:
	// Rotor and reflector options
	string rotorI, rotorII, rotorIII, rotorIV, rotorV;
	string reflectorA, reflectorB, reflectorC, reflectorBThin, reflectorCThin;

	// Rotors
	Rotor rotor1;
	Rotor rotor2;
	Rotor rotor3;
	Reflector rotorReflector;

	// Help method for setting up rotor and reflector
	string setRotor(int rot1num);
	void setReflector(int reflectorNum);

	//debug text
	string debugTEXT;
public:
	EnigmaMachine();

	// Methods for setting up rotor/reflector position and number
	void enigmaSetup(int rot1num, int rot2num, int rot3num, int rot1pos, int rot2pos, int rot3pos, int reflectorNum);

	// Print status
	string getStatus();

	// Debugging Tool
	string getDebug();

	// Enigma input, encypt()
	char encypt(char input);
};

