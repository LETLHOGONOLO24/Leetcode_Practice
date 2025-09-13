#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> roman_values = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

		int total = 0;

		// Lets use VI
		for (int i = 0; i < s.length(); i++) {
			if (i + 1 < s.length() && roman_values[s[i]] < roman_values[s[i + 1]]) {
				total += roman_values[s[i + 1]] - roman_values[s[i]];
				i++;
			}
			else {
				total += roman_values[s[i]];
			}
		}
		return total;
	}
};

int main() {
	Solution sol;

	cout << endl << sol.romanToInt("III");
	cout << endl << sol.romanToInt("LVIII");
	cout << endl << sol.romanToInt("MCMXCIV");

	return 0;

}