// 82. Remove Duplicates from Sorted List II

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* h = new ListNode(-101);
        h->next = head;
        
        ListNode* last = h;
        ListNode* cur = head;
        
        while(cur){
            ListNode* p = cur->next;
            int num = 0;
            while (p and p->val == cur->val) {
                p = p -> next;
                num++;
            }
            
            if (num == 0){
                if (p == NULL) break;
                last = cur;
                cur = cur->next;
            }
            else{
                last->next = p;
                cur = p;
            }
        }
        return h->next;
    }
};