'''
We have been given a matrix which is off course an n dimensional array , 
we have to rotate it 90 degree clockwise .
Example : Input: [[1,2,3],[4,5,6],[7,8,9]]
          Output : [[7,4,1],[8,5,2],[9,6,3]]
Approach : Note that rotating 90 degrees is actually , taking the transpose and mirroring it , i.e. 
          reverse each of its row . 

'''






class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
    
        # Step 1: Transpose the matrix
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    
        # Step 2: Reverse each row
        for i in range(n):
            matrix[i].reverse()