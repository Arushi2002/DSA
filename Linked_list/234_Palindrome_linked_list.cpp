/**
https://leetcode.com/problems/palindrome-linked-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
    bool isPalindrome(ListNode* head) {
        //Brute force //Time:O(2n) Space:O(n/2)
        //Find length of linked list
        int len=0;int half_len;
        ListNode* pres;
        pres=head;
        //Finding length of list
        while(pres)
        {
            len++;
            pres=pres->next;
        }
        
        pres=head;
        //If only one element then palindrome
        if(len==1) return true;
        
        //else
        half_len=len/2;
        
        //store first half of list in vector
        vector<int> stk;
        while(half_len--)
        {
            stk.push_back(pres->val);
            pres=pres->next;
        }
        half_len=len/2;
        //if odd skip the middle element
        if(len%2)
            pres=pres->next;
        
        //compare first half with second half
        while(half_len--)
        {
            if(stk[half_len]!=pres->val)
                return false;
            pres=pres->next;      
        }
        return true;
    }*/
    //O(n) O(1)
    static ListNode* reverse(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        ListNode* pres=head;
        ListNode* prev=NULL;
        ListNode* temp;
        while(pres)
        {
            temp=pres->next;
            pres->next=prev;
            prev=pres;
            pres=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head){
        //if empty return true
        if(!head) return true;
        
        ListNode* slow=head;
        ListNode* fast=head;
        //Find the middle element
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverse(slow->next);
        
        slow=slow->next;
        fast=head;
        while(slow)
        {
            if(fast->val!=slow->val)
                return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
        
    }
    /*
    Functions used below are HEART n SOUL of linkedlist questions. Usually, any LinkedList question can be broken down to these functions:-

Reverse ===> Used for space optimization
Find Mid ===> Slow-Fast Pointer
Iteration : normal iter, recursive iter, adjacent node 2-vars, slow-fast
Insert : start , mid, last
delete : start, mid, last
THIS QUESTION:
find Mid of linkedlist --------> do see cases of even/odd length on paper
reverse second half from mid pointer ----> see how prev gets changed
Now compare first and second half Easy huh! 😜
EdgeCase:
linkedlist size =0,1
*/
};
