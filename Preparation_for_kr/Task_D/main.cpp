#include <iostream>

using namespace std;

int search(int *array, int size){
	int left_bound = 0, right_bound = size - 1;
	
	while (left_bound < right_bound - 1) {
		int c = (left_bound + right_bound)/2;
		if (array[c] == 1) {
			right_bound = c;
		} else {
			left_bound = c;
		}
	}
	
	if (array[right_bound] == 1) {
		return right_bound - 1;
	} else {
		return right_bound;
	}
}

int main() {
	int n;
	cin >> n;
	
	int *array = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	
	cout << search(array, n) << endl;
	return 0;
}
