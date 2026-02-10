class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [''] * numRows
        current_row = 0
        going_down = False

        for char in s:
            rows[current_row] += char
            if current_row == 0 or current_row == numRows - 1:
                going_down = not going_down
            current_row += 1 if going_down else -1

        return ''.join(rows)
    
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