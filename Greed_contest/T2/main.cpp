#include <iostream>

using namespace std;

int main() {
	int n, k, s;
	cin >> n >> k;
	cin >> s;
	
	int *array = new int [s + 2];
	array[0] = 0;
	for (int i = 1; i <= s; i++) {
		cin >> array[i];
	}
	array[s + 1] = n;

	int idx = 0, prev = 0, count = 0;
	while (true) {
		for (int i = s + 1; i >= idx; i--) {
			if (array[i] - array[idx] <= k) {
				idx = i;
				break;
			}
		}
		if (idx == prev) {
			count = -1;
			break;
		}
		if (idx == s + 1) {
			break;
		}
		count++;
		prev = idx;
	}
	
	cout << count << endl;
	
	delete []array;
	return 0;
}
