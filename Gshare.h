#ifndef GSHARE_H
#define GSHARE_H
#include <map>

using namespace std;

class Gshare {
	public:
		Gshare();
		Gshare(float size);
		bool predict(int address, string branch);
	private:
		int history;
		map<int, int> table;
		int size;
		int historySize;
		int numBits;
};

#endif
