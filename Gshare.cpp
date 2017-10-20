#include "Gshare.h"
#include <cmath>
#include <iostream>

Gshare::Gshare() {
	this->history = 0x00000000000;
	this->size = 2048;
	this->historySize = pow(2, 11);
	this->numBits = log2(2048);
}
Gshare::Gshare(float size) {
	this->history = 0x00000000000;
	this->size = 2048;
	this->historySize = int(pow(2, size));
	this->numBits = log2(2048);
}
bool Gshare::predict(int address, string branch) {
	bool outcome;
	int signBits = address % int(pow(2.0, float(this->numBits)));
	
	if(signBits > this->size) throw 0;
	if(branch == "T") outcome = true;
	if(branch == "NT") outcome = false;
	
	int location = signBits ^ this->history;
	if(this->table.find(location) == this->table.end()) {
		this->table.insert(pair<int, int>(location, 3));
	}
	
	bool prediction;
	if(this->table.at(location) >= 2) {
		prediction = true;
	}
	else {
		prediction = false;
	}
	//cout << "PREDICTION BEFORE: " << this->table.at(location) << endl;
	//cout << "HISTORY BEFORE: " << this->history << endl;
	if(prediction == outcome) {
		if(this->table.at(location) == 2) this->table.at(location)++;
		else this->table.at(location)--;
		this->history = this->history << 1;
		if(outcome) this->history++;
		//cout << "HISTORY AFTER: " << this->history << endl;
		if(this->history >= this->historySize) this->history -= this->historySize;
		//cout << "HISTORY AFTER AFTER: " << this->history << endl;
		//cout << "PREDICTION AFTER: " << this->table.at(location) << '\n' << endl;
		return true;
	}
	else {
		if(this->table.at(location) >= 2) this->table.at(location)--;
		else this->table.at(location)++;
		this->history = this->history << 1;
		if(outcome) this->history++;
		//cout << "HISTORY AFTER: " << this->history << endl;
		if(this->history >= this->historySize) this->history -= this->historySize;
		//cout << "HISTORY AFTER AFTER: " << this->history << endl;
		//cout << "PREDICTION AFTER: " << this->table.at(location) << '\n' << endl;
		return false;
	}
}

