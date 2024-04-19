#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP


template <typename T>
class vectorDynamicArray {
private:
    T* data;
    int size;
    int capacity;

public:
    vectorDynamicArray();
    ~vectorDynamicArray();

    void push(const T& value);
    T& operator[](int position);
    int getSize() const;
    int getCapacity() const;
};

#endif