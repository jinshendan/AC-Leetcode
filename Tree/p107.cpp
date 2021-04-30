// 107. Binary Tree Level Order Traversal II

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
    vector<vector<int>> ans;
    void dfs(int dep, TreeNode* root){
        if (root == NULL) return ;
        if (dep >= ans.size()){
            ans.push_back(vector<int>());
        }
        ans[dep].push_back(root->val);
        dfs(dep+1, root->left);
        dfs(dep+1, root->right);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(0, root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};