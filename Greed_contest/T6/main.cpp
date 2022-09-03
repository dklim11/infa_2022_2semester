#include <iostream>

using namespace std;

int func(int n, int *cash) {
	if (n < 0) {
		return 0;
	} else if (n == 0) {
		return 1;
	} else if (cash[n] > 0) {
		return cash[n];
	} else {
		cash[n] = func(n - 50, cash) + func(n - 25, cash) + func(n - 10, cash) + func(n - 5, cash) + func(n - 1, cash);
		return cash[n];
	}
}

int main() {
	int n;
	
	while(cin >> n) {
		int *cash = new int [n + 1];
		for (int i = 0; i < n + 1; i++) {
			cash[i] = -1;
		}
		cash[0] = 0;
		cout << func(n, cash) << endl;
		delete[] cash;
	}
	
	return 0;
}
