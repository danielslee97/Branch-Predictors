#ifndef TOURNAMENTPREDICTOR_H
#define TOURNAMENTPREDICTOR_H
#include <map>
#include "TwoBitBP.h"
#include "Gshare.h"

using namespace std;

class TournamentPredictor {
	public:
		TournamentPredictor();
		bool predict(long address, string branch);
	private:
		int size;
		map<int, int> table;
		TwoBitBP bimodalPredictor;
		Gshare gSharePredictor;
};

#endif
