/*
https://leetcode.com/problems/minimum-index-sum-of-two-lists/solution/
Brute force Solution
Time Complexity: O(m*n)
Space Complexity: O(1)
*/
/*
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        //Brute force
        int min_sum=INT_MAX;
        vector<string> ans;
        for(int i=0;i<list1.size();i++)
        {
            for(int j=0;j<list2.size();j++)
            {
                if(list1[i]==list2[j])
                {
                    if(i+j==min_sum)
                    {
                        ans.push_back(list1[i]);
                    }
                    if(i+j<min_sum)
                    {
                        min_sum=i+j;
                        ans.clear();
                        ans.push_back(list1[i]);
                    }
                }
            }
        }
        return ans;
    }
};*/
/*
Fastest
Hashmap Solution
Time Complexity: O(m+n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        //Brute force
        int min_sum=INT_MAX;int index_sum;
        vector<string> ans;
        //Creating and inserting elements of list1 into hashmap
        unordered_map<string,int> umap;
        for(int i=0;i<list1.size();i++)
            umap[list1[i]]=i;
        for(int j=0;j<list2.size();j++)
        {
            if(umap.find(list2[j])!=umap.end())
            {
                index_sum=j+umap[list2[j]];
                if(index_sum==min_sum)
                    ans.push_back(list2[j]);
                if(index_sum<min_sum)
                {
                        min_sum=index_sum;
                        ans.clear();
                        ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};
/*
/*
Another discussions method
Time Complexity: O(m+n)
Space Complexity: O(n)
/*
class Solution {
public:
     vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>um;
        for(int i=0;i<list1.size();i++) um[list1[i]]=i;
        map<int,vector<string>>m;
        for(int i=0;i<list2.size();i++){
            if(um.count(list2[i]))  m[i+um[list2[i]]].emplace_back(list2[i]);
        }
        return m.begin()->second;
    }
};
*/
