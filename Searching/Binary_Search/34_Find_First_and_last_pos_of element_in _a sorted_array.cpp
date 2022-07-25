https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
/*My Solution*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> result(2,-1);
        int mid;int flag=0;int pos=-1;
        int low=0;int high=nums.size()-1;
        while(low<=high && !flag)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
                flag=1;
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
            
        }
        if(!flag)
            return result;
        while(mid-1>=0 && nums[mid-1]==target)
            mid--;
        result[0]=mid;
        while(mid+1<nums.size() && nums[mid+1]==target)
            mid++;
        result[1]=mid;
        return result;
        
    }
};
/*
//Solution2--> 2 binary searches
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> result(2,-1);
        int i=0,j=nums.size()-1;int mid;
        if(nums.size()==0) return result;
        //to find the lower index
        while(i<j)
        {
            mid=(i+j)/2;
            if(nums[mid]<target)
                i=mid+1;
            else
                j=mid;
        }
        if(nums[i]!=target) return result;
        result[0]=i;
        
        //Let i remain mid for faster finding of upper range
        j=nums.size()-1;
        while(i<j)
        {
            mid=(i+j)/2+1;// Make mid biased to the right
            if(nums[mid]>target)
                j=mid-1;
            else
                i=mid;
        }
        result[1]=j;
        return result;
        
    }
};*/
/*Solution 3 : Divide and Conquer with early breaks : 56 ms
//python
The O(log n) time isn't quite obvious, so I'll explain it below. Or you can take the challenge and prove it yourself :-)*/
/*
class Solution(object):
    def searchRange(self, nums, target):
        #for empty list
        if(len(nums)==0):
            return [-1,-1]
        def search(lo, hi):
            if nums[lo] == target == nums[hi]:
                return [lo, hi]
            if nums[lo] <= target <= nums[hi]:
                mid = (lo + hi) / 2
                l, r = search(lo, mid), search(mid+1, hi)
                return max(l, r) if -1 in l+r else [l[0], r[1]]
            return [-1, -1]
        return search(0, len(nums)-1)

*/
