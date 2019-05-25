#include <iostream>
#include <iomanip>
using namespace std;

int numWaysToReach(int n) {
	// TODO
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (n == 3)
		return 3;
	int **a = new int *[3];
	a[0] = new int[n + 1];
	a[1] = new int[n + 1];
	a[2] = new int[n + 1];

	a[0][1] = 1;
	a[1][1] = 0;
	a[2][1] = 0;

	a[0][2] = 0;
	a[1][2] = 1;
	a[2][2] = 0;

	a[0][3] = 1;
	a[1][3] = 1;
	a[2][3] = 1;

	for (int j = 4; j < n + 1; j++) {
		a[0][j] = a[1][j - 1] + a[2][j - 1];
		a[1][j] = a[0][j - 2] + a[2][j - 2];
		a[2][j] = a[0][j - 3] + a[1][j - 3];
	}
	int b = a[0][n] + a[1][n] + a[2][n];
	delete[] a[0];
	delete[] a[1];
	delete[] a[2];
	delete a;
	return b;
}


int helpanother(int n, int i) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	int sum = 0;
	if (i - 1)
		sum = sum + helpanother(n - 1, 1);
	if (i - 2)
		sum = sum + helpanother(n - 2, 2);
	if (i - 3)
		sum = sum + helpanother(n - 3, 3);
	return sum;
}

int another(int n) {
	return helpanother(n - 1, 1) + helpanother(n - 2, 2) + helpanother(n - 3, 3);
}

void test1() {
	for (int i = 1; i <= 10; i++) {
		cout << "Number of ways to walk to destination (" << i << "): " << numWaysToReach(i) << endl;
		cout << "Number of ways to walk to destination (" << i << "): " << another(i) << endl;
	}
}

int main() {
	test1();
	system("pause");
	return 0;
}