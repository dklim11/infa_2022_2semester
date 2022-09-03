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
	
	int size = n;
	int j;
	while (size > 1) {
		j = 0;
		while (j + 1 < size) {
			f[j] += f[j + 1];
			f[j + 1] = 0;
			j += 2;
		}
		j = 0;
		while (j + 2 < size) {
			f[j] += f[j + 2];
			f[j + 2] = 0;
			j += 2;
		}
		j = 2;
		while (j < size) {
			f[j/2] = f[j];
			j += 2;
		}
		size = j/2 - 1;
	}
	
	cout << f[0]*dx << endl;
	return 0;
}
