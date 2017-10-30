#include "Gshare.h"
#include <cmath>

Gshare::Gshare() {
	this->history = 0x00000000000;
	this->size = 2048;
	this->historySize = long(pow(2, 11));
}
Gshare::Gshare(float size) {
	this->history = 0x00000000000;
	this->size = 2048;
	this->historySize = long(pow(2, size));
}
bool Gshare::predict(long address, string branch) {
	bool outcome;
	long signBits = address % this->size; 
	
	if(branch == "T") outcome = true;
	else if(branch == "NT") outcome = false;
	
	int location = signBits ^ this->history;
	if(this->table.find(location) == this->table.end()) {
		this->table.insert(pair<int, int>(location, 3));
	}
	
	bool prediction;
	if(this->table.at(location) >= 2) prediction = true;
	else prediction = false;

	if(prediction == outcome) {
		if(this->table.at(location) == 2) this->table.at(location)++;
		else if(this->table.at(location) == 1) this->table.at(location)--;
		this->history = this->history << 1;
		if(outcome) this->history++;
		if(this->history >= this->historySize) this->history -= this->historySize;
		return true;
	}
	else {
		if(this->table.at(location) >= 2) this->table.at(location)--;
		else this->table.at(location)++;
		this->history = this->history << 1;
		if(outcome) this->history++;
		if(this->history >= this->historySize) this->history -= this->historySize;
		return false;
	}
}

