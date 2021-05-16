// 654. Maximum Binary Tree

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
    TreeNode* does(int i, int j, vector<int>& nums){
        if (i > j) return NULL;
        int mx = -1, mxk;
        for (int k = i; k <= j; k++){
            if (nums[k] >= mx){
                mx = nums[k];
                mxk = k;
            }
        }
        TreeNode* root = new TreeNode(nums[mxk]);
        root->left = does(i, mxk-1, nums);
        root->right = does(mxk+1, j, nums);
        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return does(0, n-1, nums);
    }
};