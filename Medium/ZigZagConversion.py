class Solution:
    
    def string_to_zigzag_conversion(self, s: str, numRows: int) -> list:
        matrix = [['' for _ in range(len(s))] for _ in range(numRows)]
        row, col = 0, 0

        for i, char in enumerate(s):
            matrix[row][col] = char

            if row == 0:
                direction = 1 # Moving down
            elif row == numRows - 1:
                direction = -1 # Moving up
            row += direction

            if direction == 1:
                col += 1
        return matrix       
    
sol = Solution()
s1 = 'PAYPALISHIRING'
s2 = 'A'
numRows_1 = 3
numRows_2 = 4
numRows_3 = 1

matrix = sol.string_to_zigzag_conversion(s1, numRows_1)
matrix_2 = sol.string_to_zigzag_conversion(s1, numRows_2)
matrix_3 = sol.string_to_zigzag_conversion(s2, numRows_3)

print("\nLets see the output\n")
print(matrix)
print("\nMatrix 2\n")
print(matrix_2)
print("\nMatrix 3\n")
print(matrix_3)