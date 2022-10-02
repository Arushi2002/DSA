# https://leetcode.com/problems/minimize-xor/
class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        n1=bin(num1)[2:]
        n2=bin(num2)[2:]
        setbits=n2.count('1')
        n1c=n1.count('1')
        if(setbits==n1c):
            temp=n1
        elif(n1c>setbits):
            i=0
            temp=""
            while(setbits>0):
                if(n1[i]=='1'): setbits-=1
                temp+=n1[i]
                i+=1
            temp+=len(n1[i:])*'0'
        else:
            temp=n1
            setbits-=n1c
            i=len(temp)-1
            while(setbits>0 and i>-1):
                if(temp[i]=='1'):
                    i-=1
                else:
                    temp=temp[:i]+'1'+temp[i+1:]
                    setbits-=1
                    i-=1
            if(setbits):
                temp=setbits*'1'+temp
        #convert temp to dec
        temp=temp[::-1]
        num=0
        for i in range(len(temp)):
            if(temp[i]=='1'):
                num+=2**i
        return num
