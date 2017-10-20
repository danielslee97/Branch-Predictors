#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Gshare.h"
#include "OneBitBP.h"
#include "TwoBitBP.h"

using namespace std;

void gShare(ifstream &infile, ofstream &outfile) {
	int size = 3;
	while(size <= 11) {
		int correct = 0;
		int numBranch = -1;
		Gshare predictor(size);
		while(!infile.eof()) {
		//while(correct <= 25) {
			string addStr;
			string branch;
			
			infile >> addStr;
			infile >> branch;
			//cout << addStr << ":   " << branch << endl;
			
			int address;
			stringstream buf;
			buf << addStr;
			buf >> hex >> address;
			//cout << address << endl;
			
			if(predictor.predict(address, branch)) correct++;
			numBranch++;
		}
		//cout << correct << ", " << numBranch << endl;
		outfile << correct << "," << numBranch << "; ";
		//cout << size << "-----------------------------------------------------------------------------" << endl;
		size++;
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;
}
void twoBit(ifstream &infile, ofstream &outfile) {
	int size = 16;
	while(size <= 2048) {
		int correct = 0;
		int numBranch = -1;
		TwoBitBP predictor(size);
		while(!infile.eof()) {
			string addStr;
			string branch;
			
			infile >> addStr;
			infile >> branch;
			//cout << addStr << ":   " << branch << endl;
			
			int address;
			stringstream buf;
			buf << addStr;
			buf >> hex >> address;
			//cout << address << endl;
			
			if(predictor.predict(address, branch)) correct++;
			numBranch++;
		}
		//cout << correct << ", " << numBranch << endl;
		outfile << correct << "," << numBranch << "; ";
		//cout << size << endl;
		size *= 2;
		if(size == 64) size *= 2;
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;
}
void oneBit(ifstream &infile, ofstream &outfile) {
	//vector<int> list3;
	//vector<int> list4;
	int size = 16;
	
	while(size <= 2048) {
		int correct = 0;
		int numBranch = -1;
		//int correct4 = 0;
		OneBitBP oneBitPredictor(size);
		//TwoBitBP twoBitPredictor(size);
		while(!infile.eof()) {
			string addStr;
			string branch;
			
			infile >> addStr;
			infile >> branch;
			//cout << addStr << ":   " << branch << endl;
			
			int address;
			stringstream buf;
			buf << addStr;
			buf >> hex >> address;
			//cout << address << endl;
			
			if(oneBitPredictor.predict(address, branch)) correct++;
			//if(twoBitPredictor.predict(address, branch)) correct4++;
			//cout << "CORRECT: " << correct << '\n' << endl;
			numBranch++;
		}
		//list3.push_back(correct3);
		//list4.push_back(correct4);
		outfile << correct << "," << numBranch << "; ";
		//cout << size << endl;
		size *= 2;
		if(size == 64) size *= 2;
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;
	/*for(int i = 0; i < list3.size(); i++) {
		outfile << list3[i] << ", " << numBranch << "; ";
	}
	outfile << '\n';
	for(int i = 0; i < list4.size(); i++) {
		outfile << list4[i] << ", " << numBranch << "; ";
	}*/
}
void alwaysNotTaken(ifstream &infile, ofstream &outfile) {
	int correct = 0;
	int numBranch = -1;
	while(!infile.eof()) {
		numBranch++;
		string addStr;
		string branch;
		
		infile >> addStr;
		infile >> branch;
		//cout << addStr << ":   " << branch << endl;
			
		if(branch == "NT") correct++;
	}
	outfile << correct << "," << numBranch << ";" << endl;
}
void alwaysTaken(ifstream &infile, ofstream &outfile) {
	int correct = 0;
	int numBranch = -1;
	while(!infile.eof()) {
		string addStr;
		string branch;
		
		infile >> addStr;
		infile >> branch;
		//cout << addStr << ":   " << branch << endl;
			
		if(branch == "T") correct++;
		numBranch++;
	}
	outfile << correct << "," << numBranch << ";" << endl;
}
int main(int argc, char **argv) {
	if(argc < 3 || argc > 3) return 1;
	
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	
	alwaysTaken(infile, outfile);
	infile.clear();
	infile.seekg(0, ios::beg);
	
	alwaysNotTaken(infile, outfile);
	infile.clear();
	infile.seekg(0, ios::beg);
	
	oneBit(infile, outfile);
	infile.clear();
	infile.seekg(0, ios::beg);
	
	twoBit(infile, outfile);
	infile.clear();
	infile.seekg(0, ios::beg);
	
	gShare(infile, outfile);
	infile.close();
	outfile.close();
	
	cout << "\nENDING" << endl;
}
