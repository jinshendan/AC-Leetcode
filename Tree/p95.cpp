//  95. Unique Binary Search Trees II

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
    void dfs(int l, int r, vector<TreeNode*>& v){
        if (l > r){
            return ;
        }
        if (l == r){
            TreeNode* x = new TreeNode(l);
            v.push_back(x);
            return ;
        }
        
        for (int i = l; i<= r; i++){
            
            vector<TreeNode*> left;
            vector<TreeNode*> right;
            
            dfs(l, i-1, left);
            dfs(i+1, r, right);
            
            if (left.size() == 0){
                left.push_back(NULL);
            }
            if (right.size() == 0){
                right.push_back(NULL);
            }
            
            for (auto nl: left)
                for (auto nr: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = nl;
                    root->right = nr;
                    v.push_back(root);
                }
        }
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        dfs(1, n, ans);
        return ans;
    }
};