/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode* runner = head;
        ListNode* walker = head;
        bool hasCycle = false;
        
        while (runner != nullptr && runner->next != nullptr) {
            walker = walker->next;
            runner = runner->next->next;
            
            if (walker == runner) {
                hasCycle = true;
                break;
            }
        }
        
        if (!hasCycle) return nullptr;
        
        ListNode* finder = head;
        while (finder != walker) {
            finder = finder->next;
            walker = walker->next;
        }
        
        return finder;
    }
};
