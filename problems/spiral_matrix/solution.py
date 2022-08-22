from typing import List

class Solution:
    def spiralOrder(matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])

        r = 0 # track current row
        c = 0 # track current column
        
        directions = [1, 0, -1, 0] # defines sequence of direction switching

        dx = 0 # index of current direction in terms of moving left to right
        dy = 3 # index of current direction in terms of moving top to bottom

        res = []

        for i in range(m * n):
            res.append(matrix[r][c])
            r += directions[dy]
            c += directions[dx]

            if m == 0 and n == 0: break

            if n != 0 and (c + 1) % n == 0:
                n -= 1
                dx = (dx + 1) % len(directions)
                dy = (dy + 1) % len(directions)
            
            if m != 0 and (r + 1) % m == 0:
                m -= 1
                dy = (dy + 1) % len(directions)
                dx = (dx + 1) % len(directions)    
            
            print(r, c)

        return res

matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

print(Solution.spiralOrder(matrix))
