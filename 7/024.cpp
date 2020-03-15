#include <list>
#include <unordered_map>

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iter;
    
public:
    // @param capacity, an integer
    LFUCache(int capacity) {
        // Write your code here
        this->capacity = capacity;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // Write your code here
        if (capacity <= 0) {
            return;
        }
        // key 已存在，更新 Value
        if (get(key) != -1) {
            cache[key].first = value;
            return;
        }
        // cache 已满，擦除 minFreq 的 key
        if (cache.size() >= capacity) {
            cache.erase(freq[minFreq].front());
            iter.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        // 写入新 key
        cache[key] = { value, 1 };
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minFreq = 1;
    }

    // @return an integer
    int get(int key) {
        // Write your code here
        // 不存在此 key
        if (cache.count(key) == 0) {
            return -1;
        }
        // 更新 cache
        freq[cache[key].second].erase(iter[key]);
        cache[key].second++;
        freq[cache[key].second].push_back(key);
        iter[key] = --freq[cache[key].second].end();
        if (freq[minFreq].size() == 0) {
            minFreq++;
        }
        return cache[key].first;
    }
};
