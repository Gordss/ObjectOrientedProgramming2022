#ifndef __VECTOR_H
#define __VECTOR_H

#include <iostream>

#define DEFAULT_CAPACITY 8

template <typename T>
class Vector
{
private:
    T* mData;
    size_t mSize;
    size_t mCapacity;

    void resize(size_t newSize, size_t newCapacity);
    void copy(T* data);
public:
    Vector();
    Vector(size_t capacity);
    
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other);

    Vector<T>& operator=(const Vector<T>& other);
    Vector<T>& operator=(Vector<T>&& other);
    ~Vector();

    size_t getCapacity() const;
    size_t getSize() const;
    T getAt(size_t index) const;
    T& getAt(size_t index);

    bool isEmpty() const;
    
    T getFirst() const;
    T getLast() const;

    void assign(size_t n, const T& x);
    void pushBack(const T& x);
    void popBack();
    void removeAt(size_t index);
    bool operator==(const Vector<T>& other) const;
    Vector operator+(const Vector<T>& other);

    T& operator[](size_t index);
    T operator[](size_t index) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Vector<U>& other);
    
    template<typename U>
    friend std::istream& operator>>(std::istream& in, Vector<U>& other);
};

template <typename K>
Vector<K> max(Vector<K>& a, Vector<K>& b);

#include "Vector.inl"

#endif