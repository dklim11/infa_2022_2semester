#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while(0 != b) {
		a %= b;
		int tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;
	
	cout << "great common devisor is equal to: " << gcd(a, b) << endl;
	return 0;
}
