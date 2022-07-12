// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/1654181/C%2B%2BPythonJava-Simple-Solution-w-Images-and-Explanation-or-BFS-%2B-DFS-%2B-O(1)-Optimized-BFS
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    static void preorder(Node* root,Node* Right)
    {
        if(root)
        {
            //printf("%d",root->val);
            root->next=Right;
            Right=root->right;
            preorder(root->left,root->right);
            if(root->next)
            {
                if(root->next->left)
                    preorder(root->right,root->next->left);   
                else
                    preorder(root->right,root->next->right); 
            }
                
            else
                preorder(root->right,NULL);
        }
    }
    Node* connect(Node* root) {
       preorder(root,NULL);
       return root;
    }
    
};
