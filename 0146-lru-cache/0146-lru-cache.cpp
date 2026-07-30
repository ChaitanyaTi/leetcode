#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    // Doubly linked list storing pair of {key, value}
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

    
    void makeRecentlyUsed(int key) {
        auto it = map[key];
        
        cache.splice(cache.begin(), cache, it);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        
        makeRecentlyUsed(key);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        
        if (map.find(key) != map.end()) {
            map[key]->second = value;
            makeRecentlyUsed(key);
            return;
        }

        
        if (cache.size() == capacity) {
            int lruKey = cache.back().first;
            cache.pop_back();
            map.erase(lruKey);
        }

        
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};
