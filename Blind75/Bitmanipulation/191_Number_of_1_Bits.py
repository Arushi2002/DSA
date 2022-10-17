https://leetcode.com/problems/number-of-1-bits/

# #M1
# class Solution:
#     def hammingWeight(self, n: int) -> int:
#         return (bin(n)[2:]).count('1')
    
    
#Allthe sols below are O(1) or O(32)
# #M2
# class Solution:
#     def hammingWeight(self, n: int) -> int:
#         res=0
#         while(n!=0):
#             if(n%2==1):
#                 res+=1
#             n=n>>1
#         return res
    
# #M3
# class Solution:
#     def hammingWeight(self, n: int) -> int:
#         res=0
#         while(n):
#             if(n%2==1):
#                 res+=1
#             n=n>>1
#         return res

#Most optimized
#M4
class Solution:
    def hammingWeight(self, n: int) -> int:
        res=0
        while(n):
            n=n&(n-1)
            res+=1
        return res
    
