#include <iostream>
#include <cmath>

using namespace std;

void input(int *array, int size) {
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(int *a, int left, int right) {
	if (right - left == 1 || right - left == 0) {
		if(a[left] > a[right]) {
			swap(a[left], a[right]);
		}
	} else {
		int p = (right + left)/2;
		int l = left, r = right;
		
		while (r > l) {
			while (a[l] < a[p]) {
				l++;
			}
			while (a[r] > a[p]) {
				r--;
			}
			if (l <= r) {
				swap(a[r], a[l]);
				l++;
				r--;	
			}
		}
		
		quick_sort(a, left, r);
		quick_sort(a, l, right);
	}
}

void output(int *array, int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

int main() {
	int size;
	cin >> size;
	
	int *array = new int [size];
	
	input(array, size);
	quick_sort(array, 0, size - 1);
	output(array, size);
	
	return 0;
}
