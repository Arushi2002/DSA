/*
https://leetcode.com/problems/two-sum/
M1
Brute Force Solution
TC: O(n^2)
SC: O(1)
*/
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                
                if((nums[i]+nums[j])==target)
                {
                    result[0]=i;
                    result[1]=j;
                    return result;
                }
            }
        }
        return result;
    }*/
/*
M2
Hash map Solution
TC: O(n)
SC: O(n)
*/
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            //Key is the number and value is its index in the vector.
            if(mpp.find(target-nums[i])!=mpp.end())
            {
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            //number was not found. Put it in the map.
            mpp[nums[i]]=i;
        }
        return ans;
    }
};
/*
M3
Sorting Solution
TC: O(nlogn)
SC: O(n)
*/
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = make_pair(nums[i], i);
        }
        sort(arr.begin(), arr.end()); // Sort arr in increasing order by their values.
        int left = 0, right = n- 1;
        while (left < right) {
            int sum2 = arr[left].first + arr[right].first;
            if (sum2 == target) 
                return {arr[left].second, arr[right].second};
            if (sum2 > target)
                right -= 1; // Try to decrease sum2
            else
                left += 1; // Try to increase sum2
        }
        return {};
    }
};*/
