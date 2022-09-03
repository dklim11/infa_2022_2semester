#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	float a, b;
	cin >> n;
	// Input two numbers, which determines bounds
	// of interation
	cin >> a >> b;
	float dx = (b - a)/n;
	float *g = new float [n];
	float *f = new float [n];
	
	for (int i = 0; i < n; i++) {
		float x = a + (b - a)*i/n;
		f[i] = log(x)*x;
		g[i] = 1/(x + 1);
	}
	
	for (int i = 0; i < n; i++) {
		f[i] *= g[i];
	}
	
	float sum = 0.f, t = 0.f;
	float y, z;
	for (int i = 0; i < n; i++) {
		y = f[i] - t;
		z = sum + y;
		t = (z - sum) - y;
		sum = z;
	}
	
	cout << sum*dx << endl;
	return 0;
}
