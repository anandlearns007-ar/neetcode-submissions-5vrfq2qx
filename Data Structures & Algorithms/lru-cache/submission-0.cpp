class LRUCache {
public:
    int capacity;

    // key -> iterator of list
    unordered_map<int, list<pair<int,int>>::iterator> cache;

    // {key, value}
    list<pair<int,int>> lru;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // Move accessed node to front (MRU)
        auto it = cache[key];
        int value = it->second;

        lru.erase(it);
        lru.push_front({key, value});
        cache[key] = lru.begin();

        return value;
    }

    void put(int key, int value) {
        // If key already exists → remove old position
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key]);
        }
        // If capacity full → remove LRU (back)
        else if (lru.size() == capacity) {
            auto last = lru.back();
            cache.erase(last.first);
            lru.pop_back();
        }

        // Insert new node at front (MRU)
        lru.push_front({key, value});
        cache[key] = lru.begin();
    }
};