#include <iostream>
using namespace std;

string to_string(int n) {
	const string ONES[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
	             TEENS[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
				            "seventeen", "eighteen", "nineteen"},
				 TENS[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", 
				           "eighty", "ninety"};
	
	if (n < 10)
		return ONES[n-1];
	
	if (n < 20 && n > 10)
		return TEENS[n-11];
	
	if (n == 10 || (n > 19 && n < 100))
		return TENS[n/10 - 1] + ((n % 10) ? ONES[n%10 - 1] : "");
	
	if (n >= 100 && n < 1000 && (n % 100 > 10 && n % 100 < 20))
		return ONES[n/100 - 1] + "hundredand" + TEENS[n%100 - 11];
	
	if (n >= 100 && n < 1000)
		return ONES[n/100 - 1] + "hundred" + (n % 100 ? "and" + (n/10 % 10 ? TENS[(n -
		       (n/100)*100)/10 - 1] : "") + (n % 10 ? ONES[n%10 - 1] : "") : "");
			   
	if (n == 1000)
		return "onethousand";
}

int main() {
	int num_letters = 0;
	
	for (int i = 1; i <= 1000; i++)
		num_letters += to_string(i).size();
		
	cout << num_letters;
}