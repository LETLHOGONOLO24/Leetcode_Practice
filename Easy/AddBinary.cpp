/*

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.



Example 1

11
01
--

carry = 0
sum = 1+1+0(carry) = 2
convert 2 to binary = 10
0 is written down, carry = 1

sum = 1+0+1(carry) = 2
convert 2 to binary = 10
0 is written down because we take from right to left
result = 00
carry = 1
final result = 100

Example 2

dcba

1010
1011
----

a
carry = 0
0+1+0 = 1
binary = 01
carry = 0
result = 1

b
1+1+0 = 2
binary = 10
carry = 1
result = 01

c
0+0+1 = 1
binary = 01
carry = 0
result = 101

d
1+1+0 = 2
binary = 10
carry = 1
result = 0101
final = 10101


STEPS


1 - we set result to empty string so that we can store our result here
2 - We set carry = 0 because before adding the binary numbers, carry = 
    0

3 - while (i >= 0 || j >= 0 || carry > 0)  says keep looping while ANY
    of these are true:
    -There are still digits left in string a (i >= 0)
    -There are still digits left in string b (j >= 0)
    -There's still a carry value that needs to be processed (carry > 0)

4 - int digitA = (i >= 0) ? a[i] - '0' : 0;
    int digitB = (j >= 0) ? b[j] - '0' : 0; means If we still have digits
    in string a and b, get the current digit and convert it from char to
    int. Otherwise, use 0."

5 - int total = digitA + digitB + carry; means add the current digit from
    string A, current digit from string B, and any carry from the previous
    column.

6 - int currentDigit = total % 2; says the digit we write down in this
    column is the remainder when we divide the total by 2.

    11
    01
    --
     0 <- is the currentDigit

    If total = 1 → 1 % 2 = 1 
    If total = 2 → 2 % 2 = 0 
    If total = 3 → 3 % 2 = 1 

7 - carry = total / 2; says the new carry is how many times 2 fits into the
    total (integer division).
    If total = 1 → 1 / 2 = 0 (no carry)
    If total = 2 → 2 / 2 = 1 (carry 1)
    If total = 3 → 3 / 2 = 1 (carry 1)

8 - result.push_back(currentDigit + '0'); says convert the integer digit back
    to a character and add it to our result string.
    currentDigit + '0': Converts integer back to char
    0 + '0' = '0'
    1 + '0' = '1'

9 - i--;
    j--; says decrement to the left

10 - reverse(result.begin(), result.end());
    return result; says since we built the result from right to left (least
    significant digit first), we need to reverse it to get the correct order
    (most significant digit first). [0,0,1] -> [1,0,0]


*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            string result = "";
            int carry = 0;

            int i = a.size()-1;
            int j = b.size()-1;

            while (i >= 0 || j >= 0 || carry > 0) {
                int digitA = (i >= 0) ? a[i] - '0' : 0;
                int digitB = (j >= 0) ? b[j] - '0' : 0;

                int total = digitA + digitB + carry;
                int currentDigit = total % 2;
                carry = total / 2;

                result.push_back(currentDigit + '0');

                i--;
                j--;
            }

            reverse(result.begin(), result.end());
            return result;

        }
};

int main() {
    Solution sol;

    string a1 = "11", b1 = "1";
    string a2 = "1010", b2 = "1011";
    string a3 = "0", b3 = "0";
    string a4 = "1111", b4 = "1111";
    
    cout << "Input: a = \"" << a1 << "\", b = \"" << b1 << "\"" << endl;
    cout << "Output: \"" << sol.addBinary(a1, b1) << "\"" << endl << endl;
    
    cout << "Input: a = \"" << a2 << "\", b = \"" << b2 << "\"" << endl;
    cout << "Output: \"" << sol.addBinary(a2, b2) << "\"" << endl << endl;
    
    cout << "Input: a = \"" << a3 << "\", b = \"" << b3 << "\"" << endl;
    cout << "Output: \"" << sol.addBinary(a3, b3) << "\"" << endl << endl;
    
    cout << "Input: a = \"" << a4 << "\", b = \"" << b4 << "\"" << endl;
    cout << "Output: \"" << sol.addBinary(a4, b4) << "\"" << endl;
    
    return 0;
}