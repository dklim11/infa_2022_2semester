#include <iostream>

using namespace std;

struct denom_array_t{
	int *arr = nullptr;
	int sz = 0;
};

int gcd(int m, int n) {
	while (n > 0 && m > 0) {
		int k;
		if (m > n) {
			k = m/n;
			m -= k*n;
		} else {
			k = n/m;
			n -= k*m;
		}
	}
	
	if (n == 0) {
		return m;
	} else {
		return n;
	}
}

denom_array_t *egyptian_denom(int m, int n, denom_array_t *a) {
	int prev = 1, r, b, c;
	while (m >= 1) {
		while(prev*m < n) {
			prev++;
		}
		r = gcd(prev, n);
		b = n/r;
		c = prev/r;
		m = c*m - b;
		n *= c;
		
		a->arr[a->sz] = prev;
		a->sz += 1;
	}
	
	return a;
}

int main() {
	int m, n;
	cin >> m >> n;
	
	int *array = new int [100];
	
	denom_array_t *a = new denom_array_t;
	a->arr = array;
	a->sz = 0;
	
	a = egyptian_denom(m, n, a);
	
	for (int i = 0; i < a->sz; i++) {
		cout << a->arr[i] << " "; 
	}
	cout << "size = " << a->sz << endl;
	
	delete[] array;
	delete a;
	return 0;
}
