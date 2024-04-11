#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <string>


/**
 *@brief Hash table class template
 *@tparam Key The type of the key.
 *@tparam Key The type of the value.
 *@param Key The size of the hash table.
*/
template <typename Key, typename Value>
class HashTable {
    private:
    std::vector<std::list<std::pair<Key, Value>>> table;
    size_t tableSize;


    /**
        *@brief Compute the hash value for a given key
        *@param Key The key to compute the hash value for.
        *@return The computed hash value.
    */
    size_t hash(const Key& key);


public:
    /**
        *@brief Default constructor with size of 503
        *@param size The size of the hash table.
    */
    
    HashTable(size_t size = 503);

    /**
        *@brief Destroy the Hash Table object.
    */
    ~HashTable();

    /**
        *@brief Insert key-value pair into the hash table.
        *@param Key The key to insert.
        *@return The computed hash value.
    */
    void insert(const Key& key, const Value& value);

    
    /**
        *@brief Remove key-value pair from the hash table.
        *@param Key The key to remove.
        *@return true if the key-value pair was removed.
    */
    bool remove(const Key& key);


    /**
        *@brief Check if the hash table is empty.
        *@return true if the hash table is empty else false.
    */
    bool empty() const;

    /**
        *@brief Get the table of the hash table
        *@return  The table of the hash table..
    */
    const std::vector<std::list<std::pair<Key, Value>>>& getTable() const;
};

#endif