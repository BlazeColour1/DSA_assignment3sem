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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode anchor(0);
        anchor.next = head;
        
        ListNode* cursor = &anchor;
        ListNode* boundary = head;
        int element_count = 0;
        
        while (boundary) {
            element_count++;
            boundary = boundary->next;
        }
        
        while (element_count >= k) {
            ListNode* active = cursor->next;
            ListNode* subsequent = active->next;
            
            for (int step = 1; step < k; ++step) {
                active->next = subsequent->next;
                subsequent->next = cursor->next;
                cursor->next = subsequent;
                subsequent = active->next;
            }
            
            cursor = active;
            element_count -= k;
        }
        
        return anchor.next;
    }
};
