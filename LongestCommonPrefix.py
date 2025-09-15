"""

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.


STEPS

1 - We create a function that takes in a list of strings as a parameter
2 - Inside the function, an If statement must check whether the list
    is empty or not using the not operator

3 - We must set prefix to the first string in the array because a prefix
    must come from one of the strings and using logic, it must be the
    first string for convenience

4 - Since we already set prefix to the first string, we don't need to
    compare it against itself, so we must start looping from the 2nd
    string inside the list to compare it with the first string

5 - The while loop doesn't check each character of the string directly.
    Instead, it keeps shortening the prefix (by chopping off the last
    character) until the current word starts with that prefix.

6 - while not s.startswith(prefix) is a condition for what happens when
    a string doesn't match a prefix. It makes sure that the string
    matches the prefix


"""


class Solution:
    def longestCommonPrefix(self, strs):

        if not strs: # Check if the list of strings is empty
            return ""
        
        prefix = strs[0]
        
        for s in strs[1:]: # Starts from the 2nd word
            while not s.startswith(prefix):
                prefix = prefix[:-1] # Shrinks prefix
                if prefix == "":
                    return ""
        return prefix
    

sol = Solution()
strs = ["flower","flow","flight"]
print(sol.longestCommonPrefix(strs))
