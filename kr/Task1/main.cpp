#include <iostream>

using namespace std;

int check(int pos[30], int i, int l) {
	int sum = 0;
	for (int b = i; b != i + l; ++b) {
		sum += pos[b];
	}
	return sum;
}

int main() {
	int n, l;
	int c, d;
	int a[30] = {0};
	int b[30][2];
	cin >> n;
	for (int i = 0; i != n; ++i) {
		cin >> c >> d;
		b[i][0] = c;
		b[i][1] = d;
	}
	cin >> l;
	for (int i = 0; i != n; ++i) {
		for (int j = b[i][0]; j != b[i][0] + b[i][1]; j++) {
			a[j] = 1;
		}
	}
	
	int s = -1;
	for (int i = 0; i != (30-l+1); ++i) {
		if (check(a, i, l) == 0) {
			s = i;
			break;
		}
	}
	cout << s << endl;
	return 0;
}
