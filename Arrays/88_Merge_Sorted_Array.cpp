// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;vector<int> temp;
        for(int p=0;p<m;p++)
        {
            temp.push_back(nums1[p]);
        }
        nums1.clear();
        while(i<m && j<n)
        {
            if(temp[i]<=nums2[j])
            {
                nums1.push_back(temp[i++]);
            }
            else
            {
                nums1.push_back(nums2[j++]);
            }
        }
        //push remaining nums2 to nums1
        if(i==m)
        {
            while(j<n)
            {
                nums1.push_back(nums2[j++]);
            }
        }
        else
        {
            while(i<m)
            {
                nums1.push_back(temp[i++]);
            }
        }
    }
};


/*
python
class Solution:
    def merge(self, nums1, m, nums2, n):
        while m > 0 and n > 0:
            if nums1[m-1] >= nums2[n-1]:
                nums1[m+n-1] = nums1[m-1]
                m -= 1
            else:
                nums1[m+n-1] = nums2[n-1]
                n -= 1
        if n > 0:
            nums1[:n] = nums2[:n]
 */
