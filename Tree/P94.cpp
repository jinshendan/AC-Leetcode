// 94. Binary Tree Inorder Traversal

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

// Recursive
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

//Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        
        if (root == NULL) return ans;
        TreeNode* r = root;
        while(r->left){
            st.push(r);
            r = r->left;
        }
        st.push(r);
        
        while(!st.empty()){
            auto r = st.top();
            st.pop();
            ans.push_back(r->val);
            r = r->right;
            if (r == NULL) continue;
            while(r->left){
                st.push(r);
                r = r->left;
            }
            st.push(r);            
        }
        
        return ans;
        
    }
};