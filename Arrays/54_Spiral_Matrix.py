#O(m*n) , O(1)
# https://leetcode.com/problems/spiral-matrix/
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        top=0
        bottom=len(matrix)
        left=0
        right=len(matrix[0])
        res=[]
        while(left<right and top<bottom):
            #interating through top row
            for i in range(left,right):
                res.append(matrix[top][i])
            top+=1
            #interating through right row
            for i in range(top,bottom):
                res.append(matrix[i][right-1])
            right-=1
            #interating through bottom row
            if not(left<right and top<bottom):
                break
            for i in range(right-1,left-1,-1):
                res.append(matrix[bottom-1][i])
            bottom-=1
            #interating through left row
            for i in range(bottom-1,top-1,-1):
                res.append(matrix[i][left])
            left+=1
        return res
