/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        for (Node* p = head; p != nullptr; p = p->next->next) {
            Node* nxt = p->next;
            p->next = new Node(p->val);
            p->next->next = nxt;
        }
        
        for (Node* p = head; p != nullptr; p = p->next->next) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        for (Node* p = head; p != nullptr; ) {
            tail->next = p->next;
            tail = tail->next;
            p->next = p->next->next;
            p = p->next;
        }
        
        Node* res = dummy->next;
        delete dummy;
        return res;
    }
};
