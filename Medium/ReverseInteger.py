class Solution:
    def reverse(self, x : int) -> int:
        INT_MAX = 2147483647
        INT_MIN = -2147483647

        sign = -1 if x < 0 else 1
        x = abs(x)

        reversed_num = 0
        
        while x != 0:
            digit = x % 10
            x = x // 10

            if sign == 1:

                if reversed_num > INT_MAX // 10:
                    return 0
                
                if reversed_num == INT_MAX // 10 and digit > 7:
                    return 0
                
            else:
                if reversed_num > 2147483647 // 10:
                    return 0
                
                if reversed_num == 2147483647 // 10 and digit > 8:
                    return 0
            reversed_num = reversed_num * 10 + digit

        return sign * reversed_num
    
sol = Solution()
x = 123
y = -123
z = 120

x_num = sol.reverse(x)
y_num = sol.reverse(y)
z_num = sol.reverse(z)

print("\nReversing integers\n")
print(x_num)
print(y_num)
print(z_num)