class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        int rounds=0;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        map<int,int>::iterator it=m.begin();
        while(it!=m.end())
        {
            if(it->second==1)
                return -1;
            else if(it->second==2)
                rounds+= 1;
            else if((it->second)%3==0)
                rounds+=(it->second)/3;
            else
                rounds+=(it->second)/3+1;
            ++it;
        }
        return rounds;
    }
};

//Leetcode
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        // Store the frequencies in the map.
        for (int task : tasks) {
            freq[task]++;
        }
        
        int minimumRounds = 0;
        // Iterate over the task's frequencies.
        for (auto [task, count] : freq) {
            // If the frequency is 1, it's not possible to complete tasks.
            if (count == 1) {
                return - 1;
            }

            if (count % 3 == 0) {
                // Group all the task in triplets.
                minimumRounds += count / 3;
            } else {
                // If count % 3 = 1; (count / 3 - 1) groups of triplets and 2 pairs.
                // If count % 3 = 2; (count / 3) groups of triplets and 1 pair.
                minimumRounds += count / 3 + 1;
            }
        }
        
        return minimumRounds;
    }
};
