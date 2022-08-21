from typing import Iterable


class Solution:
    # Idea:
    # 1. Extract and store the columns that need to be set to 0
    # 2. Set any rows that contain a 0 to 0
    # 3. Based on 1 set the cells corresponding to 'zero' columns to 0

    # Complexities:
    # * Space O(n)
    # * Time  O(nm)
    
    def setZeroes(matrix: Iterable[Iterable[int]]) -> None:
        zero_cols = set()

        for row in matrix:
            contains_zero = False
            for col_index, val in enumerate(row):
                if val != 0: continue 
                zero_cols.add(col_index)
                contains_zero = True
            
            if contains_zero == False: continue
            for i in range(len(row)):
                row[i] = 0

        for row in matrix:
            for i in zero_cols:
                row[i] = 0