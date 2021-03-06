#ifndef TWOBITBP_H
#define TWOBITBP_H
#include <map>

using namespace std;

class TwoBitBP {
	public:
		TwoBitBP();
		TwoBitBP(int size);
		bool predict(long address, string branch);
	private:
		map<int, int> table;
		int size;
};

#endif
