/*
https://leetcode.com/problems/reverse-integer/
If there are n digits
Time Complexity: O(n)
Space Complexity: O(1)
*/
/*
class Solution {
public:
    int reverse(int x) {
        
        long int rev_num=0;
        while(x)
        {
            rev_num=rev_num*10+x%10;
            if(rev_num<INT_MIN || rev_num>INT_MAX)
                return 0;
        
           x=x/10;
        }
        return (int)rev_num;
    }
};*/
//Real solution when long is not excepted
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
