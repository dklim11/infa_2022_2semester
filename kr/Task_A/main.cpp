#include <iostream>

using namespace std;

int check(int pos[], int begin, int length) {
	int sum = 0;
	for (int i = begin; i < begin + length - 1; i++) {
		if (pos[i] == 1) {
			sum += 1;
		}
	}
	
	return sum;
}

int main() {
	int n, l;
	cin >> n;
	int *array1 = new int [n];
	int *array2 = new int [n];
	int pos[30] = {0};
	
	for (int i = 0; i < n; i++) {
		cin >> array1[i] >> array2[i];
	}
	cin >> l;	
	
	for (int i = 0; i < n; i++) {
		for (int j = array1[i]; j < array1[i] + array2[i]; j++) {
			pos[j] = 1;
		}
	}
	
	int answer = -1;
	for (int i = 0; i < 30 - l + 1; i++) {
		if (check(pos, i, l) == 0) {
			answer = i;
			break;
		}
	}
	
	cout << answer << endl;
	
	delete []array1;
	delete []array2;
	return 0;
}
