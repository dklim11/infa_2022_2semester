#include <iostream>

using namespace std;

int binar_search(int array[], int size, int x) {
	int left_bound = 0, right_bound = size - 1, flag = 0;
	while (flag < size) {
		int subj = (left_bound + right_bound)/2;
		if (array[subj] == x) {
			return subj;
		} else if (array[subj] > x) {
			right_bound = subj;
		} else {
			left_bound = subj;
		}
		flag++;
	}
	return -1;
}

int linear_search(int array[], int size, int x) {
	for (int i = 0; i < size; i++) {
		if (array[i] == x) {
			return i;
		}
	}
	
	return -1;
}

int main() {
	int x;
	cin >> x;
	
	const int size = 10;
	
	int array[size] = {0};
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	
	cout << linear_search(array, size, x) << endl;
	
	cout << binar_search(array, size, x) << endl;
	return 0;
}
