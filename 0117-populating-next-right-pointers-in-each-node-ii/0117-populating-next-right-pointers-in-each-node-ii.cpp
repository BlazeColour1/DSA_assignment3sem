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
        Node* active = root;
        while (active) {
            Node placeholder(0);
            Node* currentChild = &placeholder;
            for (; active; active = active->next) {
                if (active->left) {
                    currentChild->next = active->left;
                    currentChild = currentChild->next;
                }
                if (active->right) {
                    currentChild->next = active->right;
                    currentChild = currentChild->next;
                }
            }
            active = placeholder.next;
        }
        return root;
    }
};
