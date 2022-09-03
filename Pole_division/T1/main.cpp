#include <iostream>
#include <cmath>

using namespace std;

struct Rod{
	int len;
	int price;
};

int cut_rod_helper(Rod p[], int n, int *memo) {
	if (n == 0) {
		return 0;
	}
	if (memo[n] >= 0) {
		return memo[n];
	}
	
	int q = -1;
	for (int i = 0; p[i].len <= 10 && i < 10; i++) {
		if (n - p[i].len >= 0)
			q = max(q, p[i].price + cut_rod_helper(p, n - p[i].len, memo));
	}
	memo[n] = q;
	
	return q;
}

int cut_rod_memoisation(Rod p[], int n) {
	int *memo = new int [n + 1];
	
	for (int i = 0; i <= n; i++) {
		memo[i] = -1;
	}
	
	int result = cut_rod_helper(p, n, memo);
	return result;
	delete[] memo;
}

int main() {
	int n;
	cin >> n;
	Rod rods[] = {{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
	
	cout << cut_rod_memoisation(rods, n);
	return 0;
}
