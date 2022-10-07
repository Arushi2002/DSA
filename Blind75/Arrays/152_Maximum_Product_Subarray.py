#https://leetcode.com/problems/maximum-product-subarray/
  
  class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res=max(nums)
        currmax=1
        currmin=1
        for i in range(len(nums)):
            if(nums[i]==0):
                currmax,currmin=1,1
                continue
            temp=currmax*nums[i]
            currmax=max(currmax*nums[i],currmin*nums[i],nums[i])
            currmin=min(temp,currmin*nums[i],nums[i])
            res=max(currmax,res)
        return res
            

# #Brute force
# #O(n2)
# class Solution:
#     def maxProduct(self, nums: List[int]) -> int:
#         curr_prod=nums[0]
#         max_prod=nums[0]
#         for i in range(len(nums)):
#             curr_prod=nums[i]
#             max_prod=max(curr_prod,max_prod)
#             for j in range(i+1,len(nums)):
#                 curr_prod*=nums[j]
#                 max_prod=max(curr_prod,max_prod)
        
#         return max_prod

# class Solution:
#     def maxProduct(self, nums: List[int]) -> int:
#         prefix
