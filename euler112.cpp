#include <cmath>
#include <iostream>
using namespace std;

int digit_at(int n, int i) {
	return (n % (int) pow(10, i)) / (int) pow(10, i-1);
}

bool bouncy(int n) {
	int k = (int) log10(n) + 1, digits[k], order = -1;
	enum direction { INCREASING, DECREASING };
	
	for (int i = k-1, j = 1; i >= 0; i--, j++)
		digits[i] = digit_at(n, j);
	
	for (int i = 1; i < k; i++)
		if (digits[i] > digits[i-1])
			if (order == DECREASING)
				return true;
			else 
				order = INCREASING;
		else if (digits[i] < digits[i-1])
			if (order == INCREASING)
				return true;
			else
				order = DECREASING;
	
	return false;
}

int main() {
	double n = 0, num_bouncy = 0;
	
	for (int i = 1; true; i++) {
		if (bouncy(i))
			num_bouncy++;
		
		n++;
			
		if (num_bouncy/n >= .99)
			break;
	}
	
	cout << (int) n;
}