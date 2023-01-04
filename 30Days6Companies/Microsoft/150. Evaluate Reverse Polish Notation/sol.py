class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk=[]
        for token in tokens:
            if(token in "*/+-"):
                op1=stk[-1]
                stk.pop()
                op2=stk[-1]
                stk.pop()
                if(token=="+"):
                    result=op1+op2
                    stk.append(result)
                elif(token=="-"):
                    result=op2-op1
                    stk.append(result)
                elif(token=="*"):
                    result=op2*op1
                    stk.append(result)
                elif(token=="/"):
                    result=int(op2/op1)
                    stk.append(result)
            else:
                stk.append(int(token))

        
        return stk[-1]
