/**
https://leetcode.com/problems/diameter-of-binary-tree/submissions/

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
    static int height(TreeNode* t,int& maxx){
        int l,r;
        if(t==NULL) return -1;
        if((t->left==NULL) && (t->right==NULL))
            return 0;
        l=height(t->left,maxx);
        r=height(t->right,maxx);
        if(l==-1)
            maxx=max(r+1,maxx);
        else if(r==-1)
            maxx=max(l+1,maxx);
        else
            maxx=max(l+r+2,maxx);
        if(l>r)
            return l+1;
        return r+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxx=0;
        height(root,maxx);
        return maxx;
    }
};
/*
int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    
    int rec(TreeNode* root, int &d) {
        if(root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }*/
