//              https://www.codingninjas.com/codestudio/problems/ceiling-in-a-sorted-array_1825401?leftPanelTab=1

int ceilingInSortedArray(int n, int x, vector<int> &nums){
    //if x is less than all nums
    if(x<nums[0])
        return nums[0];
    //if x is greater than all nums
    else if(x>nums[nums.size()-1])
        return -1;

   for(int i=0;i<nums.size();i++)
   {
       if(nums[i]==x)
           return x;
       if(nums[i]>x)
           return nums[i];//ceil
   }
   return -1;
 
}
