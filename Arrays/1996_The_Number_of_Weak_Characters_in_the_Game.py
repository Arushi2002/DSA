'''https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
This problem is comination of greedy and sort strategies. Let us consider the following example: [[6, 9], [7, 5], [7, 9], [7, 10], [10, 4], [10, 7]].

First step is to sort data, in this way we can be sure that for the first value we always have <= value. However we are not happy with =, we want to take only <.
So, we split data into groups: [9], [5, 9, 10], [4, 7] for the second parameter and process group by group.
We keep current max_y is the maximum value for the second parameter. In the beginning it is -1. When we done with last group, it becomes equal to 7, then it is equal to 10 and then again 10.
Each time we check condition q < max_y. We already sure that for the first parameter we have < inequality, by this we check if we are good for the second one.
Complexity
It is O(n log n) for time and O(n) for space.

Code'''
class Solution:
    def numberOfWeakCharacters(self, X):
        X = sorted(X)
        n = len(X)
        ans, d, max_y = 0, defaultdict(list), -1
 
        for a, b in X:
            d[a] += [b]
        print(d)
        for t in sorted(list(d.keys()))[::-1]:
            for q in d[t]:
                if q < max_y: ans += 1
            for q in d[t]:
                max_y = max(max_y, q)
                
        return ans
# class Solution:
#     def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        
#         #properties.sort(reverse=True)
#         properties.sort(key=lambda x: (-x[0],x[1]))
#         print(properties)
#         ans = 0
#         curr_max = 0
        
#         for _, d in properties:
#             if d < curr_max:
#                 ans += 1
#             else:
#                 curr_max = d
#         return ans
    
# class Solution:
#     def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        
#         properties.sort(key=lambda x: (x[0], -x[1]))
        
#         stack = []
#         ans = 0
        
#         for a, d in properties:
#             while stack and stack[-1] < d:
#                 stack.pop()
#                 ans += 1
#             stack.append(d)
#         return ans
