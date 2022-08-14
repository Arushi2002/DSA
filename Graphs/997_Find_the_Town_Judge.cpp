//Hashmap
//   https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0)
            return 1;
        unordered_map<int,vector<int>> m;int judge;int found;
        for(int i=0;i<trust.size();i++)
        {
            m[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++)
        {
            judge=i;
            found=1;
            for(int j=1;j<=n;j++)
            {
                if(judge==j)
                {
                    if(m.find(j)==m.end())
                    {
                        
                    }
                    else
                    {
                        found=0;break;
                    }
                }
                else if(m.find(j)==m.end())
                {
                    found=0;
                    break;
                }
                else if(m.find(j)!=m.end())
                {
                    if(!count(m[j].begin(),m[j].end(),i))
                    {
                        found=0;
                        break;
                    }       
                }  
            }
            if(found==1)
                return i;
        }
        return -1;
    }
};
/*
intuition:
Consider trust as a graph, all pairs are directed edge.
The point with in-degree - out-degree = N - 1 become the judge.

Explanation:
Count the degree, and check at the end.

Time Complexity:
Time O(T + N), space O(N)*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0)
            return 1;
        vector<int> t(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            t[trust[i][0]]--;
            t[trust[i][1]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==n-1) return i;
        }
        return -1;
    }
};
//Graph concept
//Indegree outdegree
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n+1,0);
        vector<int> in(n+1,0);
        
        for(auto edge : trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
        for(int i=1;i<n+1;i++)
        {
            if(out[i]==0 && in[i]==n-1)
                return i;
        }
        return -1;
    }
};


