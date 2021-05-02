// 19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n - 1; i++)
            fast = fast->next;
        
        ListNode* father_slow = NULL;
        while(fast->next){
            fast = fast->next;
            father_slow = slow;
            slow = slow->next;
        }
        if (father_slow)
            father_slow -> next = slow -> next;
        else
            head = slow->next;
        
        return head;
    }
};