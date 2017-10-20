#ifndef ONEBITBP_H
#define ONEBITBP_H
#include <map>

using namespace std;

class OneBitBP {
	public:
		OneBitBP();
		OneBitBP(int size);
		bool predict(int address, string branch);
	private:
		map<int, int> table;
		int size;
		int numBits;
};

#endif
