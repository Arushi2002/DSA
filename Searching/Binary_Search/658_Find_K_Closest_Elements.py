#https://leetcode.com/problems/find-k-closest-elements/
#class Solution:
#     def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
#         if(k==len(arr)):
#             return arr

#         diff=[]
#         for i in range(len(arr)):
#             diff.append(abs(arr[i]-x))
#         low=diff.index(min(diff))
#         out=0
#         if(low!=len(diff)-1):
#             high=low+1
#         else:
#             high=low
#             out=1
#         #print(diff)
#         k-=1
#         #print(k,high,low)
#         while(k):
#             if(out!=1):
#                 if(low!=0 and diff[low-1]<diff[high]):
#                     low-=1
#                 elif(low!=0 and diff[low-1]==diff[high]):
#                     low-=1
#                 elif(high!=len(diff)-1):
#                     high+=1
#                 elif(high==len(diff)-1):
#                     out=1
#             else:
#                 if(low!=0):
#                     low-=1
#             k-=1
#         if(out):
#             return arr[low:]
#         return arr[low:high]
            
            
class Solution:      
     def findClosestElements(self, A, k, x):
            left, right = 0, len(A) - k
            while left < right:
                mid =int( (left + right) / 2)
                if x - A[mid] > A[mid + k] - x:
                    left = mid + 1
                else:
                    right = mid
            return A[left:left + k]
