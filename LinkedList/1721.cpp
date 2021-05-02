// 1721. Swapping Nodes in a Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head;
        for (int i = 0; i < k - 1; i++){
            p = p->next;
        }
        
        ListNode* slow = head;
        ListNode* fast = p;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        int tmp = p->val;
        p->val = slow->val;
        slow->val = tmp;
        return head;
    }
};