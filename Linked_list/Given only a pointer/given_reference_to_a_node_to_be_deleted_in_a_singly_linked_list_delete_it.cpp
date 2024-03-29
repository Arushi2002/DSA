/* 
https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

//Optimized Solution
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        //storing the node next to given node in a pointer.	
    	Node* temp = del->next;
    	
    	//copying the data of pointer in the given current node.
    	del->data = temp->data;
    	
    	//storing the next node to pointer in link part of current node.
    	del->next = temp->next;

    	// freeing memory.
    	free(temp);
    	
    }
};

//My solution
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        Node* pres=del;
        while(pres->next)
        {
            pres->data=(pres->next)->data;
            if(pres->next->next)
                pres=pres->next;
            else
            {
                free(pres->next);
                pres->next=NULL;
            }
        }
    }

};
