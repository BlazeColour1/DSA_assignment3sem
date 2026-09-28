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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if (!head || l == r) return head;

        ListNode* d = new ListNode(0, head);
        ListNode* p = d;

        for (int i = 0; i < l - 1; ++i) {
            p = p->next;
        }

        ListNode* curr = p->next;
        ListNode* nextNode = nullptr;

        for (int i = 0; i < r - l; ++i) {
            nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = p->next;
            p->next = nextNode;
        }

        ListNode* ret = d->next;
        delete d;
        return ret;
        
    }
};