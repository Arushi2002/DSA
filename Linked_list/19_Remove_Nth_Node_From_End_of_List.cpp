/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//My sol
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pres=head;
        int len=0;
        while(pres)
        {
            pres=pres->next;
            len++;
        }
        
        // if(len==1)
        // {
        //     return NULL;
        // }
        
        len-=n;
        pres=head;
        ListNode* prev=NULL;
        while(len)
        {
            prev=pres;
            pres=pres->next;
            len--;
        }
        //printf("%d",pres->val);
        if(prev==NULL)
        {
            return pres->next;
        }
        prev->next=pres->next;
        delete pres;
        return head;
    }
    
};

//One pass 2 pointer soln
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast= head;
        while(n--) fast=fast->next;
        if(fast==NULL)
            return head->next;
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
    
};
