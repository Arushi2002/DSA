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
class Solution {
public:
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Head pointer for result list
        ListNode* root=NULL;
        //Creating node
        ListNode* temp;
        ListNode* pres3;
        //for traversing through l1 and l2
        ListNode* pres1=l1;
        ListNode* pres2=l2;
        
        pres3=root;
       
        int sum;int carry=0;
        while(pres1 && pres2)
        {
           
            sum=pres1->val+pres2->val+carry;
            if(sum/10)
            {
                carry=sum/10;
                sum=sum%10;
            }
            else
                carry=0;
            temp=new ListNode();
            temp->val=sum;
            temp->next=NULL;
            if(pres3)
            {
                pres3->next=temp;
                pres3=pres3->next;
            }
                
            else
            {
                root=temp;
                pres3=root;
            }
                
            
            //incrementing pres1 and pres2
            pres1=pres1->next;
            pres2=pres2->next;
            
        }
        if(pres1)
        {
            while(pres1)
            {
                sum=pres1->val+carry;
                if(sum/10)
                {
                    carry=sum/10;
                    sum=sum%10;
                }
                else
                    carry=0;
                //Creating and attaching node
               temp=new ListNode(sum);
               pres3->next=temp;
                
                pres1=pres1->next;
                pres3=pres3->next;
            }  
        }
        if(pres2)
        {
            while(pres2)
            {
                sum=pres2->val+carry;
                if(sum/10)
                {
                    carry=sum/10;
                    sum=sum%10;
                }
                else
                    carry=0;
                //Creating and attaching node
               temp=new ListNode(sum);
               pres3->next=temp;
                
                pres2=pres2->next;
                pres3=pres3->next;
            }
                
        }
        if(carry)
        {
            temp=new ListNode(carry);
            pres3->next=temp;
        }
        return root;
    }*/
  //Lil better
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Head pointer for result list
        ListNode* root=NULL;
        //Creating node
        ListNode* temp;
        ListNode* pres3;
        //for traversing through l1 and l2
        ListNode* pres1=l1;
        ListNode* pres2=l2;
        
        pres3=root;
       int x,y;
        int sum;int carry=0;
        while(pres1 || pres2 || carry)
        {
           if(!pres1)
               x=0;
            else
                x=pres1->val;
            if(!pres2)
                y=0;
            else
                y=pres2->val;
                
            sum=x+y+carry;
            
            carry=sum/10;
            sum=sum%10;
    
            temp=new ListNode(sum);
            if(!pres3)
            {
                root=temp;
                pres3=root;
            }
            else
            {
                pres3->next=temp;
                pres3=pres3->next;
            }
            if(pres1)
                pres1=pres1->next;
            if(pres2)
                pres2=pres2->next;
        }
        return root;
    }
};
