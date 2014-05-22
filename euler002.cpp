#include <iostream>
using namespace std;

int fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	
	return fib(n-1) + fib(n-2);
}

int main() {
    int sum = 0, i = 1;
	
	while (i++) {
		int f = fib(i);
		
		if (f >= 4000000) 
			break;
			
		if (f % 2 == 0) 
			sum += f;
	}
	
	cout << sum;
}