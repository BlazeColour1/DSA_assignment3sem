class MyLinkedList {
private:
    struct ListNode {
        int data;
        ListNode* next;
        ListNode(int val) : data(val), next(nullptr) {}
    };
    
    ListNode* dummy;
    int length;

public:
    MyLinkedList() {
        dummy = new ListNode(-1);
        length = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= length) return -1;
        ListNode* iter = dummy->next;
        while (index--) {
            iter = iter->next;
        }
        return iter->data;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummy->next;
        dummy->next = node;
        length++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* iter = dummy;
        while (iter->next) {
            iter = iter->next;
        }
        iter->next = node;
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        ListNode* iter = dummy;
        for (int i = 0; i < index; ++i) {
            iter = iter->next;
        }
        ListNode* node = new ListNode(val);
        node->next = iter->next;
        iter->next = node;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;
        ListNode* iter = dummy;
        for (int i = 0; i < index; ++i) {
            iter = iter->next;
        }
        ListNode* target = iter->next;
        iter->next = target->next;
        delete target;
        length--;
    }
    
    ~MyLinkedList() {
        ListNode* iter = dummy;
        while (iter) {
            ListNode* nextNode = iter->next;
            delete iter;
            iter = nextNode;
        }
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */