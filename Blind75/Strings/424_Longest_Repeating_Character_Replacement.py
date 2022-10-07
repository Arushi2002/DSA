# https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        #li=list(range(65,91))
        # print(li)
        # print(ord("Z"))
        #print(ord("A"))
        res=0
        mkey=0
        maxx=0
        l=r=0
        
        cnt=collections.defaultdict(lambda:0)
        while(r<len(s)):
            cnt[s[r]]+=1
            #keys=[key for key,value in cnt.items() if(value==max(cnt.values()))]
            charstoreplace= r-l+1-max(cnt.values())
            while(charstoreplace>k):
                cnt[s[l]]-=1
                l+=1
                #keys=[key for key,value in cnt.items() if(value==max(cnt.values()))]
                charstoreplace= r-l+1-max(cnt.values())
            res=max(res,r-l+1)
            r+=1
                
        return res
