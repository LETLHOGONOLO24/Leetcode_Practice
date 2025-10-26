/*

PROBLEM

Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.


STEPS


1 - 


*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            if (n <= 1) return s;

            vector<vector<bool>> dp(n, vector<bool>(n, false));
            int start = 0;
            int maxLength = 1;

            // All single characters are palindromes
            for (int i = 0; i < n; i++) {
                dp[i][i] = true;
            }

            // Check 2-character palindromes
            for (int i = 0; i < n -1; i++) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = true;
                    start = i;
                    maxLength = 2;
                }
            }

            // Check longer palindromes (length 3+)
            for (int len = 3; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int j = i + len - 1;

                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (len > maxLength) {
                            start = i;
                            maxLength = len;
                        }
                    }
                }
            }

            return s.substr(start, maxLength);
        }
};

int main() {
    Solution sol;

    string s1 = "babad";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.longestPalindrome(s2) << endl;

    return 0;
}