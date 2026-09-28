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
    ListNode* partition(ListNode* head, int x) {
        ListNode s_head(0), b_head(0);
        ListNode* s_tail = &s_head;
        ListNode* b_tail = &b_head;
        
        while (head) {
            if (head->val < x) {
                s_tail->next = head;
                s_tail = s_tail->next;
            } else {
                b_tail->next = head;
                b_tail = b_tail->next;
            }
            head = head->next;
        }
        
        b_tail->next = nullptr;
        s_tail->next = b_head.next;
        
        return s_head.next;
    }
};
