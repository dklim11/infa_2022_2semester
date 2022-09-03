#include <iostream>
#include <cmath>

using namespace std;

int func(const int *p, int left, int right) {
	if (right - left == 3) {
		return p[left]*p[left + 1]*p[left + 2];
	} else if (cash[left][right] > 0) {
		return cash[left][right];	
	} else {
		min = func(p, left, left + 1) + func(p, left + 1, right) + p[left]*p[right];
		
	}
}

int matrix_chain(const int *p, int size) {
	if (size <= 2) {
		return 0;
	} else if (size == 3) {
		return p[0]*p[1]*p[2];
	} else {
		int **cash = new int *[size];
	
		for (int i = 0; i < size; i++) {
			cash[i] = new int [size];
			for (int j = 0; j < size; j++) {
				cash[i][j] = -1;
			}
		}
		
		a = func(p, 0, size - 1);
		
		for (int i = 0; i < size; i++) {
			delete[] cash[i];
		}
		delete[] cash;
		
		return a;	
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
	
	cout << matrix_chain(p, n) << endl;
	
	delete[] insert;
	return 0;
}

