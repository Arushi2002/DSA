/*
https://leetcode.com/problems/set-matrix-zeroes/
  Brute force Soltuion
  Time Complexity: O(mn)
  Space Complexity: O(m+n)
*/
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> i_val;
        unordered_set<int> j_val;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    i_val.insert(i);
                    j_val.insert(j);
                }   
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i_val.find(i)!=i_val.end() || j_val.find(j)!=j_val.end())
                    matrix[i][j]=0;
            }
        }
    }
};*/

/*
  Using the first row and col as row_set and col_set Soltuion
  Time Complexity: O(mn)
  Space Complexity: O(1)
*/
void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}

