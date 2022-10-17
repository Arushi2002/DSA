#https://leetcode.com/problems/3sum/

#Brute force
#TC: O(n^3)
#SC: O(1)

# #TC: O(n^2)
# #SC: O(n)
# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         ans=[]
#         for i in range(len(nums)):
#             target=-nums[i]
#             print(target)
#             d={}
#             for j in range(len(nums)):
#                 if(i!=j):
#                     if(target-nums[j] in d):
#                         if(i!=j and i!=k)
#                             res=[nums[i],nums[j],nums[d[target-nums[j]]]]

#                             if(res.sort() not in ans):
#                                 print(res)
#                                 ans.append(res)
#                     else:
#                         d[nums[j]]=i
#         return ans

#TC: O(nlog(n))
#SC: O(n)
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res=[]
        
        for i in range(len(nums)):
            if((i==0) or (i!=0 and nums[i]!=nums[i-1])):
                target=-nums[i]
                #print(target)
                l=i+1
                r=len(nums)-1
                
                while(l<r):
                    s=nums[l]+nums[r]
                    if(s==target):
                        a=[nums[i],nums[l],nums[r]]
                        a.sort()
                        res.append(a)
                        l+=1
                        while(nums[l]==nums[l-1] and l<r):
                            l+=1
                         
                    elif(s>target):
                        r-=1
                        
                    elif(s<target):
                        l+=1
                        
        return res
                
