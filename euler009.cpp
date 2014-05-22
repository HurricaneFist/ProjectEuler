#include <iostream>
using namespace std;
// on the slow side

int main() {
	int a = 1, b = 1, c = 1;
	
	while (a++)
		while (b++)
			while (c++)
				if (a*a + b*b == c*c && a+b+c == 1000)
					goto outside;
	
	outside: cout << a*b*c;
}