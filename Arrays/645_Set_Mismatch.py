# #TC: O(2n)
# #SC: O(2n)
# class Solution:
#     def findErrorNums(self, nums: List[int]) -> List[int]:
#         #func should return [dup,missingno]
#         #Split question into 2 parts
#         #find missing no
#         s=set(nums)
#         for i in range(1,len(nums)+1):
#             if(i not in s):
#                 missing=i
#                 break
                
#         #find dup no
#         m={}
#         for i in range(len(nums)):
#             if(nums[i] in m):
#                 return [nums[i],missing]
#             else:
#                 m[nums[i]]=i
                
#Best sol
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        #func should return [dup,missingno]
        arr=[0]*(len(nums)+1)
        for i in range(len(nums)):
            arr[nums[i]]+=1
        for i in range(1,len(nums)+1):
            if(arr[i]==0):
                missingno=i
            elif(arr[i]==2):
                dup=i
        return [dup,missingno]
        
