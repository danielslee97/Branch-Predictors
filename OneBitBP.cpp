#include <cmath>
#include <iostream>
#include "OneBitBP.h"

OneBitBP::OneBitBP() {
	this->size = 2048;
	this->numBits = log2(2048);
}
OneBitBP::OneBitBP(int size) {
	this->size = size;
	this->numBits = log2(this->size);
	//int t(pow(2.0, float(this->numBits)));
	//cout << "THIS: " << t << endl;
	//cout << "NUMBITS: " << this->numBits << endl;
}
bool OneBitBP::predict(int address, string branch) {
	int outcome;
	int signBits = address % int(pow(2.0, float(this->numBits)));
	if(signBits > this->size) throw 0;
	//cout << "ADDRESS: " << address << endl;
	//cout << "SIGNIFICANT BITS: " << signBits << endl;
	if(branch == "T") outcome = 1;
	else if(branch == "NT") outcome = 0;
	//cout << "OUTCOME IS: " << outcome << endl;
	
	if(this->table.find(signBits) == this->table.end()) {
		this->table.insert(pair<int, int> (signBits, 1));
	}
	//cout << "PREDICTION BEFORE IS: " << this->table.at(signBits) << endl;
	if(this->table.at(signBits) == outcome) {
		//cout << "PREDICTION AFTER IS: " << this->table.at(signBits) << "-----RETURNING TRUE" << endl;
		return true;
	}
	else {
		this->table.at(signBits) = outcome;
		//cout << "PREDICTION AFTER IS: " << this->table.at(signBits) << "-----RETURNING FALSE" << endl;
		return false;
	}
	//cout << "MAP SIZE IS: " << this->table.size() << endl;
}

