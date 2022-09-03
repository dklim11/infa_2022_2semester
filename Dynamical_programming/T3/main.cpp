#include <iostream>
#include <cmath>

using namespace std;

int func(int *a, int *cash, int idx) {
	if (cash[idx] != -1) {
		return cash[idx];
	} else {
		if (idx == 1) {
			cash[idx] = abs(a[1] - a[0]);
			return cash[idx];
		} else {
			cash[idx] = min(abs(a[idx] - a[idx - 1]) + func(a, cash, idx - 1), 3*abs(a[idx] - a[idx - 2]) + func(a, cash, idx - 2));
			return cash[idx];
		}	
	}
}

int main() {
	int n; 
	cin >> n;
	
	int *a = new int [n];
	int *cash = new int [n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cash[i] = -1;
	}
	cash[0] = 0;
	
	cout << func(a, cash, n - 1) << endl;
	
	delete[] a;
	delete[] cash;
	return 0;
}
