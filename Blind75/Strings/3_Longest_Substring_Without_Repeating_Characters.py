#  https://leetcode.com/problems/longest-substring-without-repeating-characters/

# #Brute force
# #find all substrings 
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         if(s==""): return 0
#         temp=""
#         lenn=1
#         for i in range(len(s)):
#             d=defaultdict(lambda:0)
#             temp=s[i]
#             d[s[i]]+=1
#             for j in range(i+1,len((s))):
#                 temp+=s[j]
#                 d[s[j]]+=1
#                 if(d[s[j]]>1):
#                     nl=len(temp)-1
#                     if(nl>lenn):
#                         lenn=nl
#                     break
                
#                 if(d[s[len(s)-1]]==1):
#                     if(len(temp)>lenn):
#                         lenn=len(temp)
#                 #print(d,temp)
#         return lenn
                
#Neetcode
#python set is ordered 
#s[0],s[1] like list
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet=set()
        l=0
        res=0
        for r in range(len(s)):
            while s[r] in charSet:
                    charSet.remove(s[l])
                    l+=1
            charSet.add(s[r]) 
            res=max(res,r-l+1)
        return res
    
            
