class Solution {
public:
    /*//Brute force
    int maxArea(vector<int>& height) {
        int max_area=INT_MIN;
        int area;
        int h;
        for(int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                h=min(height[i],height[j]);
                area=h*(j-i); 
                if(area>max_area)
                    max_area=area;
            }
        }
            
        return max_area;
    }*/
    /*One thing that is ignored in the explanation is the h[i] == h[j] case.
You need to prove that in this case, it does not matter whether you perform i++ or j--, because if h[i] == h[j], neither (i+1, j) or (i, j-1) can be potential solutions because the area obtained is necessarily smaller than (i, j).

Start by evaluating the widest container, using the first and the last line. All other possible containers are less wide, so to hold more water, they need to be higher. Thus, after evaluating that widest container, skip lines at both ends that don't support a higher height. Then evaluate that new container we arrived at. Repeat until there are no more possible containers left.*/
    int maxArea(vector<int>& height) {
        int max_area=INT_MIN;
        int front=0;int area;
        int rear=height.size()-1;int h;
        while(rear>front)
        {
             h=min(height[front],height[rear]);
             area=h*(rear-front); 
             if(area>max_area)
                 max_area=area;
            while(height[front]<=h && front<rear) front++;
            while(height[rear]<=h && front<rear) rear--;
            
        }
            
        return max_area;
    }
};
