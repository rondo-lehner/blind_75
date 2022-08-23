from typing import List

# Idea:
# 1. Start in a direction until the boundary of the matrix is reached
# 2. Change the direction by 90 degrees
# 3. Eliminate the column/row which was traversed from the traversable matrix
# 4. Repeat Step 1 until the result contains n*m entries from the original matrix

class Solution:
    def spiralOrder(matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])

        b_t = 0                     # top
        b_b = m - 1                 # bottom
        b_l = 0                     # left
        b_r = n - 1                 # right

        cursor = {
            'row': 0,
            'col': 0
        }
        
        directions = [1, 0, -1, 0] # defines sequence of direction switching

        direction_indices = {
            'col': 0,   # index referring to direction which horizontally traverses the matrix
            'row': 3    # index referring to direction which vertically traverses the matrix
        }

        res = []

        for i in range(m * n):
            res.append(matrix[cursor['row']][cursor['col']])

            if directions[direction_indices['col']] == 1 and cursor['col'] == b_r:
                b_t += 1
                Solution.changeDirection(direction_indices)

            if directions[direction_indices['col']] == -1 and cursor['col'] == b_l:
                b_b -= 1
                Solution.changeDirection(direction_indices)

            if directions[direction_indices['row']] == 1 and cursor['row'] == b_b:
                b_r -= 1
                Solution.changeDirection(direction_indices)
            
            if directions[direction_indices['row']] == -1 and cursor['row'] == b_t:
                b_l += 1
                Solution.changeDirection(direction_indices)

            cursor['row'] += directions[direction_indices['row']]
            cursor['col'] += directions[direction_indices['col']]

        return res
    
    @staticmethod
    def changeDirection(direction_indices):
        direction_indices['col'] = (direction_indices['col'] + 1) % 4
        direction_indices['row'] = (direction_indices['row'] + 1) % 4

        return direction_indices


matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

print(Solution.spiralOrder(matrix))
