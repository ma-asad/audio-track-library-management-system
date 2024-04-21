#include "hash-table.hpp"

template <typename Key, typename Value>
size_t HashTable<Key, Value>::hasher(const Key& key) const {
  size_t hashingValue = 0;

  // Iterate over each character in the key
  for (char character : key) {
    // Update the hashing value based on the current character
    // The constant 31 is chosen because it's a prime number, which helps to
    // distribute the hash values more evenly
    hashingValue = (hashingValue * 31) + character;
  }

  return hashingValue % tableSize;
}

template <typename Key, typename Value>
size_t HashTable<Key, Value>::nextPrimeNumber(size_t number) {
  while (!prime(number)) {
    ++number;
  }

  return number;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::prime(size_t number) {
  // If the number is less than or equal to 1, it's not prime
  if (number <= 1) {
    return false;
  }

  // Check divisibility for all numbers up to the square root of the number
  for (size_t c = 2; c <= std::sqrt(number); ++c) {
    // If the number is divisible by any of these numbers, it's not prime
    if (number % c == 0) {
      return false;
    }
  }

  // If no divisors were found, the number is prime
  return true;
}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() {
  tableSize = nextPrimeNumber(503);

  // Allocate memory for the hash table, which is an array of pointers to nodes
  table = new Node<std::pair<Key, Value>>*[tableSize]();
}

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

    while (currentNode) {
      // Check if the value is identical to the one being inserted
      if (currentNode->data.second == value) {
        // Delete the new node as it's not needed
        delete newNode;

        // Indicate that insertion was not successful
        return false;
      }

      // If we're at the last node in the list, insert the new node
      if (!currentNode->next) {
        currentNode->next = newNode;

        return true;
      }

      currentNode = currentNode->next;
    }
  }

  return false;
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::remove(const Key& key) {
  size_t position = hasher(key);
  Node<std::pair<Key, Value>>* currentNode = table[position];
  Node<std::pair<Key, Value>>* previousNode = nullptr;

  while (currentNode) {
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
std::pair<size_t, std::pair<Key, Value>*> HashTable<Key, Value>::listItems()
    const {
  size_t counter = 0;
  for (size_t c = 0; c < tableSize; ++c) {
    Node<std::pair<Key, Value>>* currentNode = table[c];
    while (currentNode) {
      ++counter;
      currentNode = currentNode->next;
    }
  }

  std::pair<Key, Value>* items = new std::pair<Key, Value>[counter];
  size_t position = 0;
  for (size_t c = 0; c < tableSize; ++c) {
    Node<std::pair<Key, Value>>* currentNode = table[c];
    while (currentNode) {
      items[position++] = currentNode->data;
      currentNode = currentNode->next;
    }
  }

  return {counter, items};
}

template <typename Key, typename Value>
Value* HashTable<Key, Value>::findTrack(const Key& key) const {
  size_t index = hasher(key);
  Node<std::pair<Key, Value>>* currentNode = table[index];

  while (currentNode) {
    if (currentNode->data.first == key) {
      return &currentNode->data.second;
    }

    currentNode = currentNode->next;
  }

  // Return null if the key was not found.
  return nullptr;
}

template <typename Key, typename Value>
std::pair<int, std::pair<Key, Value>*> HashTable<Key, Value>::findAllTracks(
    const Key& key) const {
  size_t index = hasher(key);
  Node<std::pair<Key, Value>>* currentNode = table[index];

  // Count the number of matches
  int counter = 0;
  while (currentNode) {
    if (currentNode->data.first == key) {
      counter++;
    }
    currentNode = currentNode->next;
  }

  // Allocate an array of the correct size
  std::pair<Key, Value>* items = new std::pair<Key, Value>[counter];

  // Reset the currentNode pointer to the start of the list
  currentNode = table[index];

  // Fill the array with the matches
  int i = 0;
  while (currentNode) {
    if (currentNode->data.first == key) {
      items[i] = currentNode->data;
      i++;
    }
    currentNode = currentNode->next;
  }

  return {counter, items};
}

template class HashTable<std::string, AudioTrack>;