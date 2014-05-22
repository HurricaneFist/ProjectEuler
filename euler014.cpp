#include <iostream>
using namespace std;
// on the slow side

int collatz(int n) {
	int k = 1;
	
	for (int i = n; i != 1; (i % 2) ? (i *= 3, i += 1) : i /= 2)
		k++;
	
	return k;
}

int main() {
	int max_index = 0;
	
	for (int i = 1; i < 1000000; i++) {
		int c = collatz(i);
		cout << i << endl;
		
		if (c > max_index)
			max_index = c;
	}
	
	cout << max_index;
}