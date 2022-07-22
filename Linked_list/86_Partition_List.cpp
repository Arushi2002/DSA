/**
https://leetcode.com/problems/partition-list/
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
Brute force Solution
Time Complexity: O(n)
Space Complexity: O(n)
(Where n is the size of the linked list)
*/
/*
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* pres=head;
        ListNode* first_half=NULL;
        ListNode* second_half=NULL;
        ListNode* second_half_head=NULL;
        ListNode* root=NULL;
        ListNode* temp;
        while(pres)
        {
            temp=new ListNode(pres->val);
        
            if((pres->val)<x)//insert in end of first half
            {
                if(!first_half)
                {
                    first_half=temp;
                    root=first_half;
                }
                else
                {
                    first_half->next=temp;
                    first_half=first_half->next;
                }      
            }
            
            else  //insert in second half
            {
               if(!second_half)
               {
                   second_half=temp;
                   second_half_head=second_half;
               }
                    
                else
                {
                    second_half->next=temp;
                    second_half=second_half->next;
                } 
            }   
            pres=pres->next;
        }
        //Join first half and second half if they exist
        if(root && second_half_head)
            first_half->next=second_half_head;
        
        //If only second half exists return second_half_head
        if(!root && second_half_head)
            return second_half_head;
        
        return root;
    }
};*/
/*
Two pointer Solution
Time Complexity: O(n)
Space Complexity: O(1)
(Where n is the size of the linked list)
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* first_half_head=new ListNode(0);
        ListNode* first_half=first_half_head;
        ListNode* second_half_head=new ListNode(0);
        ListNode* second_half=second_half_head;
        
        while(head)
        {
            if((head->val)<x)//insert in end of first half
            {
                first_half->next=head;
                first_half=first_half->next;      
            }
            else  //insert in second half
            {
                second_half->next=head;
                second_half=second_half->next;
            }   
            head=head->next;
        }
        // Last node of "second_half" list would also be ending node of the reformed list
        second_half->next=NULL;
        //Join first half and second half if they exist
        first_half->next=second_half_head->next;
        
        return first_half_head->next;
    }
};
