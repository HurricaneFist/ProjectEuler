#include <iostream>
using namespace std;

int main() {
	int i = 20; 
	
	while (i++)
		for (int j = 1; j <= 20; j++) {
			if (i % j)
				break;
			if (j == 20)
				goto outer;
		}
	
	outer: cout << i;
}