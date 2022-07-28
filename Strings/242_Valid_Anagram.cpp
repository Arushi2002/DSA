/*https://leetcode.com/problems/valid-anagram/submissions/
/*
Time Complexity: O(nlogn)+ O(n)=O(nlogn)
Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        /*for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i]) return false;
        }
        return true;
        return s==t;
    }
};*/
/*
TIme COmplexity:O(n)
Space Complexity:O(n)
*/
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};*/
/*
Since the problem statement says that "the string contains only lowercase alphabets", we can simply use an array to simulate the unordered_map and speed up the code. The following implementation takes 12 ms.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};
