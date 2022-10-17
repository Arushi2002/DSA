'''The idea is that we need to go back a lot of times. Define by dp[i] is number of days to reach cell i.
We can only reach it from the cell i-1, so we need at least dp[i-1] steps. Then it will lead us to dp[A[i-1]] cell, because we visited i-1 for the first time.
Then we need to reach i-1 from A[i-1] again. And finally we need one more step.

Complexity
It is O(n) for time and space.'''
#https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/

class Solution:
    def firstDayBeenInAllRooms(self, A) -> int:
        n, M = len(A), 10**9 + 7
        dp = [0]*n
        for i in range(1, n):
            dp[i] = (2*dp[i-1] - dp[A[i-1]] + 2) % M

        return dp[-1] 
