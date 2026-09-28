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
    struct NodeComparator {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, NodeComparator> pq;
        
        for (size_t i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        
        ListNode root(0);
        ListNode* current = &root;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            current->next = node;
            current = current->next;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return root.next;
    }
};
