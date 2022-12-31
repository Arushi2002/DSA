class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        a=s[:int(len(s)/2)]
        b=s[len(s)//2:]
        vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        cnt_a=0
        cnt_b=0
        for i in range(0,len(s)//2):
            if a[i] in vowels:
                cnt_a+=1
            if b[i] in vowels:
                cnt_b+=1

        return cnt_a==cnt_b
