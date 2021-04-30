// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* does(int iL, int iR, int pL, int pR, vector<int>& inorder, vector<int>& postorder ){
        if (iL > iR) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pR]);
        int x;
        for (int i = iL; i <= iR; i++){
            if (postorder[pR] == inorder[i]){
                x = i;
                break;
            }
        }
        int len = iR - x;
        root->left = does(iL, x - 1,  pL, pR - len - 1, inorder, postorder);
        root->right = does(x + 1, iR, pR - len, pR-1, inorder, postorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return does(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder);    
    }
};