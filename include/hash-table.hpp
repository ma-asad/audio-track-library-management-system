#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#include "audio-track.hpp"

/**
 * @brief A struct representing a node in a linked list.
 *
 * @tparam T The type of data stored in the node.
 */
template <typename T>
struct Node {
  T data;
  Node<T>* next;
};

/**
 * @brief A template class representing a hash table data structure.
 *
 * The HashTable class provides functionality to store key-value pairs and
 * perform operations such as insertion, removal, and retrieval.
 *
 * @tparam Key The type of the keys stored in the hash table.
 * @tparam Value The type of the values stored in the hash table.
 */
template <typename Key, typename Value>
class HashTable {
 private:
  size_t tableSize;
  Node<std::pair<Key, Value>>** table;

  /**
   * @brief Hashes the given key to generate a hash value.
   *
   * This function takes a key as input and generates a hash value using a
   * hashing algorithm. The hash value is used to determine the index in the
   * hash table where the key-value pair will be stored.
   *
   * @param key The key to be hashed.
   * @return The hash value generated for the key.
   */
  size_t hasher(const Key& key);

  /**
   * @brief Finds the next prime number greater than the given size.
   *
   * @param size The size to start searching for the next prime number.
   * @return The next prime number greater than the given size.
   */
  size_t nextPrimeNumber(size_t size);

  /**
   * Checks if a given number is prime.
   *
   * @param number The number to be checked.
   * @return True if the number is prime, false otherwise.
   */
  bool prime(size_t number);

 public:
  /**
   * @brief Constructs an empty HashTable object.
   */
  HashTable();

  /**
   * @brief Destructor for the HashTable class.
   *
   * This destructor is responsible for cleaning up any dynamically allocated
   * memory and performing any necessary cleanup operations when an instance of
   * the HashTable class is destroyed.
   */
  ~HashTable();

  /**
   * @brief Inserts a key-value pair into the hash table.
   *
   * @param key The key to be inserted.
   * @param value The value to be inserted.
   * @return true if the key-value pair's location is unique, false otherwise.
   */
  bool insert(const Key& key, const Value& value);

  /**
   * @brief Removes an element from the hashtable with the specified key.
   *
   * @param key The key of the element to be removed.
   * @return true if the element was successfully removed, false otherwise.
   */
  bool remove(const Key& key);

  /**
   * Retrieves all items stored in the hashtable.
   *
   * @param items A pointer to an array of std::pair<Key, Value> objects to
   * store the retrieved items.
   * @param counter A reference to a size_t variable to store the number of
   * retrieved items.
   */
  void getItems(std::pair<Key, Value>*& items, size_t& counter);
};

#endif