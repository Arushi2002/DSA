class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[1])
        end1=points[0][1]
        arrows=1
        for start, end in points:
            if(start>end1):
                end1=end
                arrows+=1
        return arrows
