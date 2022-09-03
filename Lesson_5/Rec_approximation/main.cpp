#include <iostream>
#include <cmath>

using namespace std;

float recursive_count(int i, int size, float const f[], float const g[], float dx) {
	if (size - i == 0) {
		return f[i]*g[i]*dx;
	} else if (size - i == 1) {
		return f[i]*g[i]*dx + f[i+1]*g[i+1]*dx;
	} else {
		int c = (i + size)/2;
		return recursive_count(i, c, f, g, dx) + recursive_count(c + 1, size, f, g, dx);
	}
}

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
	
	cout << recursive_count(0, n, f, g, dx) << endl;
	return 0;
}
