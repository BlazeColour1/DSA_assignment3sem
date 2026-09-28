/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* level = root;
        while (level->left) {
            Node* cursor = level;
            while (cursor) {
                cursor->left->next = cursor->right;
                if (cursor->next) {
                    cursor->right->next = cursor->next->left;
                }
                cursor = cursor->next;
            }
            level = level->left;
        }
        return root;
    }
};
