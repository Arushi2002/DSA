# #TC: O(n*k)
# #SC: O(1)
# #Brute force
# class Solution:
#     def minStoneSum(self, piles: List[int], k: int) -> int:
#         for j in range(k):
#             i=piles.index(max(piles))
#             piles[i]=piles[i]-int(piles[i]/2)
#             #print(piles)
#         return sum(piles)

#Optimized solution using heaps
import heapq
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        heap=[-num for num in piles]
        heapq.heapify(heap)
        for _ in range(k):
            n=-heapq.heappop(heap)
            remove=n//2
            new_n=n-remove
            heapq.heappush(heap,-new_n)

        return -sum(heap)
            
