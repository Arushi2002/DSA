/*
more nice solutons
https://leetcode.com/problems/power-of-two/
https://leetcode.com/problems/power-of-two/discuss/63966/4-different-ways-to-solve-Iterative-Recursive-Bit-operation-Math
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n%2 || n==0) return false;
        while(n%2==0)
        {
            n=n/2;
        }
        if(n==1) return true;
        return false;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && not (n & n - 1);
    }
};
