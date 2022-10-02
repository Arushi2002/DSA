#https://leetcode.com/problems/spiral-matrix/submissions/
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        li=list(range(1,n*n+1))
        res=[]
        for i in range(n):
            l=[]
            for j in range(n):
                l.append(0)
            res.append(l)
        #print(res)
        top=0
        bottom=n
        left=0
        right=n
        
        while(top<bottom and left<right):
            #iterating through top
            for i in range(left,right):
                res[top][i]=li[0]
                li.pop(0)
            top+=1
            #iterating through right
            for i in range(top,bottom):
                res[i][right-1]=li[0]
                li.pop(0)
            right-=1
            #iterating through bottom
            for i in range(right-1,left-1,-1):
                res[bottom-1][i]=li[0]
                li.pop(0)
            bottom-=1
            #iterating through left
            for i in range(bottom-1,top-1,-1):
                res[i][left]=li[0]
                li.pop(0)
            left+=1
        return res

        
