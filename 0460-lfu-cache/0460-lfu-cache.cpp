#include <unordered_map>
#include <list>

class LFUCache {
private:
    struct CacheItem {
        int itemKey;
        int itemValue;
        int useCount;
        CacheItem(int k, int v, int f) : itemKey(k), itemValue(v), useCount(f) {}
    };

    int maxCapacity;
    int lowestFreq;
    std::unordered_map<int, std::list<CacheItem>::iterator> registry;
    std::unordered_map<int, std::list<CacheItem>> freqGroups;

    void adjustFrequency(std::list<CacheItem>::iterator target) {
        int k = target->itemKey;
        int v = target->itemValue;
        int f = target->useCount;

        freqGroups[f].erase(target);

        if (freqGroups[f].empty()) {
            freqGroups.erase(f);
            if (lowestFreq == f) {
                lowestFreq++;
            }
        }

        freqGroups[f + 1].push_front(CacheItem(k, v, f + 1));
        registry[k] = freqGroups[f + 1].begin();
    }

public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        lowestFreq = 0;
    }
    
    int get(int key) {
        if (maxCapacity == 0 || registry.find(key) == registry.end()) {
            return -1;
        }
        
        auto current = registry[key];
        int result = current->itemValue;
        adjustFrequency(current);
        return result;
    }
    
    void put(int key, int value) {
        if (maxCapacity == 0) return;

        if (registry.find(key) != registry.end()) {
            auto current = registry[key];
            current->itemValue = value;
            adjustFrequency(current);
            return;
        }

        if (registry.size() == maxCapacity) {
            auto& boundaryList = freqGroups[lowestFreq];
            int victimKey = boundaryList.back().itemKey;
            
            registry.erase(victimKey);
            boundaryList.pop_back();
            
            if (boundaryList.empty()) {
                freqGroups.erase(lowestFreq);
            }
        }

        lowestFreq = 1;
        freqGroups[1].push_front(CacheItem(key, value, 1));
        registry[key] = freqGroups[1].begin();
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */