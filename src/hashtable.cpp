#include "hashtable.hpp"
#include "audiotrack.hpp"
#include <algorithm>


template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t size) : tableSize(size) {
    table.resize(size);
}


template <typename key, typename Value>
HashTable<key, Value> ::~HashTable(){

}

// compute hash value
template <typename Key, typename Value>
size_t HashTable<Key, Value>::hash(const Key& key) {
    std::hash<Key> hasher;
    return hasher(key) % tableSize;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::insert(const Key& key, const Value& value){
    size_t index = hash(key);
    std::list<std::pair<Key, Value>>& bucket = table[index];

    // Update existing entry
    for (std::pair<Key, Value>& element : bucket) {
        if (element.first == key) {
            element.second = value;
            return;
        }
    }
    // Add new key-value pair
    bucket.emplace_back(key, value);
}

// Delete audio
template <typename Key, typename Value>
bool HashTable<Key, Value>::remove(const Key& key) {
    size_t index = hash(key);
    std::list<std::pair<Key, Value>>& bucket = table[index];

    for (auto& entry : bucket) {
        if (entry.first == key) {
            bucket.remove(entry);
            return true;
        }
    }

    return false;
}

// check if empty
template <typename Key, typename Value>
bool HashTable<Key, Value>::empty() const {
    for (const auto& bucket: table){
        if (!bucket.empty()) {
            return false;
        }
    }
    return true;
}

// Get Table 
template <typename Key, typename Value>
const std::vector<std::list<std::pair<Key, Value>>>& 
        HashTable<Key, Value>::getTable() const{
            return table;
}


template class HashTable<std::string, AudioTrack>;