#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, left = 0, right = 0;
	cin >> n;
	
	char c;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> c;
		
		if (c == '(') {
			left++;
		} else {
			right++;
		}
		
		if (right - left > 0) {
			flag = false;
			break;
		}
	}
	
	if (flag) {
		cout << "correct" << endl;
	} else {
		cout << "incorrect" << endl;
	}
	return 0;
}
