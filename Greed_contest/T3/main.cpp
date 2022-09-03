#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int array[n][2];
	
	for (int i = 0; i < n; i++) {
		cin >> array[i][0] >> array[i][1];
	}
	
	int tmp = array[0][1], count = 1;
	for (int i = 1; i < n; i++) {
		if (array[i][0] >= tmp) {
			count++;
			tmp = array[i][1];
		}
	}
	
	cout << count << endl;
	return 0;
}
