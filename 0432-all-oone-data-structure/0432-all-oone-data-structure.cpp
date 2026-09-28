#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class AllOne {
private:
    struct FrequencyNode {
        int val;
        unordered_set<string> elements;
    };

    list<FrequencyNode> chain;
    unordered_map<string, list<FrequencyNode>::iterator> registry;

public:
    AllOne() = default;
    
    void inc(string key) {
        auto it = registry.find(key);
        if (it == registry.end()) {
            if (chain.empty() || chain.front().val > 1) {
                chain.push_front({1, {key}});
            } else {
                chain.front().elements.insert(key);
            }
            registry[key] = chain.begin();
        } else {
            auto curr = it->second;
            auto nextNode = next(curr);
            
            if (nextNode == chain.end() || nextNode->val > curr->val + 1) {
                nextNode = chain.insert(nextNode, {curr->val + 1, {key}});
            } else {
                nextNode->elements.insert(key);
            }
            
            registry[key] = nextNode;
            curr->elements.erase(key);
            if (curr->elements.empty()) {
                chain.erase(curr);
            }
        }
    }
    
    void dec(string key) {
        auto curr = registry[key];
        
        if (curr->val == 1) {
            registry.erase(key);
        } else {
            auto prevNode = prev(curr);
            if (curr == chain.begin() || prevNode->val < curr->val - 1) {
                prevNode = chain.insert(curr, {curr->val - 1, {key}});
            } else {
                prevNode->elements.insert(key);
            }
            registry[key] = prevNode;
        }
        
        curr->elements.erase(key);
        if (curr->elements.empty()) {
            chain.erase(curr);
        }
    }
    
    string getMaxKey() {
        return chain.empty() ? "" : *(chain.back().elements.begin());
    }
    
    string getMinKey() {
        return chain.empty() ? "" : *(chain.front().elements.begin());
    }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */