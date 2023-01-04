class Solution {
public:
    bool is_oper(string p){
        if(p=="+"||p=="-"||p=="*"||p=="/")
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        char ch;
        int i=0;
        int result,op1,op2;
        for (int i = 0; i < tokens.size(); i++)
        {
            string ch=tokens[i];
            if(is_oper(ch))
            {
                op1=stk.top();
                stk.pop();
                op2=stk.top();
                stk.pop();
                
                if (ch=="+")
                {
                    result=op1+op2;
                    stk.push(result);
                }
                
                else if(ch=="-")
                {
                    result=op2-op1;
                    stk.push(result);
                }
                else if(ch=="*")
                {
                    result=op1*op2;
                    stk.push(result);
                }
                else if(ch=="/")
                {
                    result=op2/op1;
                    stk.push(result);
                }
            }
            else
            {
                stk.push(stoi(ch));
            }
        }
           result=stk.top();
            return result; 
        }
        
    
};
