
//My solution
https://leetcode.com/problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string abc="";
         char a;
         while(columnNumber)
         {
             if(columnNumber%26==0)
             {
                 a=64+26;
                 columnNumber=columnNumber/26-1;
             }
  
             else
             {
                 a=columnNumber%26+64;
                 columnNumber/=26;
             }
             //concatination of strings
             abc=a+abc; 
         }
        return abc;
    }
};
//one line solution
class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');
    }
};
//Cleaner solution
class Solution {
public:
    string convertToTitle(int n) {

        string res;

        char tmp;

        while(n){

            n -= 1;

            tmp = 'A' + n % 26;

            res = tmp + res;

            n /= 26;

        }

        return res;

    }
};
