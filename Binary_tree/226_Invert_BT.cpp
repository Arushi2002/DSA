/*
https://leetcode.com/problems/invert-binary-tree/

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
    static void preorder(TreeNode* root)
    {
        TreeNode* Right;
        if(root)
        {
            preorder(root->left);
            preorder(root->right);
            Right=root->left;
            root->left=root->right;
            root->right=Right;
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        preorder(root);
        return root; 
    }
};

/*Recursive
TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;
}
Non-Recursive

TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}*/
