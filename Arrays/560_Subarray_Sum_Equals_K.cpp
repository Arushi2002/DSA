/*https://leetcode.com/problems/subarray-sum-equals-k/
Brute force
Time Complexity: O(n^2)
Space Complexity: O(1)*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum==k) ans++;
            }
            
        }
        return ans;
    }
};
/*
Most optimized Solution
https://leetcode.com/problems/subarray-sum-equals-k/discuss/1759909/C%2B%2Bor-Full-explained-every-step-w-Dry-run-or-O(n2)-greater-O(n)-or-Two-approaches
Time Complexity: O(n)
Space Complexity: O(n)*/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // take the size of the array
        
        int prefix[n]; // make a prefix array to store prefix sum
        
        prefix[0] = arr[0]; // for element at index at zero, it is same
        
        // making our prefix array
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; // declare an unordered map
        
        int ans = 0; // to store the number of our subarrays having sum as 'k'
        
        for(int i = 0; i < n; i++) // traverse from the prefix array
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }
            
            mp[prefix[i]]++; // put prefix sum into our map
        }
        
        return ans; // and at last, return our answer
    }
};
