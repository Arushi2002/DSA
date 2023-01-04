class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        count=collections.Counter(tasks)
        rounds=0
        for val in count.values():
            if val==1:
                return -1
            elif val==2:
                rounds+=1
            elif val%3==0:
                rounds+=val//3
            else:
                rounds+=val//3+1
        return rounds
           
            
