class Solution:
    def myAtoi(self, s: str) -> int:
        # 32-bit integer limits
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        
        # Step 1: Ignore leading whitespace
        s = s.lstrip()
        
        # If string is empty after stripping whitespace
        if not s:
            return 0
        
        # Step 2: Handle signedness
        sign = 1
        index = 0
        
        if s[0] == '-':
            sign = -1
            index += 1
        elif s[0] == '+':
            index += 1
        
        # Step 3: Convert digits
        result = 0
        
        while index < len(s):
            # If current character is not a digit, stop conversion
            if not s[index].isdigit():
                break
            
            digit = int(s[index])
            
            # Step 4: Check for overflow BEFORE adding the digit
            # For positive numbers
            if sign == 1:
                if result > INT_MAX // 10:
                    return INT_MAX
                if result == INT_MAX // 10 and digit > 7:
                    return INT_MAX
            # For negative numbers
            else:
                if result > 2147483648 // 10:
                    return INT_MIN
                if result == 2147483648 // 10 and digit > 8:
                    return INT_MIN
            
            # Build the number P.S., this is how you get rid of a leading zero
            result = result * 10 + digit
            index += 1
        
        # Apply sign
        result = sign * result
        
        # Clamp to 32-bit range (redundant given our overflow checks, but safe)
        if result < INT_MIN:
            return INT_MIN
        if result > INT_MAX:
            return INT_MAX
            
        return result

sol = Solution()
s1 = "42"
s2 = " -042"
s3 = "1337c0d3"
s4 = "0-1"
s5 = "words and 987"

num1 = sol.myAtoi(s1)
num2 = sol.myAtoi(s2)
num3 = sol.myAtoi(s3)
num4 = sol.myAtoi(s4)
num5 = sol.myAtoi(s5)

print("\nResults\n")
print(num1)
print(num2)
print(num3)
print(num4)
print(num5)
print("\n------")