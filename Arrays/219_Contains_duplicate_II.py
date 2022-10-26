#we cannot sort coz relative pos
#Brute force
#gives TLE
# class Solution:
#     def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
#         for i in range(len(nums)):
#             for j in range(i+1,len(nums)):
#                 if(nums[i]==nums[j] and abs(i-j)<=k):
#                     return True
#         return False


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        m={}
        for i in range(len(nums)):
            if(nums[i] in m and abs(i-m[nums[i]])<=k):
                return True
            else:
                m[nums[i]]=i
