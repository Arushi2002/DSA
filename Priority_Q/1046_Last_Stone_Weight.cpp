/*
https://leetcode.com/problems/last-stone-weight/
Brute Force Solution
TC: O((n^2)logn)
SC: O(1)*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int s1, s2;
        while(stones.size()!=1)
        {
            sort(stones.begin(),stones.end());
            s1=stones[stones.size()-1];
            s2=stones[stones.size()-2];
            if(s1==s2 && stones.size()==2)
            {
                stones.pop_back();
                stones.pop_back();
                stones.push_back(0);
            }
            else if(s1==s2)
            {
                stones.pop_back();
                stones.pop_back();
            }
            if(s1!=s2)
            {
                stones.pop_back();
                stones.pop_back();
                stones.push_back(s1-s2);
            }
        }
        return stones[0];
    }
};

/*Priority Queue
TC: O(nlogn)
SC: O(n)*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y) pq.push(x-y);
        }
        return pq.empty()?0:pq.top();
    }
};
