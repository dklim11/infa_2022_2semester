#include <iostream>
#include <cmath>

using namespace std;

void inverse(int &k) {
	int copy = k;
	k = 0;
	while (copy > 0) {
		k *= 10;
		k += copy % 10;
		copy /= 10;
	}
}

int main() {
	int n;
	cin >> n;
	
	inverse(n);
	cout << n << endl;
	return 0;
}
