/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


STEPS


1 - We're going to declare a bool function isValid that is going to take
    a string as a parameter

2 - We're going to declare a stack where we're going to store our 
    parentheses in a LIFO manner because if we see (, we push it in
    the stack, and if we later see ), we check if the top of the stack
    is (. If yes, we remove the match

3 - We're going to declare a map that has parenthesis characters as its
    key value pairs so that they can match the string parameter

4 - We're going to loop through the characters of the string
    - We're going to check if the characters in the string are equal
    to the opening brackets, and if they are, push

    Here's the example:

    Simulation
Initial:

s = "()[]{}"
st = [] (empty stack)

🔹 Step 1: c = '('

It’s an opening bracket.

Condition if (c == '(' || c == '[' || c == '{') is true.

Action: st.push('(')

st = ['(']

🔹 Step 2: c = ')'

It’s a closing bracket.

Go to the else part.

Check: st.empty()? → No (st has '(').

Check: st.top() != matching[')']

matching[')'] = '('

st.top() = '(' → matches ✅

Action: st.pop()

st = []

🔹 Step 3: c = '['

Opening bracket.

Action: st.push('[')

st = ['[']

🔹 Step 4: c = ']'

Closing bracket.

st.empty()? → No.

matching[']'] = '['

st.top() = '[' → matches ✅

Action: st.pop()

st = []

🔹 Step 5: c = '{'

Opening bracket.

Action: st.push('{')

st = ['{']

🔹 Step 6: c = '}'

Closing bracket.

st.empty()? → No.

matching['}'] = '{'

st.top() = '{' → matches ✅

Action: st.pop()

st = []

End of loop:

String finished.

st.empty()? → Yes ✅

Therefore: return true.

👉 That’s why "()[]{}" is valid.

The stack keeps track of open brackets that we still need to close.

When we push '(', '[', or '{', we’re saying: “Okay, I opened this,
and now I’m waiting for a proper closing bracket.”

When a closing bracket appears (')', ']', '}'), we check the top of
the stack:

If it matches, ✅ that pair is now complete.

We remove (pop) it because it’s no longer "waiting" to be closed.

This way, the stack only contains brackets that still need a match.

After looping through the string:

If the stack is empty, ✅ it means every opening bracket had a closing bracket → valid.

If the stack is not empty, ❌ it means some opening brackets never
got closed → invalid.

*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
    public:

    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            else {
                if (st.empty() || st.top() != matching[c]) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = "([])";
    cout << (sol.isValid(s) ? "true" : "false") << endl;

    s = "()[]{}";
    cout << (sol.isValid(s) ? "true" : "false") << endl;



    return 0;
}