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
    ListNode* root;

public:
    Solution(ListNode* head) {
        root = head;
    }
    
    int getRandom() {
        int selected = root->val;
        ListNode* iterator = root->next;
        int count = 2;
        
        while (iterator) {
            if (rand() % count == 0) {
                selected = iterator->val;
            }
            count++;
            iterator = iterator->next;
        }
        
        return selected;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */