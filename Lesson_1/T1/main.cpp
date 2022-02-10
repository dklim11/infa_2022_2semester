#include <iostream>
#include <cmath>

using namespace std;

bool prime(int k) {
	int bound = sqrt(k) + 1;
	
	bool flag = true;
	for (int i = 2; i < bound; i++) {
		if (k % i == 0) {
			flag = false;
			break;
		}
	}
	
	return flag;
}

bool palindrome(int k) {
	int copy = 0, test = k, last;
	
	while (k > 0) {
		copy *= 10;
		last = k % 10;
		copy += last;
		k /= 10;
	}
	
	return copy == test;
}

int main() {
	int n;
	cin >> n;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		
		if (prime(tmp)) {
			cout << "prime" << " ";
		} else {
			cout << "composite" << " ";
		}
		
		if (palindrome(tmp)) {
			cout << "palindrome" << endl;
		} else {
			cout << "not a palindrome" << endl;
		}
	}
	
	return 0;
}
