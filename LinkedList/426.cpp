// 426. Convert Binary Search Tree to Sorted Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    pair<Node*, Node*> dfs(Node* root){
        if (root == NULL) {
            Node* p = NULL;
            return make_pair(p, p);
        }
        Node* smallest = root;
        Node* largest = root;
        if (root->left){
            auto p = dfs(root->left);
            root->left = p.second;
            (p.second)->right = root;
            smallest = p.first;
        } 
        if (root->right){
            auto p = dfs(root->right);
            root->right = p.first;
            (p.first)->left = root;
            largest = p.second;
        }
        return make_pair(smallest, largest);
    }
    
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        auto p = dfs(root);
        (p.first)->left = p.second;
        (p.second)->right = p.first;
        return p.first;
    }
};