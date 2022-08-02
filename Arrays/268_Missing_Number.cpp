/*
https://leetcode.com/problems/missing-number/submissions/
Brute force
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n+1;i++)
        {
            if(count(nums.begin(),nums.end(),i)==0)
                return i;
        }
        return -1;
    }
};
/*
Sorting 
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i!=nums[i])
                return i;
        }
        return n;
    }
};
//1.XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i=0; i<nums.size(); i++){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};*/

//2.SUM
/*
O(n)
O(1)*/
class Solution {
public:
    int missingNumber(vector<int>& nums) { //sum
        int len = nums.size();
        //sum of all numbers in range len
        int sum = (0+len)*(len+1)/2;
        for(int i=0; i<len; i++)
            sum-=nums[i];
        return sum;
    }
};

/*
//3.Binary Search
TC: O(nlogn)
SC: O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //binary search
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.length, mid= (left + right)/2;
        while(left<right){
            mid = (left + right)/2;
            if(nums[mid]>mid) right = mid;
            else left = mid+1;
        }
        return left;
};
