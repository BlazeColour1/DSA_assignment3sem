/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* walker = root;
        
        while (walker) {
            if (walker->left) {
                TreeNode* deepRight = walker->left;
                while (deepRight->right) {
                    deepRight = deepRight->right;
                }
                
                deepRight->right = walker->right;
                
                walker->right = walker->left;
                walker->left = nullptr;
            }
            walker = walker->right;
        }
    }
};