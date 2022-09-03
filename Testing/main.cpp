#include <iostream>

using namespace std;

int main() {
	int *array = new int [5];
	
	for (int i = 0; i < 5; i++) {
		array[i] = i + 1;
	}
	
	cout << *(array) << endl;
	delete[] array;
	return 0;
}
