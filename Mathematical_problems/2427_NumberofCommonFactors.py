# https://leetcode.com/contest/weekly-contest-313/problems/number-of-common-factors/
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        if(a==1 or b==1): return 1
        minn=min(a,b)
        ans=0
        for i in range(1,minn+1):
            if(a%i==0 and b%i==0):
                ans+=1
        return ans
