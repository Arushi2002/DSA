class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        #c=1
        res=0
        s=0
        for i in range(len(nums)):
            if(nums[i]==1):
                s+=1
            else:
                res=max(s,res)
                s=0
                #c=0
        res=max(res,s)
        return res
