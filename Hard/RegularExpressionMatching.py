class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # Create a memoization dictionary to store results of subproblems
        memo = {}
        
        def dfs(i, j):
            # If we've already computed this state, return it
            if (i, j) in memo:
                return memo[(i, j)]
            
            # Base case: if we've reached the end of both strings
            if i >= len(s) and j >= len(p):
                return True
            
            # If we've reached the end of pattern but not string
            if j >= len(p):
                return False
            
            # Check if current characters match (considering '.')
            match = i < len(s) and (s[i] == p[j] or p[j] == '.')
            
            # Handle '*' pattern
            if j + 1 < len(p) and p[j + 1] == '*':
                # Two possibilities:
                # 1. Don't use the '*' (skip current char and '*')
                # 2. Use the '*' if current chars match (move i forward, keep j)
                result = (dfs(i, j + 2) or  # Skip the 'x*' pattern
                         (match and dfs(i + 1, j)))  # Use '*' to match one more
                memo[(i, j)] = result
                return result
            
            # No '*' following, just match current character
            if match:
                result = dfs(i + 1, j + 1)
                memo[(i, j)] = result
                return result
            
            # No match found
            memo[(i, j)] = False
            return False
        
        return dfs(0, 0)

sol = Solution()