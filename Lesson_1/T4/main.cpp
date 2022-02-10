#include <iostream>

using namespace std;

void print(int i, int n) {
	char c = 'A';
	
	for (int j = 0; j < 2*n - 1; j++) {
		if (j < n - i) {
			cout << c;
			c++;
			if (j == n - 1 - i && i == 0) {
				c--;	
			}
		} else if (j > n + i - 2) {
			--c;
			cout << c;
		} else {
			cout << " ";
		}
	}
	cout << endl;
}

int main() {
	int n; 
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		print(i, n);
	}
	return 0;
}
