#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(int a[], int left, int right) {
	if (right - left == 1) {
		if(a[left] > a[right]) {
			swap(a[left], a[right]);
		}
	} else {
		int p = (left + right)/2;
		bool flag = true;
		int l = left, r = right;
		
		while (l < r) {
			while (a[l] < a[p]) {
				l++;
			}
			while (a[r] > a[p]) {
				r--;
			}
			if (l < r) {
				swap(a[r], a[l]);
				l++;
				r--;	
			}
		}
		
		quick_sort(a, p, right);
		quick_sort(a, left, p);
	}
}

int main() {
	int s, n;
	int *array = new int [n];
	
	cin >> s >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	quick_sort(array, 0, n - 1);
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += array[i];
		if (sum > s) {
			cout << i << endl;
			break;
		}
	}
	
	delete []array;
	return 0;
}
