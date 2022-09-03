#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(int a[], int left, int right) {
	if (right - left <= 1) {
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
		
		quick_sort(a, left, r);
		quick_sort(a, l, right);
	}
}

int func(int *a, int left, int right) {
	if (right - left == 1) {
		return 0;
	} else if (right - left == 2) {
		if (a[right] - a[right - 1] > a[left + 1] - a[left]) {
			return a[left + 1] - a[left];
		} else {
			return a[right] - a[right - 1];
		}
	} else {
		if (a[left + 1] - a[left] > a[right] - a[right - 1]) {
			return a[right] - a[right - 1] + func(a, left, right - 1);
		} else {
			return a[left + 1] - a[left] + func(a, left + 1, right);
		}
	}
}

int main() {
	int *a = new int [100];
	
	int count = 0;
	while (cin >> a[count]) {
    	count++;
	}
	
	quick_sort(a, 0, count - 1);
	
	if (count == 2) {
		cout << a[1] - a[0] << endl;
	} else if (count == 3) {
		cout << a[2] - a[0] << endl;
	} else {
		cout << a[1] - a[0] + a[count - 1] - a[count - 2] + func(a, 1, count - 2) << endl;
	}
	
	delete[] a;
	return 0;
}
