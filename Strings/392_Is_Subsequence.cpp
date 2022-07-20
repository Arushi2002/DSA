/*
https://leetcode.com/problems/is-subsequence/
Brute Force Solution
Time Complexity: O(t.size())
Space Complexity: O(1)
*/
/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<t.size() && j<s.size())
        {
            if(t[i]==s[j])
            {
                j++;
            }
            i++;
        }
        if(j==s.size()) return true;
        return false;
    }
};*/
/*
Recursive method Solution
Time Complexity: O(t.size())
Space Complexity: O(1)
*/
/*
class Solution {
public:
    //m is for s
    //n is for t
    bool isSub(string s, string t, int m, int n){
        if(m==0)
            return true;
        if(n==0)
            return false;
        if(s[m-1]==t[n-1])
            return isSub(s,t,m-1, n-1);
        return isSub(s,t,m, n-1);  
    }
    bool isSubsequence(string s, string t) {
        
        return isSub(s,t,s.size(),t.size());
    }
};
/*
DP Solution
Time Complexity: O(t.size())
Space Complexity: O(1)
*/

class Solution {
public:
    
    // returns the length of longest common subsequence
    int isSubs(string& s1, string& s2, int i , int j,vector<vector<int>> &t)
    {
        if(i == 0 || j == 0)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        if(s1[i-1] == s2[j-1])
            return t[i][j] = 1 + isSubs(s1,s2,i-1,j-1,t);
        else
            return t[i][j] = isSubs(s1,s2,i,j-1,t);
    }
    
    
    bool isSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // intialising dp matrix with -1
        
        if(m >  n)
            return false;
        
        vector<vector<int>> t(m+1,vector<int> (n+1,-1));
    
        if(isSubs(s1,s2,m,n,t) == m)
            return true;
        return false;
    }
};
/*
Hashmap Solution
Time Complexity: O(t.size())
Space Complexity: O(1)
*/
/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,vector<int>> m;
        if(s=="")return true;
        for(int i=0;i<t.size();i++)
        {
            m[t[i]].push_back(i);
        }
        int latest=-1;
        for(int j=0;j<s.size();j++)
        {
            auto it=upper_bound(m[s[j]].begin(),m[s[j]].end(),latest);
            if(it==m[s[j]].end())
                return false;
            latest=*it;
            if(j==s.size()-1)
                return true;
        }  
        return false;
    }
};*/
