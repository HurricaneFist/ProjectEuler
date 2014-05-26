#include <iostream>
using namespace std;

int main() {
	const int N = 1000000; // arbitrary large number
	bool is_composite[N] = {false};
	
	for (int i = 2; i < N; i++)
		for (int j = i*2; j < N; j += i)
			if (!is_composite[j])
				is_composite[j] = true;
	
	int k = 2, num_prime = 1;
	while (num_prime < 10001)
		if (!is_composite[++k])
			num_prime++;
		
	cout << k;
}