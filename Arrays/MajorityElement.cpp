/*https://leetcode.com/problems/majority-element/*/
class Solution {
public:
   /*int majorityElement(const vector<int> &A) {
    int n=A.size();
    int n_half=n/2;int count,count_max=0,count_max_index;
    
    for(int i=0;i<n;i++)
    {
        count=0;
        for(int j=0;j<n;j++)
        {
            if(A[i]==A[j])
                count++;
        }
        if(count>count_max)
        {
            count_max=count;
            count_max_index=i;
        }
    }
    
    
    return A[count_max_index];
}*/
    int majorityElement(const vector<int> &A)
    {
        int count=1;int current_ele=A[0];
        int n=A.size();
        for(int i=1;i<n;i++)
        {
            if(A[i]==current_ele)
            {
                count++;
                if(count>(n/2))
                    return current_ele;
            }
                
            else
            {
                count--;
                if(count==0)
                {
                    current_ele=A[i];
                    count=1;
                }
            }
            //printf("%d\n",current_ele);
            //printf("%d\n",count);
        }
    
        return current_ele;
        
    }
};
