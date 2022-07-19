/* https://leetcode.com/problems/climbing-stairs/ */
class Solution {
public:
    //DP Bottom Up
    int climbStairs(int n) {
        int arr[n+1];
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 3;
        arr[0]=0;
        arr[1]=1;
        arr[2]=2;
        arr[3]=3;
        for(int i=4;i<n+1;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
    //Another method is recursion +memoization
    //Top_down
    int t[46];
    int climbStairs(int n) {
        if(n==1) {t[n]=1; return 1;}
        if(n==2) {t[n]=2; return 2;}
        else if(t[n]!=0) return t[n];
        t[n] = climbStairs(n-1)+climbStairs(n-2);
        return t[n];
    }
    //Normal doesnt work as it has O(n2) complexity
    /*
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        return climbStairs(n-1)+climbStairs(n-2);
    }*/
};
