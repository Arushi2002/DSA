#https://leetcode.com/problems/counting-bits/
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans=[]
        for i in range(n+1):
            cnt=0
            p=i
            while(p):
                p=p&(p-1)
                cnt+=1
            ans.append(cnt)
        return ans
    
    
# #nlogn
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans=[]
        for i in range(n+1):
            cnt=0
            p=i
            while(p):
                if(p%2==1):
                    cnt+=1
                p=p>>1
            ans.append(cnt)
        return ans
    
#O(n)
#dp
class Solution:
    def countBits(self, n: int) -> List[int]:
        dp=[0]*(n+1)
        offset=1
        for i in range(1,n+1):
            if(offset*2==i):
                offset=i
            dp[i]=1+dp[i-offset]
        return dp
        
    
    
            
