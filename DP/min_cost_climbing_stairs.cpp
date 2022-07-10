class Solution {
public:
    
/*  While trying to solve this problem like this. If I'm at my current location what was the minimum cost
I paid to reach this location.
Let  cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
at the first location the minimum cost I have to pay is 1.
cost = [1,]
for the second stair the minum cost I have to pay is that stair itself because u can skep a stair.
cost = [1,100]
for the third stair i could have come from the first stair or the second stair.Since the q states minmum cost
I am going to pick the 1st stair + cost of the current stair.
cost = [1,100,2]
cost = [1,100,2,3] <--picked stair 3.
cost = [1,100,2,3,3] <---picked stair 3
cost = [1,100,2,3,3,103,4,5,104,6].
Thus the final answer is dp[n]. Not necessarily!
lets take this example:
cost = [10,15,20]
cost = [10,15,30] but i can reach my destination by skipping the 3 stair thus giving me a minimum cost of 15.
thus you final answer must be min(dp[n],dp[n-1]).
*/
 int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2;i<cost.size();i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};
/*
//Another method without changing the cost array
 int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp = 0, dp1 = 0, dp2 = 0; // corresponding to current dp, previous 1 step dp, previous 2 step dp
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp1 + cost[i - 1];  // Minimum cost if we jump 1 step from floor (i-1)_th to i_th floor
            int jumpTwoStep = dp2 + cost[i - 2];  // Minimum cost if we jump 2 steps from floor (i-2)_th to i_th floor
            dp = min(jumpOneStep, jumpTwoStep);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }*/
