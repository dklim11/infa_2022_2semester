#include <iostream>
#include <cmath>

using namespace std;

long long check(long long n) {
	long long k = 1;
	
	while (2*k <= n) {
		k *= 2; 
	}
	
	return k;
}

int main() {
	long long n;
	cin >> n;
	
	long long result = 0, k = check(n);
	
	while(k > 1) {
		result += n/k;
		k /= 2;
	}
	
	cout << result << endl;
	return 0;
}
