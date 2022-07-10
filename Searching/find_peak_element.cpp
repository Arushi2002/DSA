class Solution {
public:
    /*//O(n) O(1)
    int findPeakElement(vector<int>& nums) {
      //Brute force 
     int i=0;
        while(i<nums.size()-1)
        {
            if(nums[i+1]>nums[i])
                i++;
            else 
                return i;
        }
         return i;
              
    }*/
    /*
    static int BinSearch(vector<int>& nums,int low,int high)
    {
        if(low>high)
            return -1;
        else if(low==high)
            return low;
        else
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid+1])
                return BinSearch(nums,low,mid);
            
            return BinSearch(nums,mid+1,high);
        }
        
    }
    //rECURSIVE BINARY SEARCH
    int findPeakElement(vector<int>& nums) {
        return BinSearch(nums,0,nums.size()-1);
    }*/
    //Iterative
    int findPeakElement(vector<int>& nums){
        int mid;int low=0;int high=nums.size()-1;
        while(low<high)
        {
            
            mid=(low+high)/2;
            if(nums[mid]>nums[mid+1])
            {
                high=mid;
            }
            else if(nums[mid]<nums[mid+1])
            {
                low=mid+1;
            }
                
        }
        return low;
    }
};
