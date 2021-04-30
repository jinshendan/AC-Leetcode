// 98. Validate Binary Search Tree

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
    bool check(int lower, int upper, TreeNode* root){
        if (root == NULL) return true;
        if (lower > upper) return false;
        if (lower > root->val or root->val > upper) return false;
        
        if (root->val == INT_MIN and root->left) return false;
        if (root->val != INT_MIN)
            if (!check(lower, root->val-1, root->left)) return false;
    
        if (root->val == INT_MAX and root->right) return false;
        if (root->val != INT_MAX)
            if (!check(root->val+1, upper, root->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return check(INT_MIN, INT_MAX, root);
    }
};