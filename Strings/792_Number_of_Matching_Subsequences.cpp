/*
https://leetcode.com/problems/number-of-matching-subsequences/

Brute Force Solution
Time Complexity: O(s.size()*words.size()*x)
Space Complexity: O(1)*/
/*
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            int j=0; int k=0;
            while(j<words[i].size() && k<s.size())
            {
                if(words[i][j]==s[k])
                    j++;
                k++;
            }
            if(j==words[i].size())
                ans++;
        }
        return ans;
    }
};*/
/*
Hashmap Solution
Time Complexity: O(s.size()+words.size()*x)
Space Complexity: O(s.size()*x)*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<char,vector<int>> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].push_back(i);
        }
        int latest=-1;
        for(int i=0;i<words.size();i++)
        {
            string curr=words[i];
            int latest=-1;
            for(int j=0;j<curr.size();j++)
            {
                auto it=upper_bound(m[curr[j]].begin(),m[curr[j]].end(),latest);
                if(it==m[curr[j]].end())
                    break;
                latest=*it;
                if(j==curr.size()-1)
                    ans++;
            }  
        }
        return ans;
    }
};
