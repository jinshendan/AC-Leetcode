// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* does(int pL, int pR, int iL, int iR, vector<int>& preorder, vector<int>& inorder){
        if (pL > pR) return NULL;
        TreeNode* root = new TreeNode(preorder[pL]);
        int x;
        for (int i = iL; i <= iR; i++) if (inorder[i] == preorder[pL]) {
            x = i;
            break;
        }
        int len1 = x - iL;
        root->left = does(pL + 1, pL + len1, iL, x - 1, preorder, inorder);
        root->right = does(pL + len1 + 1, pR, x + 1, iR, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return does(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
    }
};