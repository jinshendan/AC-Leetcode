// 108. Convert Sorted Array to Binary Search Tree

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
    TreeNode* does(int l, int r, vector<int>& nums){
        if (l > r) return NULL;
        int mid = (r - l) / 2 + l;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = does(l, mid-1, nums);
        root->right = does(mid+1, r, nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return does(0, nums.size()-1, nums);
    }
};