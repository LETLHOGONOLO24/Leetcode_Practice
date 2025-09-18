/*

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.


STEPS

1 - We create an int function strStr() that takes string parameters
    needle and haystack
2 - size_t is an unsigned integer type used to represent sizes and
    counts of objects in memory. It's defined in several headers
    like <cstddef>, <cstdio>, <cstdlib>, <cstring>, etc.

    - Use size_t for: array indices, loop counters with containers,
    size calculations

3 - pos (position) is haystack.find(needle) meaning find needle in
    haystack
4 - The if statement pos != string::npos means If the position is
    NOT equal to 'no position found. string::npos is a special code
    that means "I didn't find it

5 - What happens in each case: If found: return static_cast<int>(pos);
    → Give back the position number
    - If not found: return -1; → Give back -1
    - Why static_cast<int>? The computer uses a special number type for
    positions, but we want to give back a regular number, so we convert
    it.

6 - Using != lets us handle the error case first and then get to the
    happy path. So using != is often more natural because we think about
    the problem case first.

*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:

    int strStr(string haystack, string needle) {

        size_t pos = haystack.find(needle);
        if (pos != string::npos) {
            return static_cast<int>(pos);
        }
        else {
            return -1;
        }
    }
};

int main() {

    Solution sol;
    string haystack = "sadbutsad";
    string needle = "sad";

    int result = sol.strStr(haystack, needle);

    if (result != -1) {
        cout << "Found '" << needle << "' at position: " << result << endl;
        cout << "Surrounding text: " << haystack.substr(result, 20) << "..." << endl;
    }
    else {
        cout << "String not found" << endl;
    }
    return 0;
}