#ifndef TWOBITBP_H
#define TWOBITBP_H
#include <map>

using namespace std;

class TwoBitBP {
	public:
		TwoBitBP();
		TwoBitBP(int size);
		bool predict(int address, string branch);
	private:
		map<int, int> table;
		int size;
		int numBits;
};

#endif
