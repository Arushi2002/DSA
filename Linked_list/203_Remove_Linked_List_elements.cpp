/**
https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pres=head;
        ListNode* prev=NULL;
        ListNode* curr;
        while(pres)
        {
            if(pres->val==val)
            {
                if(prev==NULL) //First node to be deleted
                    head=pres->next;
                else
                    prev->next=pres->next;
                   
                curr=pres;
                pres=pres->next;
                delete(curr);
            }
            else
            {
              prev=pres;
              pres=pres->next;  
            }  
        }
        return head;
    }
};
/*
		Approach: 2
        Solving the problem using a single pointer: current.
        Time: 20 ms
    */
/*    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
		// This is for the case when a linked list is like this: 
		// 1->1->2->null , val = 1
		// 1->1->1->null , val = 1
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* curr = head;
        while(curr!=nullptr  && curr->next!=nullptr){
            if(curr->next->val==val){
                curr->next = curr->next->next;
				// After doing the above step, I am not updating "curr" because of these type of test cases:
				// 1->2->3->6->6->6->5->null  val = 6
            }
            else
                curr = curr->next;
        }
        return head;
    }
};*/
