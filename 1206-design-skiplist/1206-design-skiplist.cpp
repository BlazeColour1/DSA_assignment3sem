#include <vector>
#include <cstdlib>

class Skiplist {
    struct Node {
        int v;
        std::vector<Node*> f;
        Node(int val, int sz) : v(val), f(sz, nullptr) {}
    };

    int max_l;
    Node* h;

    int coin_flip() {
        int l = 1;
        while (l < max_l && (std::rand() & 1)) {
            l++;
        }
        return l;
    }

public:
    Skiplist() : max_l(16) {
        h = new Node(-1, max_l);
    }
    
    bool search(int t) {
        Node* curr = h;
        for (int i = max_l - 1; i >= 0; --i) {
            while (curr->f[i] && curr->f[i]->v < t) {
                curr = curr->f[i];
            }
        }
        curr = curr->f[0];
        return curr && curr->v == t;
    }
    
    void add(int num) {
        std::vector<Node*> path(max_l, nullptr);
        Node* curr = h;
        for (int i = max_l - 1; i >= 0; --i) {
            while (curr->f[i] && curr->f[i]->v < num) {
                curr = curr->f[i];
            }
            path[i] = curr;
        }

        int lvl = coin_flip();
        Node* n = new Node(num, lvl);
        for (int i = 0; i < lvl; ++i) {
            n->f[i] = path[i]->f[i];
            path[i]->f[i] = n;
        }
    }
    
    bool erase(int num) {
        std::vector<Node*> path(max_l, nullptr);
        Node* curr = h;
        for (int i = max_l - 1; i >= 0; --i) {
            while (curr->f[i] && curr->f[i]->v < num) {
                curr = curr->f[i];
            }
            path[i] = curr;
        }

        curr = curr->f[0];
        if (!curr || curr->v != num) {
            return false;
        }

        for (int i = 0; i < max_l; ++i) {
            if (path[i]->f[i] != curr) {
                break;
            }
            path[i]->f[i] = curr->f[i];
        }
        delete curr;
        return true;
    }
};


/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */