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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        for (ListNode* walk = head; walk != nullptr; walk = walk->next) {
            count++;
        }
        
        int width = count / k;
        int rem = count % k;
        
        vector<ListNode*> parts(k, nullptr);
        ListNode* active = head;
        
        int idx = 0;
        while (active != nullptr && idx < k) {
            parts[idx] = active;
            int current_limit = width + (rem > 0 ? 1 : 0);
            rem--;
            
            ListNode* prev = nullptr;
            for (int step = 0; step < current_limit; step++) {
                prev = active;
                active = active->next;
            }
            
            if (prev != nullptr) {
                prev->next = nullptr;
            }
            idx++;
        }
        
        return parts;
    }
};
