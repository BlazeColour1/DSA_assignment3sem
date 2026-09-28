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
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> present_vals(nums.begin(), nums.end());
        int total_components = 0;
        bool tracking = false;

        ListNode* node = head;
        while (node) {
            if (present_vals.find(node->val) != present_vals.end()) {
                if (!tracking) {
                    total_components++;
                    tracking = true;
                }
            } else {
                tracking = false;
            }
            node = node->next;
        }

        return total_components;
    }
};
