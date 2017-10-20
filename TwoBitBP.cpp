#include <cmath>
#include <iostream>
#include "TwoBitBP.h"

TwoBitBP::TwoBitBP() {
	this->size = 2048;
	this->numBits = log2(2048);
}
TwoBitBP::TwoBitBP(int size) {
	this->size = size;
	this->numBits = log2(this->size);
}
bool TwoBitBP::predict(int address, string branch) {
	bool outcome;
	int signBits = address % int(pow(2.0, float(this->numBits)));
	if(signBits > this->size) throw 0;
	if(branch == "T") outcome = true;
	if(branch == "NT") outcome = false;
	
	if(this->table.find(signBits) == this->table.end()) {
		this->table.insert(pair<int, int> (signBits, 3));
	}
	
	//cout << "PREDICTION BEFORE: " << this->table.at(signBits);
	bool prediction;
	if(this->table.at(signBits) >= 2) {
		prediction = true;
		//cout << "------ TRUE" << endl;
	}
	else {
		prediction = false;
		//cout << "------ FALSE" << endl;
	}
	
	if(prediction == outcome) {
		if(this->table.at(signBits) == 2) this->table.at(signBits)++;
		else if(this->table.at(signBits) == 1) this->table.at(signBits)--;
		//cout << "PREDICTION AFTER: " << this->table.at(signBits) << "-------RETURNING TRUE\n" << endl;
		return true;
	}
	else {
		if(this->table.at(signBits) >= 2) this->table.at(signBits)--;
		else this->table.at(signBits)++;
		//cout << "PREDICTION AFTER: " << this->table.at(signBits) << "-------RETURNING FALSE\n" << endl;
		return false;
	}
}

