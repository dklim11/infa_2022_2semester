#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(0, 3);

double eps = 0.00001f;

bool check(int (&array)[40][40], int i, int j) {
	bool flag = false;
	if (array[i - 1][j] == 1 || array[i - 1][j] == 2) {
		flag = true;
	}
	if (array[i + 1][j] == 1 || array[i + 1][j] == 2) {
		flag = true;
	}
	if (array[i][j - 1] == 1 || array[i][j - 1] == 2) {
		flag = true;
	} 
	if (array[i][j + 1] == 1 || array[i][j + 1] == 2) {
		flag = true;
	}
	
	return flag;
}

void move(int (&array)[40][40], int size) {
	int movement[size][size] = {0};
	int direction;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && movement[i][j] == 0) {
				direction = dist(rng);
				if (direction == 0) {
					if (array[i - 1][j] == 0) {
						array[i - 1][j] = 1;
						movement[i - 1][j] = 1;
						array[i][j] = 0;
					}
				} else if (direction == 1) {
					if (array[i][j - 1] == 0) {
						array[i][j - 1] = 1;
						movement[i][j - 1] = 1;
						array[i][j] = 0;
					}
				} else if (direction == 2) {
					if (array[i + 1][j] == 0) {
						array[i + 1][j] = 1;
						movement[i + 1][j] = 1;
						array[i][j] = 0;
					}
				} else {
					if (array[i][j + 1] == 0) {
						array[i][j + 1] = 1;
						movement[i][j + 1] = 1;
						array[i][j] = 0;
					}
				}
			}
		}
	}
}

void step(int (&array)[40][40], int size, int &quantity) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && (i == 0 || i == size - 1 || j == 0 || j == size - 1)) {
				array[i][j] = 2;
				quantity -= 1;
			} else if (array[i][j] == 1) {
				if (check(array, i, j)) {
					array[i][j] = 2;
					quantity -= 1;
 				}
			}
		}
	}
	
	move(array, size);
}

void print(int (&a)[40][40], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void recalculate(int count, double (&result)[10], int (&num_exp)[10], double Area) {
	if ((Area - 0.46) < 0) {
		result[0] = (result[0]*num_exp[0] + count)/(num_exp[0] + 1);
		num_exp[0]++;
	} else if ((Area - 0.47) < 0) {
		result[1] = (result[1]*num_exp[1] + count)/(num_exp[1] + 1);
		num_exp[1]++;
	} else if ((Area - 0.48) < 0) {
		result[2] = (result[2]*num_exp[2] + count)/(num_exp[2] + 1);
		num_exp[2]++;
	} else if ((Area - 0.49) < 0) {
		result[2] = (result[2]*num_exp[2] + count)/(num_exp[2] + 1);
		num_exp[2]++;
	} else if ((Area - 0.50) < 0) {
		result[3] = (result[3]*num_exp[3] + count)/(num_exp[3] + 1);
		num_exp[3]++;	
	} else if ((Area - 0.51) < 0) {
		result[4] = (result[4]*num_exp[4] + count)/(num_exp[4] + 1);
		num_exp[4]++;
	} else if ((Area - 0.52) < 0) {
		result[5] = (result[5]*num_exp[5] + count)/(num_exp[5] + 1);
		num_exp[5]++;
	} else if ((Area - 0.53) < 0) {
		result[6] = (result[6]*num_exp[6] + count)/(num_exp[6] + 1);
		num_exp[6]++;
	} else if ((Area - 0.54) < 0) {
		result[7] = (result[7]*num_exp[7] + count)/(num_exp[7] + 1);
		num_exp[7]++;
	} else if ((Area - 0.55) < 0) {
		result[8] = (result[8]*num_exp[8] + count)/(num_exp[8] + 1);
		num_exp[8]++;
	} else {
		result[9] = (result[9]*num_exp[9] + count)/(num_exp[9] + 1);
		num_exp[9]++;
	}
}

int main() {
	const int size = 40;
	int array[size][size];
	int quantity;
	double Area;
	
	double result[10] = {0};
	int num_exp[10] = {0};
	//"result" is an array of const size, related to values of Area
	// 0.45, 0.46, 0.47, 0.48, 0.49, 0.50, 0.51, 0.52, 0.53
	// "num_exp" - array, that states number of reculculating of each
	// position in "result" array
	
	for (int k = 0; k < 20000; k++) {
		array[size][size] = {0};
		quantity = 0; 
		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				array[i][j] = dist(rng)%2;
				if (array[i][j] == 1) {
					quantity++;
				}
			}
		}
		
		Area = (double)quantity/(size*size);
			
		int count = 0;
		while (quantity > 0) {
			step(array, size, quantity);
			count++;
		}
		--count;
		
		recalculate(count, result, num_exp, Area);
	}
	cout << endl;
	for (int k = 0; k < 10; k++) {
		cout << result[k] << " " << num_exp[k] << endl;
	}

	return 0;
}
