/*
https://leetcode.com/problems/search-a-2d-matrix/
Solution 1-> Brute Force
Time Complexity: O(m*n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==target)
                    return true;
            }  
        }
        return false;
    }
};
/*Solution 1-> iteration +BS
Time Complexity: O(m)+O(log(n))=O(m)
Space Complexity: O(1)
A matrix with m rows and n columns is called an m × n matrix
*/
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int mid;
        int low=0;int i=0;
        
        //Find the row to search in
        for(int j=0;j<matrix.size();j++)
        {
            if(target>=matrix[j][0])
                i=j;
        }
        
        int high=matrix[i].size()-1;
        //apply binary search on the row
        while(low<=high)
        {
            mid=(low+high)/2;
            if(matrix[i][mid]==target)
                return true;
            else if(matrix[i][mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};*/
/*Solution 2-> 2 BS
Time Complexity: O(log(m)+O(log(n))=O(log(mn))
Space Complexity: O(1)
A matrix with m rows and n columns is called an m × n matrix
*/
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid;
        int low=0;int high=matrix.size()-1;int i=0;
        //Find the row to search in
        while(low<=high)
        {
             mid=(low+high)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]>target)
                 high=mid-1; 
            else
                low=mid+1;
        }
        if(high>=0)
            i=high;
        else
            return false;
        
        //intinalize low and high for BS in row->i
        low=0;
        high=matrix[i].size()-1;
        //apply binary search on the row
        while(low<=high)
        {
            mid=(low+high)/2;
            if(matrix[i][mid]==target)
                return true;
            else if(matrix[i][mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};*/
/* Solution 3->only 1 BS
Time Complexity: O(log(mn))
Space Complexity: O(1)*/
// Do binary search in this "ordered" matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row_len = matrix.size();
	int col_len = matrix[0].size();
	
	int begin = 0, end = row_len * col_len - 1;
	
	while(begin <= end)
    {
		int mid = (begin + end) / 2;
		int mid_value = matrix[mid/col_len][mid%col_len];
		
		if( mid_value == target)
			return true;
		
		else if(mid_value < target)
			//Should move a bit further, otherwise dead loop.
			begin = mid+1;
		else
			end = mid-1;
		
	}
	
	return false;
    }
};
