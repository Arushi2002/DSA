/**
https://leetcode.com/problems/reverse-linked-list/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/* 
Iterative Solution
Time Complexity: O(n)
Space Complexity: O(1)*/
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};*/
/* 
Recusive Solution
Time Complexity: O(n)
Space Complexity: O(n)*/

class Solution {
public:
    ListNode* helper(ListNode* head, ListNode* prev) {
        if (!head) return prev;
        ListNode* next = head->next;
        head->next = prev;
        return helper(next, head);
      
        
    }
    
    ListNode* reverseList(ListNode* head) {       
        return helper (head, NULL);
        
    }
};
