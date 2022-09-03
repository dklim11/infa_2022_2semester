#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	float dx;
	cin >> n;
	cin >> dx;
	
	float *f = new float [n];
	float *g = new float [n];
	
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	
	float sum = 0.f;
	for(int i = 0; i < n; i++) {
		sum = fma(f[i], g[i], sum);
	}
	
	cout << sum*dx << endl;
	return 0;
}
