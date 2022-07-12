/**
https://leetcode.com/problems/same-tree/

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //If both p and q are NULL
        if(!p && !q) return true;
        //If either p or q is NULL
        if(!p || !q) return false;
        if(p->val==q->val)
             return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
             //return l && r;
        
        return false;  
    }
};
    /*Smart solution
    bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL || q == NULL) return (p == q);
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}*/
/*recursive solution
//iterative

  class Solution {
  public:
      bool isSameTree(TreeNode* p, TreeNode* q) {
          queue<TreeNode *> queue;
          queue.push(p);
          queue.push(q);
          while (queue.size()!=0){
              TreeNode * q2=queue.front();
              queue.pop();
              TreeNode * q1=queue.front();
              queue.pop();
              if (q1==nullptr && q2==nullptr) continue;
              if (q1==nullptr || q2==nullptr) return false;
              if (q1->val!=q2->val) return false;
              queue.push(q1->left);
              queue.push(q2->left);
              queue.push(q1->right);
              queue.push(q2->right);
          }
          return true;
      }
  };*/
