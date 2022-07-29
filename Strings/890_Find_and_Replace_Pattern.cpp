/*
https://leetcode.com/problems/find-and-replace-pattern/solution/

n->no of words
k->length of each word
Time Complexity: O(n*k)
Space Complexity: O(n*k)
*/
class Solution {
public:
    string getPattern(string pattern){
        string ans;
        unordered_map<char,char> mp;
        int j=0;
        for(int i=0;i<pattern.size();i++)
        {
            if(mp.find(pattern[i])==mp.end())
            {
                mp[pattern[i]]='a'+j;
                j++;
            }
                  
            ans.push_back(mp[pattern[i]]);
                
        }
        return ans;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
          string pat=getPattern(pattern);
          string p;
          for(int i=0;i<words.size();i++)
          {
              p=getPattern(words[i]);
              if(p==pat)
              {
                  ans.push_back(words[i]);
              }
          }             
          return ans;                   
    }
};
