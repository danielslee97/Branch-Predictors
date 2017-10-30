#ifndef GSHARE_H
#define GSHARE_H
#include <map>

using namespace std;

class Gshare {
	public:
		Gshare();
		Gshare(float size);
		bool predict(long address, string branch);
	private:
		long history;
		map<int, int> table;
		int size;
		long historySize;
};

#endif
