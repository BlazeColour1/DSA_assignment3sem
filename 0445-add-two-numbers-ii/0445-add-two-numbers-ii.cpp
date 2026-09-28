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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        stack<int> digits1;
        stack<int> digits2;
        
        for (ListNode* curr = list1; curr != nullptr; curr = curr->next) {
            digits1.push(curr->val);
        }
        
        for (ListNode* curr = list2; curr != nullptr; curr = curr->next) {
            digits2.push(curr->val);
        }
        
        ListNode* resultList = nullptr;
        int overflow = 0;
        
        while (!digits1.empty() || !digits2.empty() || overflow > 0) {
            int currentSum = overflow;
            
            if (!digits1.empty()) {
                currentSum += digits1.top();
                digits1.pop();
            }
            
            if (!digits2.empty()) {
                currentSum += digits2.top();
                digits2.pop();
            }
            
            overflow = currentSum / 10;
            
            ListNode* freshNode = new ListNode(currentSum % 10);
            freshNode->next = resultList;
            resultList = freshNode;
        }
        
        return resultList;
    }
};
