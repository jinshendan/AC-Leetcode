// 99. Recover Binary Search Tree

/**
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
    TreeNode* first;
    TreeNode* second;
    TreeNode* last;
    void inorder(TreeNode* root){
        if (root == NULL) return;
        inorder(root->left);
         if (last != NULL and last->val > root->val){
            if (!first){
                first = last;
                second = root;
            }
            else second = root;
        } 
        last = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        last = NULL;
        first = NULL;
        second = NULL;
        inorder(root);   
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};