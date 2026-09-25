#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:

    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {


        if (mp.count(key) == 0)
            return -1;
        auto it = mp[key];

        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});

        mp[key] = cache.begin();

        return value;
    }


    void put(int key, int value) {

        if (mp.count(key)) {
            cache.erase(mp[key]);

            mp.erase(key);
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();


        
        if (cache.size() > capacity) {

            auto last = cache.back();

       
            mp.erase(last.first);

          
            cache.pop_back();
        }
    }
};


int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl;  // 10

    cache.put(3, 30);

    cout << cache.get(2) << endl;  // -1

    cout << cache.get(3) << endl;  // 30

    return 0;
}
