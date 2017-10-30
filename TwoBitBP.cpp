#include "TwoBitBP.h"

TwoBitBP::TwoBitBP() {
	this->size = 2048;
}
TwoBitBP::TwoBitBP(int size) {
	this->size = size;
}
bool TwoBitBP::predict(long address, string branch) {
	bool outcome;
	int signBits = address % this->size;

	if(branch == "T") outcome = true;
	else if(branch == "NT") outcome = false;
	
	if(this->table.find(signBits) == this->table.end()) {
		this->table.insert(pair<int, int>(signBits, 3));
	}
	
	bool prediction;
	if(this->table.at(signBits) >= 2) prediction = true;
	else prediction = false;
	
	if(prediction == outcome) {
		if(this->table.at(signBits) == 2) this->table.at(signBits)++;
		if(this->table.at(signBits) == 1) this->table.at(signBits)--;
		return true;
	}
	else {
		if(this->table.at(signBits) >= 2) this->table.at(signBits)--;
		else this->table.at(signBits)++;
		return false;
	}
}

