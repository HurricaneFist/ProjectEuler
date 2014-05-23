#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int triangle(int n) {
	int result = 1;
	
	for (int i = 1; i < n; i++)
		result += i + 1;
		
	return result;
}

bool triangular(int n) {
	for (int i = 1; i <= n; i++)
		if (triangle(i) == n)
			return true;
	
	return false;
}

// I used a script to delete all quotation marks and change the commas to spaces in the file
int main() {
	ifstream file("wordswithspaces.txt");
	int total = 0;
	string word;
	
	while (file >> word) {
		int n = 0;
		
		for (int i = 0; i < word.size(); i++)
			n += word[i] - 64;
			
		if (triangular(n))
			total++;
	}
	
	cout << total;
}