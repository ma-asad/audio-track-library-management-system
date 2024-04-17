#include "hashtable.hpp"

#include "audiotrack.hpp"

// element of table initialised to nullptr
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() {
  tableSize = nextPrimeNumber(503);
  table = new Node<std::pair<Key, Value>>*[tableSize]();
}

// frees allocated memory to prevent memory leaks
template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
  for (size_t c = 0; c < tableSize; ++c) {
    Node<std::pair<Key, Value>>* currentNode = table[c];

    while (currentNode) {
      Node<std::pair<Key, Value>>* nextNode = currentNode->next;
      delete currentNode;
      currentNode = nextNode;
    }
  }
  delete[] table;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::insert(const Key& key, const Value& value) {
  size_t position = hasher(key);
  Node<std::pair<Key, Value>>* newNode =
      new Node<std::pair<Key, Value>>{{key, value}, nullptr};

  if (!table[position]) {
    table[position] = newNode;
    return true;

  } else {
    Node<std::pair<Key, Value>>* currentNode = table[position];

    while (currentNode->next) {
      currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    return false;
  }
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::remove(const Key& key) {
  size_t position = hasher(key);
  Node<std::pair<Key, Value>>* currentNode = table[position];
  Node<std::pair<Key, Value>>* previousNode = nullptr;
  std::cout << "currentNode: " << currentNode << std::endl;

  while (currentNode) {
    std::cout << "currentNode->data.first: " << currentNode->data.first
              << std::endl;
    std::cout << "key: " << key << std::endl;

    if (currentNode->data.first == key) {
      if (previousNode) {
        previousNode->next = currentNode->next;
      } else {
        table[position] = currentNode->next;
      }
      delete currentNode;
      return true;
    }
    previousNode = currentNode;
    currentNode = currentNode->next;
  }
  return false;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::getItems(std::pair<Key, Value>*& items,
                                     size_t& counter) {
  counter = 0;
  for (size_t c = 0; c < tableSize; ++c) {
    Node<std::pair<Key, Value>>* currentNode = table[c];
    while (currentNode) {
      ++counter;
      currentNode = currentNode->next;
    }
  }

  items = new std::pair<Key, Value>[counter];
  size_t position = 0;
  for (size_t c = 0; c < tableSize; ++c) {
    Node<std::pair<Key, Value>>* currentNode = table[c];
    while (currentNode) {
      items[position++] = currentNode->data;
      currentNode = currentNode->next;
    }
  }
}

template <typename Key, typename Value>
size_t HashTable<Key, Value>::hasher(const Key& key) {
  size_t hashingValue = 0;
  for (char character : key) {
    hashingValue = (hashingValue * 31) + character;
  }
  return hashingValue % tableSize;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::prime(size_t number) {
  if (number <= 1) {
    return false;
  }
  for (size_t c = 2; c <= std::sqrt(number); ++c) {
    if (number % c == 0) {
      return false;
    }
  }
  return true;
}

template <typename Key, typename Value>
size_t HashTable<Key, Value>::nextPrimeNumber(size_t number) {
  while (!prime(number)) {
    ++number;
  }
  return number;
}

template class HashTable<std::string, AudioTrack>;