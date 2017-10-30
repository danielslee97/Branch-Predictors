#include "OneBitBP.h"

OneBitBP::OneBitBP() {
	this->size = 2048;
}
OneBitBP::OneBitBP(int size) {
	this->size = size;
}
bool OneBitBP::predict(long address, string branch) {
	int outcome;
	int signBits = address % this->size;

	if(branch == "T") outcome = 1;
	else if(branch == "NT") outcome = 0;
	
	if(this->table.find(signBits) == this->table.end()) {
		this->table.insert(pair<const int, int>(signBits, 1));
	}
	
	if(this->table[signBits] == outcome) return true;
	else {
		this->table[signBits] = outcome;
		return false;
	}
}

