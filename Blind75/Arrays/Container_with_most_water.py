# #Brute force 
# class Solution:
#     def maxArea(self, height: List[int]) -> int:
#         area=0
#         for i in range(len(height)):
#             for j in range(i+1,len(height)):
#                 area=max(area,min(height[i],height[j])*(j-i))
#         return area
 
# Optimized
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l=0
        area=0
        r=len(height)-1
        while(l<r):
            a=min(height[l],height[r])*(r-l)
            area=max(a,area)
            if(height[l]<height[r]):
                l+=1
            else:
                r-=1
        return area
