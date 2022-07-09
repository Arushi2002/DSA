//https://leetcode.com/problems/single-number/
class Solution {
public:
    //Brute force  //n2
    /*int singleNumber(vector<int>& nums) {
          for(int i=0;i<nums.size();i++)
          {
              for(int j=0;j<nums.size();j++)
              {
                if(nums[i]==nums[j])
                    dup=1;
              }
              if(!dup)
                  return nums[i];
          }
        
    }
    //Sorting //nlogn
    int singleNumber(vector<int>& nums) {
          sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size()-1;i+=2)
          {
              if(nums[i]!=nums[i+1])
                  return nums[i];
          }
        return nums[0];
    }
    //hashmap
    int singleNumber(vector<int>& nums) {
          
    }*/
    //const space
    int singleNumber(vector<int>& nums) {
         int ans=0;
         for(auto x:nums)
         {
             ans^=x;
         }
        return ans;
        
    }
};
