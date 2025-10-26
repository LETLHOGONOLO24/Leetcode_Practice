"""

LONGEST PALINDROME IN PYTHON


STEPS


1 - 



"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n <= 1:
            return s
        
        # Create DP table: dp[i][j] will be True if substring from i to j is palindrome
        dp = [[False] * n for _ in range(n)]
        start = 0
        max_length = 1
        
        # All single characters are palindromes
        for i in range(n):
            dp[i][i] = True
        
        # Check 2-character palindromes
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start = i
                max_length = 2
        
        # Check longer palindromes (length 3 to n)
        for length in range(3, n + 1):
            for i in range(0, n - length + 1):
                j = i + length - 1  # Ending index
                
                # Check if first and last chars match AND inner substring is palindrome
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    if length > max_length:
                        start = i
                        max_length = length
        
        return s[start:start + max_length]

# Test the solution

sol = Solution()
    
s1 = "babad"
print(f"Input: {s1}")
print(f"Output: {sol.longestPalindrome(s1)}")
    
s2 = "cbbd"
print(f"Input: {s2}")
print(f"Output: {sol.longestPalindrome(s2)}")
    
s3 = "a"
print(f"Input: {s3}")
print(f"Output: {sol.longestPalindrome(s3)}")