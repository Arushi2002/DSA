#My sol
#TC:O(n) 
#SC: O(1)
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        li = list(s)
        d1={}
        for idx,ele in enumerate(li):
            if ele in d1:
                d1[ele].append(idx)
            else:
                d1[ele]=[]
                d1[ele].append(idx)

        li2=list(t)
        d2={}
        for idx,ele in enumerate(li2):
            if ele in d2:
                d2[ele].append(idx)
            else:
                d2[ele]=[]
                d2[ele].append(idx)
        # print(d1.values())
        # print(d2.values())
        return list(d1.values())==list(d2.values())

#Leetcode sol
#TC:O(n) 
#SC: O(1)
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        
        mapping_s_t = {}
        mapping_t_s = {}
        
        for c1, c2 in zip(s, t):
            
            # Case 1: No mapping exists in either of the dictionaries
            if (c1 not in mapping_s_t) and (c2 not in mapping_t_s):
                mapping_s_t[c1] = c2
                mapping_t_s[c2] = c1
            
            # Case 2: Ether mapping doesn't exist in one of the dictionaries or Mapping exists and
            # it doesn't match in either of the dictionaries or both            
            elif mapping_s_t.get(c1) != c2 or mapping_t_s.get(c2) != c1:
                return False
            
        return True

#First occurence transformtion
#TC:O(n) 
#SC: O(n)
class Solution:
    def transformed(self,s: str) -> str:
        new_str=[]
        m={}
        for idx,letter in enumerate(s):
            if letter not in m:
                m[letter]=idx
            new_str.append(str(m[letter]))
        
        final=" ".join(new_str)
        return final

    def isIsomorphic(self, s: str, t: str) -> bool:
        return self.transformed(s)==self.transformed(t)

