#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

const int size = 21;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(0, max(size, 100));

bool check(int (&array)[size][size], int i, int j) {
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

void move_1(int (&array)[size][size], int size, int &possibility) {
	int movement[size][size] = {0};
	int direction, chance;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			chance = dist(rng) % 100;
			if (array[i][j] == 1 && movement[i][j] == 0 && chance >= possibility) {
				direction = dist(rng) % 4;
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

void move_2(int (&array)[size][size], int size, int &possibility) {	
	int movement[size][size];
	int direction, chance;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			movement[i][j] = array[i][j];
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (movement[i][j] > 0) {
				for(int k = 0; k < movement[i][j]; k++) {
					chance = dist(rng) % 100;
					if (chance >= possibility) {
						direction = dist(rng) % 4;
						if (direction == 0) {
							array[i - 1][j]++;
							array[i][j]--;
						} else if (direction == 1) {
							array[i][j - 1]++;
							array[i][j]--;
						} else if (direction == 2) {
							array[i + 1][j]++;
							array[i][j]--;
						} else {
							array[i][j + 1]++;
							array[i][j]--;
						}
					}
				}
			}
		}
	}
}

void step_1(int (&array)[size][size], int size, int &quantity, int &possibility) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && (i == 0 || i == size - 1 || j == 0 || j == size - 1)) {
				array[i][j] = 2;
				quantity--;
			} else if (array[i][j] == 1) {
				if (check(array, i, j)) {
					array[i][j] = 2;
					quantity--;
 				}
			}
		}
	}
	
	move_1(array, size, possibility);
}

void step_2(int (&array)[size][size], int size, int &quantity, int &possibility) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] > 0 && (i == 0 || i == size - 1 || j == 0 || j == size - 1)) {
				quantity = quantity - array[i][j];
				array[i][j] = 0;
			}
		}
	}
	
	move_2(array, size, possibility);
}

void print(int (&a)[size][size], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void insertion(int (&array)[size][size], int quantity_st) {
	int quantity, coord1, coord2;
	quantity = quantity_st;
	
	while (quantity > 0) {
		coord1 = dist(rng) % size;
		coord2 = dist(rng) % size;
		if (array[coord1][coord2] == 0) {
			quantity--;
			array[coord1][coord2] = 1;
		}
	}
}

int main() {
	int quantity_state_1, quantity_state_2, count;
	int possibility_1, possibility_2;
	double average = 0;
	
	cout << "Input a percent of first-type dislocations in cristall: " << endl;
	cin >> quantity_state_1;
	cout << endl;
	
	cout << "Input a percent of second-type dislocations in cristall: " << endl;
	cin >> quantity_state_2;
	cout << endl;
	
	cout << "Input a possibility of first-type dislocation's freezing from 1 to 100: " << endl;
	cin >> possibility_1;
	cout << endl;
	
	cout << "Input a possibility of second-type dislocation's freezing from 1 to 100: " << endl;
	cin >> possibility_2;
	cout << endl;
	
	quantity_state_1 = (size*size)*quantity_state_1/100;
	quantity_state_2 = (size*size)*quantity_state_2/100;
	
	//array_1 has a behaviour which is similar to previous model of dislocations.
	//array_2 represents a new_type dislocations
	int quantity_1, quantity_2;	
	for (int k = 1; k < 2000; k++) {
		int	array_1[size][size] = {0};
		int array_2[size][size] = {0};
		
		quantity_1 = quantity_state_1;
		quantity_2 = quantity_state_2;
		insertion(array_1, quantity_state_1);
		insertion(array_2, quantity_state_2);
		
		count = 0;
		while (quantity_1 > 0 || quantity_2 > 0) {
			if (quantity_1 > 0) {
				step_1(array_1, size, quantity_1, possibility_1);
			}
			if (quantity_2 > 0) {
				step_2(array_2, size, quantity_2, possibility_2);	
			}
			count++;
		}
		--count;
		
		average = (average * (k - 1) + count)/k;
	}
	
	cout << average << endl;
	return 0;
}
