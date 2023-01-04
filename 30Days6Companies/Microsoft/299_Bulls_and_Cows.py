#TC: O(n^2)
#My sol
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        x=0
        y=0
        temp=list(secret)
        cows_index=[i for i in range(len(guess))]
        cows=[]
        for i in range(len(guess)):
            if(secret[i]==guess[i]):
                x+=1
                cows_index.remove(i)
                temp.remove(guess[i])
      
        for c in cows_index:
            if guess[c] in temp:
                y+=1
                temp.remove(guess[c])
        

        return"{0}A{1}B".format(x,y)

#O(n) solution
class Solution:
    def getHint(self, secret: str, guess: str) -> str:       
        bull, cow = 0, 0
        s = {} # secret hashtable
        g = {} # guess hashtable
        
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bull += 1
            else:
                s[secret[i]] = s.get(secret[i], 0) + 1
                g[guess[i]] = g.get(guess[i], 0) + 1
        
        for k in s:
            if k in g:
                cow += min(s[k], g[k])
        
        return '{0}A{1}B'.format(bull, cow)
            
