#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int triangle[15][15] = {
		{75},
		{95, 64},
		{17, 47, 82},
		{18, 35, 87, 10},
		{20, 4, 82, 47, 65},
		{19, 1, 23, 75, 3, 34},
		{88, 2, 77, 73, 7, 63, 67},
		{99, 65, 4, 28, 6, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
	};

	enum direction { LEFT, RIGHT };

	int paths[16384][14];
	
	for (int i = 0; i < 16384; i++) {
		int k = i; 
		
		for (int j = 13; j >= 0; j--)
			if (k >= (int) pow(2, j)) {
				paths[i][j] = RIGHT;
				k %= (int) pow(2, j);
			} else
				paths[i][j] = LEFT;
	}
	
	int max = 0;
	
	for (int i = 0; i < 16384; i++) {
		int curr_index = 0, sum = 0;
		
		for (int j = 0; j < 15; j++) {
			sum += triangle[j][curr_index];
			curr_index += paths[i][j];
		}
		
		if (sum > max) 
			max = sum;
	}

	cout << max;
}
