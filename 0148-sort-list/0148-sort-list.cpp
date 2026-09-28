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
private:
    ListNode* joinLists(ListNode* a, ListNode* b) {
        ListNode headNode(0);
        ListNode* tail = &headNode;
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return headNode.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *curr = head, *runner = head, *last = nullptr;
        while (runner && runner->next) {
            last = curr;
            curr = curr->next;
            runner = runner->next->next;
        }
        last->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(curr);
        return joinLists(left, right);
    }
};
