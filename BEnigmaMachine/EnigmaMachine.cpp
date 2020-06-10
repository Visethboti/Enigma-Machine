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

	usePlugBoard = false;
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
	// Choose the rotor number from the 5 options
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

	// Return the string of the rotor number/type inputted
	return rotorRightString;
}

void EnigmaMachine::setReflector(int reflectorNum) {
	// Make the rotor have the string of the rotor number.
	// Choose the reflector type from the 5 options
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

	// Return  the string of the reflector type inputted
	rotorReflector.setReflectorType(reflectorType, rotorRightString);
}


// Print all status of the enigmaMachine (Rotors number...etc)
string EnigmaMachine::getStatus() {
	string status;

	// Create a string of the current status of the rotors and reflector
	status = "|  Rotor  |   Rotor Type  | Rotor Position |            Left            |            Right           | Plug Board | \n";
	status += "|  Rotor1 |      " + to_string(rotor1.getRotorNum()) + "        |        " + to_string(rotor1.getRotorPos()) + "       | " + rotor1.getRotorLeft() + " | " + rotor1.getRotorRight() + " |      " + to_string(usePlugBoard) + "     | \n"; 
	status += "|  Rotor2 |      " + to_string(rotor2.getRotorNum()) + "        |        " + to_string(rotor2.getRotorPos()) + "       | " + rotor2.getRotorLeft() + " | " + rotor2.getRotorRight() + " | " + plugBoard1.getLeft() + " | \n";
	status += "|  Rotor3 |      " + to_string(rotor3.getRotorNum()) + "        |        " + to_string(rotor3.getRotorPos()) + "       | " + rotor3.getRotorLeft() + " | " + rotor3.getRotorRight() + " | " + plugBoard1.getRight() + " | \n";
	status += "|Reflector|  " + rotorReflector.getReflectorType() + "  |  No Position   | " + rotorReflector.getReflectorLeft() + " | " + rotorReflector.getReflectorRight() + " | \n";
	status += "                                           | 0123456789<@#$%>0123456789 | 0123456789<@#$%>0123456789 | 0123456789 |\n";
	// Return the status string
	return status;
}

// Get and Set usePlugBoard
bool EnigmaMachine::getUsePlugBoard() {
	return usePlugBoard;
}
void EnigmaMachine::setUsePlugBoard(bool input) {
	usePlugBoard = input;
}

// Set pairs into the plugboard
void EnigmaMachine::setPlugBoardPair(string inputPair) {
	plugBoard1.setPair(inputPair);
}

// Reset all pairs in teh plug board and set usePlugboard to false
void EnigmaMachine::resetPlugBoard() {
	plugBoard1.resetPair();
	usePlugBoard = false;
}

// Get all existing pair in the plugboard, return a string of left and right. (To prevent duplicate char)
string EnigmaMachine::getAllExistingPairs() {
	return plugBoard1.getLeft() + plugBoard1.getRight();
}

// Debugging Tool
string EnigmaMachine::getDebug() {
	debugTEXT = "Nothing to Debug \n";
	return debugTEXT;
}


// enigma input a char, will manage through the plugBoard (or not) then all 3 rotor and reflector and output back an encypted of that char
char EnigmaMachine::encypt(char input) {
	char result;

	// Going through plugboard;
	if (usePlugBoard)
		result = plugBoard1.crossPlugBoard(input);
	else
		result = input;

	// First rotor
	rotor1.rotate();
	result = rotor1.inputChar(result);
	
	// Check if rotor need to reset and rotate the next rotor (when each rotor make a full revolution)
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
	
	// Going through second and third rotor
	result = rotor2.inputChar(result);
	result = rotor3.inputChar(result);

	// Going through the reflector
	result = rotorReflector.inputChar(result);

	// Go backward from the reflector
	// Going through the third second and then the first rotor from the reverse side
	result = rotor3.reverseInputChar(result);
	result = rotor2.reverseInputChar(result);
	result = rotor1.reverseInputChar(result);

	// Going through plugboard on the way out
	if (usePlugBoard)
		result = plugBoard1.crossPlugBoard(result);

	// Come out the first rotor and result the result char;
	return result;
}