# #TC: O(n*n)
# #SC: O(1)
#TLEing
# class Solution:
#     def maxRotateFunction(self, nums: List[int]) -> int:
#         if(len(nums)==1):
#             return 0
#         F_max=0

#         k=0
#         while(k!=len(nums)):
#             li=[i for i in range(k,len(nums))]
#             if(k>0):
#                 li.extend([i for i in range(k)])
#             F=0
#             for idx,ele in enumerate(li):
#                 F+=idx*nums[ele]
#             F_max=max(F_max,F)
#             k+=1
        
#         return F_max

#TLEing
# class Solution:
#     def maxRotateFunction(self, nums: List[int]) -> int:
#         q=collections.deque(nums)
#         k=0
#         F_max=0
#         while(k!=len(nums)):
#             F=0
#             for idx,ele in enumerate(q):
#                 F+=idx*ele
#             F_max=max(F,F_max)
#             l=q[-1]
#             q.pop()
#             q.appendleft(l)
#             k+=1
#         return F_max

#Leetcode sol
class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        s=sum(nums)
        size=len(nums)
        Fprev=sum(i*j for i,j in enumerate(nums))
        F_max=Fprev
        
        while(nums):
            F=Fprev+s-size*nums.pop()
            Fprev=F
            F_max=max(F_max,F)
            
        return F_max

            

        
