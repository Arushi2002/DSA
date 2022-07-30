/*Brute force
    TC: O(n^2)
    SC: O(1)
*/
/*
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(abs(nums[i]-nums[j])==k)
                ans++;
        }
    }
    return ans;
    }
};
*/
/*Using Map
    TC: O(n)
    SC: O(n)
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]+k]) count+=map[nums[i]+k]; 
            if(map[nums[i]-k]) count+=map[nums[i]-k]; 
            map[nums[i]]++;
        }
        return count;
    }
};
/*Counting Sort
    TC: O(n)
    SC: O(100)
*/
/*
int countKDifference(vector<int>& nums, int k) {
    int cnt[101] = {}, res = 0;
    for (auto n : nums)
        ++cnt[n];
    for (int i = k + 1; i < 101; ++i)
        res += cnt[i] * cnt[i - k];
    return res;
}*/
