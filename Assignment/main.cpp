#include <iostream>
#include <cmath>

using namespace std;

void def(int *next, const int *p, int idx, int size) {
	int flag = 0;
	for (int j = 0; j < size; ++j) {
		if (j != idx) {
			next[j] = p[j + flag];
		} else {
			j--;
			idx--;
			flag = 1;
		}
	}
}

int matrix_chain(const int *p, int size) {
	if (size - 2 <= 0) {
		return 0;
	} else if (size == 3) {
		return p[0]*p[1]*p[2];
	} else {
		int *next = new int [size - 1];
		def(next, p, 1, size);
		const int *f = next;
		int minimal = p[0]*p[1]*p[2] + matrix_chain(f, size - 1);
		for (int i = 2; i < size - 1; i++) {
			def(next, p, i, size);
			const int *tmp = next; 
			minimal = min(minimal, p[i - 1]*p[i]*p[i + 1] + matrix_chain(tmp, size - 1));
		}
		
		delete[] next;
		return minimal;
	}
}

int main() {
	int n;
	cin >> n;
	
	int *insert = new int [n];
	
	for (int i = 0; i < n; i++) {
		cin >> insert[i];
	}
	
	const int *p = insert;
	
	if (n - 2 <= 0) {
		cout << 0 << endl;
	} else {
		cout << matrix_chain(p, n) << endl;
	}

	delete[] insert;
	return 0;
}
