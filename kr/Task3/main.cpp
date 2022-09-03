#include <iostream>

using namespace std;

int* compress(int** matrix, int n, int m) {
	int *a = new int [n * 3];
	
	int count;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != 0 && flag) {
				count++;
				if (count > 3) {
					flag = false;
				} else {
					a[3*i + count - 1] = matrix[i][j];
				}
			}
		}
		if (count < 3) {
			flag = false;
		}
	}
	
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
	
	if (flag) {
		return a;
	} else {
		delete[] a;
		return nullptr;
	}
}

int main() {
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int* compressed = compress(a, n, m);
	
    if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}
