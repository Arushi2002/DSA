/*
https://leetcode.com/problems/happy-number/
HashSet Solution
Time Complexity: O(logn)
Space Complexity: O(logn)
*/
class Solution {
public:
    static int helper_happy(int n){
        int ab=0;
        while(n)
        {
            ab+=(n%10)*(n%10);
            n/=10;
        }
        return ab;
    }
    bool isHappy(int n) {
        //initialize has_set to keep track of all the visited numbers
        unordered_set<int> visit;
        int new_num=n;
        while(new_num!=1 && visit.find(new_num)==visit.end())
        {
            visit.insert(new_num);
           new_num= helper_happy(new_num);  
        }
        if(new_num==1) return true;
        return false;
    }
};
/*
Floyd's Cycle detection algorithm
Solution based on Linked List Cycle Concept
Time Complexity: O(logn)
Space Complexity: O(1)
*/
class Solution {
public:
    static int getNext(int n){
        int ab=0;
        while(n)
        {
            ab+=(n%10)*(n%10);
            n/=10;
        }
        return ab;
    }
    bool isHappy(int n) {
        //fast is 2 steps ahead of slow
        int slowRunner=n;
        int fastRunner=getNext(n);
        while(fastRunner!=1 && slowRunner!=fastRunner)
        {
            slowRunner=getNext(slowRunner);
            fastRunner=getNext(getNext(fastRunner));
        }
        return fastRunner == 1;
    }
};
    
