#include <iostream>
#include <unordered_map>
#include <list>

// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present.
// When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
// The cache is initialized with a positive capacity.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

// my understanding:
// 1. Set will insert into the head of the list.
// 2. Get will move the accessed data to the head of the list.
// 3. Remove the last element of the list every time if needed.
// for the example:
// cache.put(1, 1);    // list : 1
// cache.put(2, 2);    // list : 2->1
// cache.get(1);       // list : 1->2
// cache.put(3, 3);    // After removing the last 2, list : 1->3
// cache.get(2);       // list : 3->1 return -1
// cache.put(4, 4);    // After removing the last 1, list : 4->3
// cache.get(1);       // list : 4->3, return -1
// cache.get(3);       // list : 3->4
// cache.get(4);       // list : 4->3

namespace LRUCache
{
class LRUCache {
public:
    LRUCache() = default;
    void setCapacity(int capacity)
    {
        capacity_ = capacity;
    }

    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }

    int get(int key)
    {
        auto search = table_.find(key);
        if (search == table_.end())
        {
             std::cout << -1 << std::endl;
            return -1;
        }
        auto ret = search->second->second;
        moveListElemToFirst(key, search->second);
        std::cout << ret << std::endl;
        return ret;
    }

    void put(int key, int value)
    {
        if (capacity_ <= table_.size())
        {
            removeLastElemFromList();
        }
        insertListElemToFirst(key, value);
    }

private:
    using myPair = std::pair<int, int>;
    using myList = std::list<myPair> ;
    using CacheTable = std::unordered_map<int, myList::iterator>;
    CacheTable table_;
    myList listDatas_;
    int capacity_ ;

    void insertListElemToFirst(const int& key, const int& data)
    {
        listDatas_.push_front(myPair(key, data));
        table_[key] = listDatas_.begin();
    }
    void moveListElemToFirst(const int& key, const myList::iterator& it)
    {
        listDatas_.push_front(*it);
        listDatas_.erase(it);
        table_.erase(key);
        table_[key] = listDatas_.begin();
    }
     void removeLastElemFromList()
    {
        table_.erase(listDatas_.back().first);
        listDatas_.pop_back();
    }
}; // class LRUCache
}  // namespace  LRUCache
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
