#include <iostream>
#include <iomanip>
using namespace std;

long numWaysToReach(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int *a = new int[n + 1];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	int i;
	for (i = 3; i < n+1; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	int b = a[n];
	delete[] a;
	return b;
}

int another(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return another(n-1)+another(n-2);
}

void test1() {
	for (int i = 1; i <= 20; i++) {
		cout << "Number of ways to walk to destination (" << i << "): " << numWaysToReach(i) << endl;
		cout << "Number of ways to walk to destination (" << i << "): " << another(i) << endl;
	}
}

int main() {
	test1();
	system("pause");
	return 0;
}
