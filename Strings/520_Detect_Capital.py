#https://leetcode.com/problems/detect-capital/
#My sol
#TC:O(n)
#SC:O(1)
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        all_letters_caps=1
        all_letters_small=1
        first_letter_cap=0
        for i in range(len(word)):
            if(i==0):
                if 65<=ord(word[i])<=90:
                    first_letter_cap=1
                    all_letters_small=0
                else:
                    all_letters_caps=0
            else:
                if 65<=ord(word[i])<=90:
                    all_letters_small=0
                    first_letter_cap=0
                else:
                    all_letters_caps=0
                    
                
        
        return all_letters_caps or all_letters_small or first_letter_cap

#Leetcode sol
#TC: O(n)
#SC: O(1)
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        n = len(word)

        if len(word) == 1:
            return True

        # case 1: All capital
        if word[0].isupper() and word[1].isupper():
            for i in range(2, n):
                if not word[i].isupper():
                    return False
        # case 2 and case 3
        else:
            for i in range(1, n):
                if word[i].isupper():
                    return False

        # if pass one of the cases
        return True

#Regex sol
#TC: O(n)
#SC: O(1)
import re

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return re.fullmatch(r"[A-Z]*|.[a-z]*", word)
