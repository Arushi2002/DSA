#https://leetcode.com/problems/bag-of-tokens/
#O(n2)
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        score=0
        if(len(tokens)):
            tokens.sort()
            if(power<tokens[0]):
                return 0
            #first iter
            power-=tokens[0]
            score+=1
            tokens.remove(tokens[0])

            while(len(tokens) and power>=tokens[0]):
                power-=tokens[0]
                score+=1
                tokens.remove(tokens[0])


            while(len(tokens)>1):
                    if(score>0):
                        power+=tokens[-1]
                        score-=1
                        tokens.remove(tokens[-1])
                    while(len(tokens) and power>=tokens[0]):
                        power-=tokens[0]
                        score+=1
                        tokens.remove(tokens[0])
                    
        
        return score
    
#Leetcode sol
class Solution(object):
    def bagOfTokensScore(self, tokens, P):
        tokens.sort()
        deque = collections.deque(tokens)
        ans = bns = 0
        while deque and (P >= deque[0] or bns):
            while deque and P >= deque[0]:
                P -= deque.popleft()
                bns += 1
            ans = max(ans, bns)

            if deque and bns:
                P += deque.pop()
                bns -= 1

        return ans
            
