#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <string>
#include <cmath>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename Key, typename Value>
class HashTable {
private:
    size_t tableSize;
    Node<std::pair<Key, Value>>** table;

    size_t hasher(const Key& key);
    size_t nextPrimeNumber(size_t size);
    bool prime(size_t number);


public:
   
    /**
         *@brief Default constructor
    */
    HashTable();

    /**
         *@brief Destroy the Hash Table object
    */
    ~HashTable();

    /**
         *@brief Insert key-value pair into the hash table.
         *@param Key the key to insert
         *@return computed hash value
    */
    void insert(const Key& key, const Value& value);

    /**
         *@brief Remove key-value pair into the hash table.
         *@param Key the key to insert
         *@return true if key-value pair was removeed
    */
    bool remove(const Key& key);


    /**
        *@brief Get the key-value paired from the hash tbale into a dynamically
                allocated array
        *@param items a reference to pointer that point to dynamically array 
                of value pairs
        *@param counter a referenc to a size_t variable to store total items
                copied into 'items'.
    */
    void getItems(std::pair<Key, Value>*& items, size_t& counter);
    
};

#endif