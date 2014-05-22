#include <iostream>
using namespace std;

int main() {
	long long n = 600851475143LL;
	
	for (long long i = 2LL; i < n; i++)
		while (n % i == 0)
			n /= i;
	
	cout << n;
}