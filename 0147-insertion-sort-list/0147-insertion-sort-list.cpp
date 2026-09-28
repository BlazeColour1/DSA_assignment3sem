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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        ListNode* node = head;

        while (node) {
            ListNode* nxt = node->next;
            ListNode* scan = &dummy;

            while (scan->next && scan->next->val < node->val) {
                scan = scan->next;
            }

            node->next = scan->next;
            scan->next = node;
            node = nxt;
        }

        return dummy.next;
    }
};
