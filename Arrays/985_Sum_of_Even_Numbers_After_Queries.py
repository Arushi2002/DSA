#https://leetcode.com/problems/sum-of-even-numbers-after-queries/

#O(2n)
class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        ans=[]
        sum=0
        for n in nums:
            if(n%2==0):
                sum+=n
        for query in queries:
            val=query[0]
            i=query[1]
            if(nums[i]%2==0):
                sum-=nums[i]
            nums[i]+=val
            if(nums[i]%2==0):
                sum+=nums[i]
            ans.append(sum)
        
        return ans
    
#Same approach but shorter
 class Solution(object):
    def sumEvenAfterQueries(self, A, queries):
        S = sum(x for x in A if x % 2 == 0)
        ans = []

        for x, k in queries:
            if A[k] % 2 == 0: S -= A[k]
            A[k] += x
            if A[k] % 2 == 0: S += A[k]
            ans.append(S)

        return ans           
