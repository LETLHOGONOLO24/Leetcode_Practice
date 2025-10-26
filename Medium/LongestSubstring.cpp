/*


PROBLEM

Given a string s, find the length of the longest substring without
duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that
"bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence
and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


STEPS


1 - We create an int function that takes a string as a parameter
2 - left is going to be the left part of the sliding window -> we set it to
    zero

3 - We also set longest to zero because we want to count the longest substring
4 - We create a set that is going to store non-repeating characters

5 - Our index r is going to be the right window of the sliding window
6 - The while loop is going to check if a character in a string is in the set
    and if the character is in the set, remove it and increment the left window

7 - W is for calculating the substring and when we start, we're going to add
    the first character, so that 1 represents adding that 1st character

8 - longest is going to be the max method with longest and w as its arguments



*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left = 0;
            int longest = 0;
            unordered_set<char> sett = {};
            int n = s.size();
            int r = 0;

            for (int r = 0; r < n; r++) {
                while (sett.find(s[r]) != sett.end()) {
                    sett.erase(s[left]);
                    left++;
                }

                int w = (r - left) + 1;
                longest = max(longest, w);
                sett.insert(s[r]);
            }

            return longest;

        }
};

int main() {
    Solution sol;
    string s1 = "abcabcabc";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    cout << "Length of s1: " << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "Length of s2: " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "Length of s3: " << sol.lengthOfLongestSubstring(s3) << endl;

    return 0;
}