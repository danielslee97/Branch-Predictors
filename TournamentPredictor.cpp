#include "TournamentPredictor.h"

TournamentPredictor::TournamentPredictor() {
	this->size = 2048;
	this->bimodalPredictor = TwoBitBP();
	this->gSharePredictor = Gshare();
}
bool TournamentPredictor::predict(long address, string branch) {
	bool outcome;
	int signBits = address % this->size;

	if(this->table.find(signBits) == this->table.end()) {
		this->table.insert(pair<int, int>(signBits, 0));
	}
	
	if(this->table.at(signBits) >= 2) {
		if(this->bimodalPredictor.predict(address, branch)) {
			if(this->gSharePredictor.predict(address, branch)) {
				return true;
			}
			else {
				if(this->table.at(signBits) == 2) {
					this->table.at(signBits)++;
				}
				return true;
			}
		}
		else if(this->gSharePredictor.predict(address, branch)) {
			this->table.at(signBits)--;
			return false;
		}
		else return false;
	}
	else {
		if(this->gSharePredictor.predict(address, branch)) {
			if(this->bimodalPredictor.predict(address, branch)) {
				return true;
			}
			else {
				if(this->table.at(signBits) == 1) {
					this->table.at(signBits)--;
				}
				return true;
			}
		}
		else if(this->bimodalPredictor.predict(address, branch)) {
			this->table.at(signBits)++;
			return false;
		}
		else return false;
	}
}







