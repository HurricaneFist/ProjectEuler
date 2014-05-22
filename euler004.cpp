#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int digit_at(int n, int i) {
	return (n % (int) pow(10, i)) / (int) pow(10, i-1);
}

bool palindromic(int n) {
	vector<int> digits;
	
	for (int i = 0; i < (int) log10(n)+1; i++)
		digits.push_back(digit_at(n, i+1));
		
	for (int i = 0, j = digits.size()-1; i < digits.size(); i++, j--)
		if (digits[i] != digits[j])
			return false;
			
	return true;
}

int main() {
	int max_palindrome = 0;
	
	for (int i = 100; i < 1000; i++)
		for (int j = 100; j < 1000; j++)
			if (palindromic(i*j) && i*j > max_palindrome)
				max_palindrome = i*j;
	
	cout << max_palindrome;
}