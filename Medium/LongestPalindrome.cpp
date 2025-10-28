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


1 - vector<vector<bool>> dp(n, vector<bool>(n, false)) creates a 2D
    boolean vector (table) of size n x n, initialized to false. This
    DP table will store whether substring from index i to j is a palindrome.

2 - int start = 0 and int maxLength = 1 initialize variables to track
    the starting index and length of the longest palindrome found. We
    start with length 1 because single characters are palindromes.

3 - This loop sets dp[i][i] = true for all i from 0 to n-1. This marks that
    every single character by itself is a palindrome (substring from i to i).

4 - This loop checks all 2-character substrings. for (int i = 0; i < n - 1; i++)
    goes through each possible starting position for 2-character substrings.
    if (s[i] == s[i + 1]) checks if two adjacent characters are the same. If they
    are, dp[i][i + 1] = true marks this 2-character substring as a palindrome,
    and we update start = i and maxLength = 2 to remember this palindrome.

5 - This is the main logic for finding longer palindromes. for (int len = 3; len
    <= n; len++) starts checking from length 3 up to the full string length. for
    (int i = 0; i <= n - len; i++) goes through all possible starting positions
    for substrings of current length. int j = i + len - 1 calculates the ending
    index of the current substring.

6 - if (s[i] == s[j] && dp[i + 1][j - 1]) checks two conditions: first, if the first
    and last characters of the current substring match, and second, if the inner
    substring (from i+1 to j-1) is already known to be a palindrome (we checked this
    in previous iterations for shorter lengths). If both conditions are true, dp[i][j]
    = true marks the current substring as palindrome, and if this palindrome is longer
    than our current longest, we update start = i and maxLength = len.

7 - return s.substr(start, maxLength) extracts and returns the longest palindromic
    substring using the stored start index and length.
8 - We use the DP vector dp[i][j] to store and reuse computation results so we don't
    have to repeatedly check if the same substring is a palindrome.

9 - The key insight: A substring s[i...j] is a palindrome if:
    - The first and last characters are equal (s[i] == s[j])

    - The inner substring s[i+1...j-1] is also a palindrome
10 - Without the DP table, we'd have to repeatedly check the inner substring, leading
    to O(n³) time complexity. With DP, we build the solution bottom-up:

    - First we know all length 1 substrings are palindromes
    - Then we check length 2 substrings

    - Then for longer lengths, we can quickly check using previously stored results
11 - This reduces the time complexity from O(n³) to O(n²) while using O(n²) space to
store intermediate results.


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