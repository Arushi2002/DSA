# https://leetcode.com/problems/continuous-subarray-sum/submissions/

# #Brute force 
# class Solution:
#     def checkSubarraySum(self, nums: List[int], k: int) -> bool:
#         for i in range(len(nums)):
#             s=nums[i]
#             for j in range(i+1,len(nums)):
#                 s+=nums[j]
#                 if(s%k==0):
#                     return True
#         return False

# tried perfix but is o(n2)
#class Solution:
#     def checkSubarraySum(self, nums: List[int], k: int) -> bool:
#         s=0
#         prefix=[]
#         for i in range(len(nums)):
#             s+=nums[i]
#             prefix.append(s)
#         for i in range(1,len(nums)):
#             if(i==1):
#                 if(prefix[i]%k==0):
#                     return True
#             for j in range(0,i-1):
#                 if((prefix[i]-prefix[j])%k==0):
#                     return True
                
#         return False

#Time: O(n)
#Space: O(n)
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        prefix=0
        rem={0:-1}
        for i in range(len(nums)):
            prefix+=nums[i]
            if(prefix%k in rem):
                if(i-rem[prefix%k]>=2):
                    return True
            else:
                rem[prefix%k]=i
        return False
                
