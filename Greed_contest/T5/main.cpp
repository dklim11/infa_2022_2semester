#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int *array = new int[5];
	
	array[4] = n - (n % 100);
	n %= 100;
	array[3] = n - (n % 50);
	n %= 50;
	array[2] = n - (n % 25);
	n %= 25;
	array[1] = n - (n % 5);
	n %= 5;
	array[0] = n;
	
	cout << array[4]/100 + array[3]/50 + array[2]/25 + array[1]/5 + array[0];
	return 0;
}
