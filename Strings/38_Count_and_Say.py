# #TC: O((n-1)*length of countAndSay)
# #SC: O(1)
# https://leetcode.com/problems/count-and-say/
#My sol
# class Solution:
#     def countAndSay(self, n: int) -> str:
#         if(n==1):
#             return "1"
#         i=0
#         ans="1"
       
#         while(i<n-1):
#             cnt=0
#             countAndSay=ans
#             ans=""
#             c=countAndSay[0]
#             for j in range(len(countAndSay)):
                
#                 if(countAndSay[j]==c):
#                     cnt+=1
#                 else:
#                     ans=ans+str(cnt)+c
#                     c=countAndSay[j]
#                     cnt=1
#             #adding the last element
#             ans=ans+str(cnt)+c
#             #print(ans)
#             i+=1
#         return ans
          
    
#Use join for better TC
#Coz concatination takes O(m+n)
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for i in range(n-1):
            count = 1
            temp = []
            for index in range(1, len(s)):
                if s[index] == s[index-1]:
                    count += 1
                else:
                    temp.append(str(count))
                    temp.append(s[index-1])
                    count = 1
            temp.append(str(count))
            temp.append(s[-1])
            s = ''.join(temp)
        return s 
    
    
## RE method
def countAndSay(self, n):
    s = '1'
    for _ in range(n - 1):
        s = ''.join(str(len(group)) + digit
                    for group, digit in re.findall(r'((.)\2*)', s))
    return s
