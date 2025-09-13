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
