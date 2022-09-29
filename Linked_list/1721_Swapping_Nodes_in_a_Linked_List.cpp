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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* k_start=head;
        ListNode* k_end=head;
        ListNode* fast=head;
        int n=k;
        while(n--) fast=fast->next;
        n=k-1;
        while(fast || n)
        {
            if(n)
            {
                k_start=k_start->next;
                n--;
            }  
            if(fast!=NULL)
            {
                k_end=k_end->next;
                fast=fast->next;
            }
            
        }
       
        int temp;
        temp=k_start->val;
        k_start->val=k_end->val;
        k_end->val=temp;
        return head;
    }
};

//Other sol
// We traverse the list until we reach the kth node.
// Then we set "kth" to that node to remember it, set ptr2 to head and continue traversing the list, while we move both ptr1 and ptr2.
// When ptr1 reaches the end - ptr2 is on the (n-k)th node.
// Now we swap "kth" and "ptr2" and we're done!

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(ptr2->val, kth->val);
        return head;
    }
};
