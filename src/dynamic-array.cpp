#include "dynamic-array.hpp"
#include "audio-track.hpp"
#include "playlist.hpp"

template <typename T>
vectorDynamicArray<T>::vectorDynamicArray() : data(nullptr), size(0), capacity(0) {}

template <typename T>
vectorDynamicArray<T>::~vectorDynamicArray() {
    delete[] data;
}

template <typename T>
void vectorDynamicArray<T>::push(const T& Value) {
    if (size == capacity){
        int newCapacity;
        if (capacity == 0) {
            newCapacity = 1;
        } else {
            newCapacity = capacity * 2;
        }

        // copy existing data into new array
        //free old array and redirect to new array
        //insert new element and increase size

        T* newData = new T[newCapacity];
        for (int c = 0; c < size; ++c){
            newData[c] = data[c];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = Value;

}

template <typename T>
T& vectorDynamicArray<T>::operator[](int position) {
    return data[position];
}

template <typename T>
int vectorDynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
int vectorDynamicArray<T>::getCapacity() const {
    return capacity;
}

// Explicit instantiation of the template class for the desired types
template class vectorDynamicArray<int>;
template class vectorDynamicArray<AudioTrack>;
template class vectorDynamicArray<Playlist>;