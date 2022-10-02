# https://leetcode.com/contest/weekly-contest-313/problems/maximum-sum-of-an-hourglass/
class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        rows=len(grid)
        cols=len(grid[0])
        sum=0
        if(rows==3 and cols==3):
            for j in range(0,3):
                sum+=grid[0][j]+grid[2][j]
            sum+=grid[1][1]
            return sum
        l=0
        r=l+2
        rn=0
        rn2=rn+2
        maxx=0
        sum=0
        while(rn2<rows):
            while(l+2<cols):
                sum+=grid[rn][l]+grid[rn][l+1]+grid[rn][l+2]
                sum+=grid[rn2][l]+grid[rn2][l+1]+grid[rn2][l+2]
                sum+=grid[rn+1][l+1]
                #print(sum)
                maxx=max(sum,maxx)
                sum=0
                l+=1
            l=0
            rn+=1
            rn2+=1
        return maxx
        
