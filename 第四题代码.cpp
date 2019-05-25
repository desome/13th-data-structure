#include <iostream>
#include <stdlib.h>

using namespace std;

class coinChanger {
private:
	int numcoin;
	int *coin;
	int *res;
	int locate;
public:
	coinChanger() {
		locate = 0;
		numcoin = 0;
		res = new int[1001];
		res[0] = 0;

		coin = NULL;
	}
	coinChanger(int* coinValueSet, int n) {
		locate = 0;
		numcoin = n;
		res = new int[1001];
		res[0] = 0;

		coin = new int[n];
		for (int i = 0; i < n; i++) {
			coin[i] = coinValueSet[i];
			//cout << coin[i] << endl;
		}

	}

	~coinChanger() {
		delete[] res;
		delete[] coin;
	}
	void clearResults() {
		locate = 0;
	}
	void setCoinValueSet(int* coinValueSet, int n) {
		if (n <= 0)
			throw("bad number");
		if (numcoin < n) {
			delete[] coin;
			coin = new int[n];
		}

		for (int i = 0; i < n; i++) {
			coin[i] = coinValueSet[i];
			//cout << coin[i]<<endl;
		}
		
		locate = 0;
		//cout << locate<<endl;
		numcoin = n;
	}
	int numCoinsToMakeChange(int target) {
		// small to large for coinValues
		// limit target to be <= 1000;
		// return -1 if impossible.
		if (!numcoin)
			throw("can not work");

		if (target < 0 || target>1000)
			throw("bad number");

		if (target < locate + 1)
			return res[target];

		int min = 0;
		bool first;
		for (int i = locate + 1; i < target + 1; i++)
		{
			min = -1;
			first = true;
			for (int j = 0; j < numcoin; j++) {
				if (i - coin[j] > -1 && res[i - coin[j]]>-1) {
					//cout << i - coin[j]<<endl;
					if (first) {
						min = res[i - coin[j]];
						first = false;
					}
					else
						min = min < res[i - coin[j]] ? min : res[i - coin[j]];
				}
			}

			if(first)
				res[i] = min;
			else
				res[i] = min +1;
			//cout <<"res[i] is:" <<res[i] << "        "<<i<<endl;
		}
		locate = target;

		return res[target];
	}
};

void test1() {
	srand(1387423);
	int coinValueSet1[4] = { 1,2,5,10 };
	int coinValueSet3[2] = { 5,7 };

	coinChanger cc(coinValueSet1, 4);
	cc.setCoinValueSet(coinValueSet1, 4);

	cout << "Using the set {1,2,5,10}, making changes for:" << endl;
	cout << "99: " << cc.numCoinsToMakeChange(99) << endl;
	cout << "98: " << cc.numCoinsToMakeChange(98) << endl;
	cout << "579: " << cc.numCoinsToMakeChange(579) << endl;
	cout << "998: " << cc.numCoinsToMakeChange(998) << endl;

	for (int i = 0; i < 5000; i++) {
		cc.numCoinsToMakeChange(rand() % 1001);
	}
	
	cc.setCoinValueSet(coinValueSet3, 2);
	cc.clearResults();
	cout << "Using the set {5,7}, making changes for: " << endl;
	cout << "99: " << cc.numCoinsToMakeChange(99) << endl;
	cout << "98: " << cc.numCoinsToMakeChange(98) << endl;
	cout << "579: " << cc.numCoinsToMakeChange(579) << endl;
	cout << "998: " << cc.numCoinsToMakeChange(998) << endl;
	cout << "23: ";
	if (cc.numCoinsToMakeChange(23) == -1) cout << "Impossible" << endl;
	else cout << cc.numCoinsToMakeChange(23) << endl;

	for (int i = 0; i < 5000; i++) {
		cc.numCoinsToMakeChange(rand() % 1001);
	}
}

int main() {
	test1();
	system("pause");
	return 0;
}