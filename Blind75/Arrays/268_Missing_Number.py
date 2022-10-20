# #O(3n)
# class Solution:
#     def missingNumber(self, nums: List[int]) -> int:
#         a=max(nums)
#         for i in range(a+2):
#             if(i not in nums):
#                 return i

# class Solution:
#     def missingNumber(self, nums: List[int]) -> int:
#         s=set(nums)
#         n=len(nums)
#         for i in range(n+1):
#             if(i not in s):
#                 return i
      
# #sorting
# class Solution:
#     def missingNumber(self, nums: List[int]) -> int:
#         nums.sort()
#         for i in range(len(nums)):
#             if(i!=nums[i]):
#                 return i
#         return i+1

# class Solution:
#     def missingNumber(self, nums: List[int]) -> int:
#         ans=0
#         n=len(nums)
#         for i in range(1,n+1):
#             ans^=i
#         for i in range(n):
#             ans^=nums[i]
#         return ans


# class Solution:
#     def missingNumber(self, nums: List[int]) -> int:
#         n=len(nums)
#         s1=int(n*(n+1)/2)
#         s2=sum(nums)
#         return s1-s2

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans=len(nums)
        for i in range(len(nums)):
            ans+=(i-nums[i])
        return ans
