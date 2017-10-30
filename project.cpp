#include <fstream>
#include <iostream>
#include <sstream>
#include "Gshare.h"
#include "OneBitBP.h"
#include "TournamentPredictor.h"
#include "TwoBitBP.h"

using namespace std;

void tournament(ifstream &infile, ofstream &outfile) {
	TournamentPredictor predictor = TournamentPredictor();
	int correct = 0;
	int numBranch = 0;
	
	while(!infile.eof()) {
		string addStr;
		string branch;
			
		infile >> addStr;
		infile >> branch;
		if(branch == "") break;
			
		long address;
		stringstream buf;
		buf << addStr;
		buf >> hex >> address;
			
		if(predictor.predict(address, branch)) correct++;
		numBranch++;
	}
	outfile << correct << "," << numBranch << "; ";
}
void gShare(ifstream &infile, ofstream &outfile) {
	int size = 3;
	while(size <= 11) {
		int correct = 0;
		int numBranch = 0;
		Gshare predictor(size);
		while(!infile.eof()) {
			string addStr;
			string branch;
			
			infile >> addStr;
			infile >> branch;
			if(branch == "") break;
			
			long address;
			stringstream buf;
			buf << addStr;
			buf >> hex >> address;
			
			if(predictor.predict(address, branch)) correct++;
			numBranch++;
		}
		outfile << correct << "," << numBranch << "; ";
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
		int numBranch = 0;
		TwoBitBP predictor(size);
		while(!infile.eof()) {
			string addStr;
			string branch;
			
			infile >> addStr;
			infile >> branch;
			if(branch == "") break;
			
			long address;
			stringstream buf;
			buf << addStr;
			buf >> hex >> address;
			
			if(predictor.predict(address, branch)) correct++;
			numBranch++;
		}
		outfile << correct << "," << numBranch << "; ";
		size *= 2;
		if(size == 64) size *= 2;
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;
}
void oneBit(ifstream &infile, ofstream &outfile) {
	int size = 16;
	while(size <= 2048) {
		int correct = 0;
		int numBranch = 0;
		OneBitBP predictor(size);
		while(!infile.eof()) {
			string addStr;
			string branch;
			
			infile >> addStr;
			infile >> branch;
			if(branch == "") break;
			
			long address;
			stringstream buf;
			buf << addStr;
			buf >> hex >> address;
			
			if(predictor.predict(address, branch)) correct++;
			numBranch++;
		}
		outfile << correct << "," << numBranch << "; ";
		size *= 2;
		if(size == 64) size *= 2;
		infile.clear();
		infile.seekg(0, ios::beg);
	}
	outfile << endl;
}
void alwaysNotTaken(ifstream &infile, ofstream &outfile) {
	int correct = 0;
	int numBranch = 0;
	while(!infile.eof()) {
		string addStr;
		string branch;
		
		infile >> addStr;
		infile >> branch;
		if(branch == "") break;
			
		if(branch == "NT") correct++;
		numBranch++;
	}
	outfile << correct << "," << numBranch << ";" << endl;
}
void alwaysTaken(ifstream &infile, ofstream &outfile) {
	int correct = 0;
	int numBranch = 0;
	while(!infile.eof()) {
		string addStr;
		string branch;
		
		infile >> addStr;
		infile >> branch;
		if(branch == "") break;
			
		if(branch == "T") correct++;
		numBranch++;
	}
	outfile << correct << "," << numBranch << ";" << endl;
}
int main(int argc, char **argv) {
	if(argc != 3) return 1;
	
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
	infile.clear();
	infile.seekg(0, ios::beg);
	
	tournament(infile, outfile);
	infile.close();
	outfile.close();
	
	cout << "\nENDING" << endl;
}
