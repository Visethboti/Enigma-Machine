#include "pch.h"
#include "EnigmaMachine.h"

// Constructor
EnigmaMachine::EnigmaMachine()
{
	// Initialize rotor and reflector with the value (Got from Wiki)
	rotorI = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
	rotorII = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
	rotorIII = "JVIUBHTCDYAKEQZPOSGXNRMWFL";
	rotorIV = "QYHOGNECVPUZTFDJAXWMKISRBL";
	rotorV = "QWERTZUIOASDFGHJKPYXCVBNML";

	reflectorA = "EJMZALYXVBWFCRQUONTSPIKHGD";
	reflectorB = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
	reflectorC = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
	reflectorBThin = "ENKQAUYWJICOPBLMDXZVFTHRGS";
	reflectorCThin = "RDOBJNTKVEHMLFCWZAXGYIPSUQ";
}

// Set up the rotor and reflector's position and number from the option
void EnigmaMachine::enigmaSetup(int rot1num, int rot2num, int rot3num, int rot1pos, int rot2pos, int rot3pos, int reflectorNum) {
	
	//Setup the three rotors
	rotor1.setRotorNum(rot1num, setRotor(rot1num));
	rotor1.setRotorPos(rot1pos);

	rotor2.setRotorNum(rot2num, setRotor(rot2num));
	rotor2.setRotorPos(rot2pos);

	rotor3.setRotorNum(rot3num, setRotor(rot3num));
	rotor3.setRotorPos(rot3pos);
	
	// Setup reflector
	setReflector(reflectorNum);
}

string EnigmaMachine::setRotor(int rotnum) {
	// Make the rotor have the string of the rotor number.
	string rotorRightString;
	switch (rotnum) {
	case 1:
		rotorRightString = rotorI;
		break;
	case 2:
		rotorRightString = rotorII;
		break;
	case 3:
		rotorRightString = rotorIII;
		break;
	case 4:
		rotorRightString = rotorIV;
		break;
	case 5:
		rotorRightString = rotorV;
		break;
	}

	// Return the numbered rotor string
	return rotorRightString;
}

void EnigmaMachine::setReflector(int reflectorNum) {
	// Make the rotor have the string of the rotor number.
	string rotorRightString, reflectorType;
	switch (reflectorNum) {
	case 1:
		rotorRightString = reflectorA;
		reflectorType = "Reflector A";
		break;
	case 2:
		rotorRightString = reflectorA;
		reflectorType = "Reflector B";
		break;
	case 3:
		rotorRightString = reflectorC;
		reflectorType = "Reflector C";
		break;
	case 4:
		rotorRightString = reflectorBThin;
		reflectorType = "Reflector B Thin";
		break;
	case 5:
		rotorRightString = reflectorCThin;
		reflectorType = "Reflector C Thin";
		break;
	}

	// Return the type's rotor string
	rotorReflector.setReflectorType(reflectorType, rotorRightString);
}


// Print all status of the enigmaMachine (Rotors number...etc)
string EnigmaMachine::getStatus() {
	string status;

	status = "|   Rotor   |    Rotor Type   |   Rotor Position   |            Left            |            Right           | \n";
	status += "|   Rotor 1 |       " + to_string(rotor1.getRotorNum()) + "         |          " + to_string(rotor1.getRotorPos()) + "         | " + rotor1.getRotorLeft() + " | " + rotor1.getRotorRight() + " | \n";
	status += "|   Rotor 2 |       " + to_string(rotor2.getRotorNum()) + "         |          " + to_string(rotor2.getRotorPos()) + "         | " + rotor2.getRotorLeft() + " | " + rotor2.getRotorRight() + " | \n";
	status += "|   Rotor 3 |       " + to_string(rotor3.getRotorNum()) + "         |          " + to_string(rotor3.getRotorPos()) + "         | " + rotor3.getRotorLeft() + " | " + rotor3.getRotorRight() + " | \n";
	status += "| Reflector |   " + rotorReflector.getReflectorType() + "   |    No Position     | " + rotorReflector.getReflectorLeft() + " | " + rotorReflector.getReflectorRight() + " | \n";

	return status;
}



// Debugging Tool
string EnigmaMachine::getDebug() {
	debugTEXT = "Nothing to Debug \n";
	return debugTEXT;
}


// enigma input a char, will manage through all 3 rotor and output back an encypte of that char
char EnigmaMachine::encypt(char input) {
	char result;
	rotor1.rotate();
	result = rotor1.inputChar(input);
	
	// reset rotor and rotate the next rotator
	if (rotor1.getRotorPos() > 27) {
		rotor1.resetPos();
		rotor2.rotate();
		if (rotor2.getRotorPos() > 27) {
			rotor2.resetPos();
			rotor3.rotate();
			if (rotor3.getRotorPos() > 27) {
				rotor3.resetPos();
			}
		}
	}
	
	result = rotor2.inputChar(result);
	result = rotor3.inputChar(result);

	result = rotorReflector.inputChar(result);

	// Go backward from the reflector
	result = rotor3.reverseInputChar(result);
	result = rotor2.reverseInputChar(result);
	result = rotor1.reverseInputChar(result);

	return result;
}