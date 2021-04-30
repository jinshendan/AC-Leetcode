// 114. Flatten Binary Tree to Linked List

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
    TreeNode* last;
    void dfs(TreeNode* root){
        if (root == NULL) return;
        TreeNode* l = root->left;
        TreeNode* r= root->right;
        
        if (last != NULL){
            last -> left = NULL;
            last -> right = root;
        }
        
        last = root;
        dfs(l);
        dfs(r);
    }
    
    void flatten(TreeNode* root) {
        last = NULL;
        dfs(root);
    }
};