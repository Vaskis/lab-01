// Lab01.cpp
// Jeremiah Vaskis
// COSCO 2030
// Lab 01
// September 17 2018

// A program that attempts to open and read a file and then output:
//	the total count of numbers
//	the first and second numbers
//	the second to last and last numbers
// No containers allowed and the read loop must be accomplished via a .fail()


#include<iostream>
using namespace std;
using std::cout;

#include<string>
using std::string;

#include<fstream>
using std::ifstream;
using std::ofstream;
using std::getline;


// Prototyped functions
string getFileName();
void checkOpeness(string file, ifstream& inFile);


int main() {

	// Variables
	double num1, num2, num3, num4 = 0;
	string fileName;
	ifstream inFile;
	
	fileName = getFileName();
	
	checkOpeness(fileName, inFile);
	

	// Read data from file
	double temp;
	int count = 0;

	// .fail() will "fail" as soon as the datatype it is reading is not whitespace or a number
	// .oef() will read until the end of the file, the else statement filter out the garbage
	while (!inFile.fail() /* !inFile.oef()*/){ 
		if (inFile >> temp){			
			if (count == 0){
				num1 = temp;
				count = count + 1;
			}
			else if (count == 1){
				num2 = temp;
				count = count + 1;
			}
			else if (count == 2){
				num3 = temp;
				count = count + 1;
			}
			else if (count == 3){
				num4 = temp;
				count = count + 1;
			}
			else if (count > 3){
				num3 = num4;
				num4 = temp;
				count = count + 1;
			}
			inFile.clear();
			inFile.ignore();
		}
		// This will glitch out the .fail(), but this lets .eof() filter out all non-numbers
		/*else{
			inFile.clear();
			inFile.ignore();
		}*/
	}

	// Close file
	inFile.close();

	if (count >= 4) {
		cout << "\nReached the end of:    " << fileName << endl;
		cout << "Number of numbers:     " << count << endl;
		cout << "First number:          " << num1 << endl;
		cout << "Second number:         " << num2 << endl;
		cout << "Second to last number: " << num3 << endl;
		cout << "Last number:           " << num4 << endl << endl;
	}
	else if (count == 3) {
		cout << "\nReached the end of:    " << fileName << endl;
		cout << "Number of numbers:     " << count << endl;
		cout << "First number:          " << num1 << endl;
		cout << "Second number:         " << num2 << endl;
		cout << "Second to last number: " << num2 << endl;
		cout << "Last number:           " << num3 << endl << endl;
	}
	else if (count == 2) {
		cout << "\nReached the end of:    " << fileName << endl;
		cout << "Number of numbers:     " << count << endl;
		cout << "First number:          " << num1 << endl;
		cout << "Second number:         " << num2 << endl;
		cout << "Second to last number: " << num1 << endl;
		cout << "Last number:           " << num2 << endl << endl;
	}
	else if (count == 1) {
		cout << "\nReached the end of:    " << fileName << endl;
		cout << "Number of numbers:     " << count << endl;
		cout << "First number:          " << num1 << endl;
		cout << "Last number:           " << num1 << endl << endl;
	}
	else if (count == 0) {
		cout << "\nReached the end of:    " << fileName << endl;
		cout << "***There where no numbers present***" << endl << endl;
		cout << "Number of numbers:     " << count << endl;
	}

	system("pause");

	return 0;
}

// Function definitions

string getFileName() {
	string name;
	cout << "Enter filename: ";
	cin >> name;
	return name;
}

void checkOpeness(string file, ifstream& inFile) {
	inFile.open(file); // Try to Open File
	// If not open, then stop program
	if (!inFile.is_open()) {
		cout << "File: " << file << " cannot be opened." << endl;
		inFile.close();
		inFile.clear();
		system("pause");
		exit(1);
	}
}