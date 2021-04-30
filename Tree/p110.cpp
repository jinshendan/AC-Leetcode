// 110. Balanced Binary Tree

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
    bool get(TreeNode* root, int& h){
        if (root == NULL) {
            h = 0;
            return true;
        }
        if (root->left == NULL and root->right == NULL) {
            h = 1; 
            return true;
        }
        
        int l, r;
        bool ok = get(root->left, l) and get(root->right, r);
        if (!ok) return false;
        if (abs(l - r) > 1) return false;
        h = max(l, r) + 1;
        return true;
    }
    
    
    bool isBalanced(TreeNode* root) {
        int h;
        return get(root, h);
    }
};