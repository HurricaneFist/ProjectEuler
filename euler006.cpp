#include <iostream>
using namespace std;

int main() {
	int sum = 0, sq_sum = 0;
	
	for (int i = 1; i <= 100; i++) {
		sum += i;
		sq_sum += i * i;
	}
	
	cout << sum*sum - sq_sum;
}