/**
https://leetcode.com/problems/intersection-of-two-linked-lists/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Brute Force Solution
Time Complexity: O(m*n)
Space Complexity: O(1)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pres1=headA;
        ListNode* pres2=headB;
        //Brute force
        while(pres1)
        {
            pres2=headB;
            while(pres2)
            {
                if(pres1==pres2)
                    return pres1;
                pres2=pres2->next;
            }
            pres1=pres1->next;
            
        }
        return NULL;
    }
};
/*
2. HashMap Solution
Time Complexity : O(m + n)
Space Complexity : O(m)
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*, int> m;
		while(headA != NULL){
			m[headA]++;
			headA = headA -> next;
		}
		while(headB != NULL){
			if(m[headB] > 0){
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;
	}
};
/*
3. Length Difference Solution
Time Complexity : O(m + n)
Space Complexity : O(1)
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int n = 0;
		int m = 0;
		ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;
		while(ptr1 != NULL){
			n++;
			ptr1 = ptr1 -> next;
		}
		while(ptr2 != NULL){
			m++;
			ptr2 = ptr2 -> next;
		}
		int t = abs(n - m);
		if(n > m){
			while(t){
				headA = headA -> next;
				t--;
			}
		}
		else{
			while(t){
				headB = headB -> next;
				t--;
			}
		}
		while(headA != NULL and headB != NULL){
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
		}
		return NULL;
	}
};
/*
4. Two-Pointers Solution
Time Complexity : O(m + n)
Space Complexity : O(1)
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
		while(ptr1 != ptr2){
			if(ptr1 == NULL){
				ptr1 = headB;
			}
			else{
				ptr1 = ptr1 -> next;
			}
			if(ptr2 == NULL){
				ptr2 = headA;
			}
			else{
				ptr2 = ptr2 -> next;
			}
		}
		return ptr1;
	}
};
/*
Here is a tricky, non-algorithmic, unique 5th solution that marks the nodes by negating it while first iteration using headA, then when we iterate using headB, the first node with a negative value is the intersecting node.
*/
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *answer=nullptr,*iter = headA;
        
        while(iter!=nullptr)
        {
            iter->val *= -1;
            iter = iter->next;
        }
        
        iter = headB;
        
        while(iter!=nullptr)
        {
            if(iter->val <0)
            {
                answer = iter;
                break;
            }
            iter = iter->next;
        }
        
        iter = headA;
        
        while(iter!=nullptr)
        {
            iter->val *= -1;
            iter = iter->next;
        }
        
        return answer;
    }
};
