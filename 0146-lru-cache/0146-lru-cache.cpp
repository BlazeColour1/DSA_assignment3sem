#include <unordered_map>

class LRUCache {
private:
    struct CacheNode {
        int k, v;
        CacheNode* prev;
        CacheNode* next;
        CacheNode(int key, int val) : k(key), v(val), prev(nullptr), next(nullptr) {}
    };

    int max_size;
    std::unordered_map<int, CacheNode*> lookup;
    CacheNode* head;
    CacheNode* tail;

    void detach(CacheNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(CacheNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        max_size = capacity;
        head = new CacheNode(-1, -1);
        tail = new CacheNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (lookup.find(key) == lookup.end()) {
            return -1;
        }
        CacheNode* target = lookup[key];
        detach(target);
        moveToFront(target);
        return target->v;
    }

    void put(int key, int value) {
        if (lookup.find(key) != lookup.end()) {
            CacheNode* target = lookup[key];
            target->v = value;
            detach(target);
            moveToFront(target);
        } else {
            if (lookup.size() == max_size) {
                CacheNode* lru = tail->prev;
                detach(lru);
                lookup.erase(lru->k);
                delete lru;
            }
            CacheNode* fresh = new CacheNode(key, value);
            lookup[key] = fresh;
            moveToFront(fresh);
        }
    }
};
