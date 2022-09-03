#include <iostream>

using namespace std;

bool check(int **a, int n, int c, int d) {
	for (int i = 0; i < n; i++) {
		if (a[i][0] == c && a[i][1] == d) {
			return true;		
		}
	}
	return false;
}

int func(int **a, int n, int **cash, int pos1, int pos2) {
	if (cash[pos1][pos2] != -1) {
		return cash[pos1][pos2];
	} else {
		if(pos1 == 0) {
			cash[pos1][pos2] = 0;
			return 0;
		}
		if (check(a, n, pos1, pos2)) {
			if (pos2 == 0) {
				cash[pos1][pos2] = func(a, n, cash, pos1 - 1, pos2 + 1);
				return cash[pos1][pos2];
			}
			if (pos2 == 7) {
				cash[pos1][pos2] = func(a, n, cash, pos1 - 1, pos2 - 1);
				return cash[pos1][pos2];
			}
			cash[pos1][pos2] = func(a, n, cash, pos1 - 1, pos2 + 1) + func(a, n, cash, pos1 - 1, pos2 - 1);
			return cash[pos1][pos2];
		} else {
			cash[pos1][pos2] = func(a, n, cash, pos1 - 1, pos2);
			return cash[pos1][pos2];
		}
	}
}

int ans(int **a, int n, int **cash) {
	int sum = 0;
	
	for (int i = 0; i < 8; i++) {
		sum += func(a, n, cash, 7, i);
	}
	
	return sum;
}

int main() {
	int n;
	cin >> n;
	
	int **cash = new int *[8];
	for (int i = 0; i < 8; i++) {
		cash[i] = new int [8];
		for (int j = 0; j < 8; j++) {
			cash[i][j] = -1;
		}
	}
	
	int **a = new int *[n + 1]; 
	char c, d;
	int first, second;
	for (int i = 0; i < n + 1; i++) {
		cin >> c >> d;
		second = c - '0';
		second -= 49;
		first = d - '0';
		first--;
		a[i] = new int [2];
		a[i][0] = first;
		a[i][1] = second;
	}
	cash[a[n][0]][a[n][1]] = 1;
	
	cout << ans(a, n, cash) << endl;
	
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	for (int i = 0; i < 8; i++) {
		delete[] cash[i];
	}
	delete[] cash;
	return 0;
}
