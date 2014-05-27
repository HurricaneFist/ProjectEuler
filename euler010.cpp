#include <iostream>
using namespace std;

int main() {
	const int N = 2000000;
	bool is_composite[N] = {false};
	
	for (int i = 2; i < N; i++)
		for (int j = i*2; j < N; j += i)
			if (!is_composite[j])
				is_composite[j] = true;
				
	long long sum = 0;
	for (int i = 2; i < N; i++)
		if (!is_composite[i])
			sum += i;
			
	cout << sum;
}