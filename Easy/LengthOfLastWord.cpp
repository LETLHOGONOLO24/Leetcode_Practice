/*

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


STEPS


1 - Declare an int function that takes a string as a parameter and returns
    an int
2 - Declare i as size of the string - 1 so that when we loop, we don't
    go out of bounds

3 - Declare length_of_lastWord to 0 so that when we count the length of
    the last word, we increment
4 - The first while loop loops from the last character in the string and
    checks for white space at the same time while decrementing or going
    from last element to first element. This while loop checks the white
    space at the end of the string.

5 - The if statement is for if the string is all white space, it should
    return 0
6 - The 2nd while loop is for checking white space is not found so that
    it can count the last words using the variable length_of_lastWord while
    decrementing until white space is found

7 - Return length_of_lastWord



*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
    public:

    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int length_of_lastWord = 0;

        while (i >= 0 && isspace(s[i])) {
            i--;
        }

        if (i < 0) return 0;
        
        while (i >= 0 && !isspace(s[i])) {
            length_of_lastWord++;
            i--;
        }

        return length_of_lastWord;

    }
};

int main() {

    Solution sol;
    string s = "Hello World";

    int result = sol.lengthOfLastWord(s);
    cout << "Length of last word: " << result << endl;

}

