#include <iostream>
#include <cmath>

using namespace std;

int func(int *a, int *cash, int idx) {
	if (cash[idx] != -1) {
		return cash[idx];
	} else {
		bool flag = true;
		for (int i = 0; i < idx; i++) {
			if (a[idx] > a[i]) {
				flag = false;
				cash[idx] = max(cash[idx], func(a, cash, i) + 1);
			} else if (a[idx] == a[i]) {
				flag = false;
				cash[idx] = max(cash[idx], func(a, cash, i));
			}
		}
		if (flag) {
			cash[idx] = 1;
		}
		return cash[idx];
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
	cash[0] = 1;
	
	for (int i = 1; i < n; i++) {
		func(a, cash, i);	
	}
	
	int ans = cash[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, cash[i]);
	}
	
	cout << ans;
	delete[] a;
	delete[] cash;
	return 0;
}
