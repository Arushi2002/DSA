/**
https://leetcode.com/problems/merge-two-sorted-lists/

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
class Solution {
public:
    *ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* temp;ListNode* pres3;
        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                temp=new ListNode(list1->val);
                if(!head)
                {
                    head=temp;
                    pres3=head;
                }
                else
                {
                    pres3->next=temp;
                    pres3=pres3->next;
                }
                list1=list1->next;
            }
            else
            {
                temp=new ListNode(list2->val);
                if(!head)
                {
                    head=temp;
                    pres3=head;
                }
                else
                {
                    pres3->next=temp;
                    pres3=pres3->next;
                }
                list2=list2->next;
            }
            
        }
        if(list1)
        {
          while(list1)
          {
               temp=new ListNode(list1->val);
                if(!head)
                {
                    head=temp;
                    pres3=head;
                }
                else
                {
                    pres3->next=temp;
                    pres3=pres3->next;
                }
                list1=list1->next;
          }
        }
        else
        {
            while(list2)
            {
                temp=new ListNode(list2->val);
                if(!head)
                {
                    head=temp;
                    pres3=head;
                }
                else
                {
                    pres3->next=temp;
                    pres3=pres3->next;
                }
                list2=list2->next;
            }
        }
        return head;
    }
};*/
   // RECURSIVE APPROACH

					// 😉😉😉😉Please upvote if it helps 😉😉😉😉
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};
