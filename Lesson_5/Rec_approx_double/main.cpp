#include <iostream>
#include <cmath>

using namespace std;

float recursive_count(int i, int size, double const f[], double const g[], double dx) {
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
	double dx = (b - a)/n;
	double *g = new double [n];
	double *f = new double [n];
	
	for (int i = 0; i < n; i++) {
		double x = a + (b - a)*i/n;
		f[i] = log(x)*x;
		g[i] = 1/(x + 1);
	}
	
	cout << recursive_count(0, n, f, g, dx) << endl;
	return 0;
}
