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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode *p1 = head, *p2 = head;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* right = p1->next;
        p1->next = nullptr;
        
        ListNode* last = nullptr;
        while (right) {
            ListNode* nxt = right->next;
            right->next = last;
            last = right;
            right = nxt;
        }

        ListNode* left = head;
        while (last) {
            ListNode* l_next = left->next;
            ListNode* r_next = last->next;

            left->next = last;
            last->next = l_next;

            left = l_next;
            last = r_next;
        }
    }
};
