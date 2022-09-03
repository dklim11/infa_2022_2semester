#include <iostream>
#include <cmath>

using namespace std;

void input(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void heap_sort(int a[], int bound, int size) {
	if (bound <= size) {
		for (int i = size - bound; i >= 0; i--) {
			if (2*i + 2 <= size - bound) {
				if (a[i] > a[2*i + 2]) {
					swap(a[2*i + 2], a[i]);
				}
				if (a[i] > a[2*i + 1]) {
					swap(a[2*i + 1], a[i]);
				} 
			} else if (2*i + 1 <= size - bound) {
				if (a[i] > a[2*i + 1]) {
					swap(a[2*i + 1], a[i]);
				}
			}
		}
		swap(a[0], a[size - bound]);
		heap_sort(a, bound + 1, size);
	}
}

void output(int a[], int size) { 
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int size;
	cin >> size;
	
	int *array = new int[size];
	
	input(array, size);
	heap_sort(array, 1, size);
	output(array, size);
	
	return 0;
}
