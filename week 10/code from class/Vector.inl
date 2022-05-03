#include "Vector.h"

template<typename T>
void Vector<T>::resize(size_t newSize, size_t newCapacity)
{
    // size up
    bool shouldErase = false;
    if ((this->mCapacity * 3) / 4 <= newSize)
    {
        this->mCapacity = newCapacity;
        shouldErase = true;
    }

    // size down
    if (this->mCapacity / 4 >= newSize)
    {
        this->mCapacity = newCapacity;
        shouldErase = true;
    }

    if (shouldErase)
    {
        T* save = this->mData;
        this->copy(save);
        
        delete[] save;
    }
}

template<typename T>
void Vector<T>::copy(T* data)
{
    this->mData = new T[this->mCapacity];
    for(size_t i = 0; i < this->mSize; i++)
    {
        this->mData[i] = data[i];
    }
}

template <typename T>
Vector<T>::Vector()
    : mCapacity(DEFAULT_CAPACITY),
      mSize(0)
{
    this->mData = new T[this->mCapacity];
}

template <typename T>
Vector<T>::Vector(size_t capacity)
    : mCapacity(capacity),
      mSize(0)
{
    this->mData = new T[this->mCapacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
    : mCapacity(other.mCapacity),
      mSize(other.mSize)
{
    this->copy(other.mData);
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other)
    : mCapacity(other.mCapacity),
      mSize(other.mSize)
{
    this->mData = other.mData;
    other.mData = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        delete[] this->mData;
        this->mCapacity = other.mCapacity;
        this->mSize = other.mSize;
        this->copy(other.mData);
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
    if (this != &other)
    {
        delete[] this->mData;
        this->mCapacity = other.mCapacity;
        this->mSize = other.mSize;
        this->mData = other.mData;
        other.mData = nullptr;
    }

    return *this;
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] this->mData;
}

template <typename T>
size_t Vector<T>::getCapacity() const
{
    return this->mCapacity;
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return this->mSize;
}

template <typename T>
T Vector<T>::getAt(size_t index) const
{
    if (index >= this->mSize)
    {
        throw "Index out of bounds!\n";
    }

    return this->mData[index];
}

template <typename T>
T& Vector<T>::getAt(size_t index)
{
    if (index >= this->mSize)
    {
        throw "Index out of bounds!\n";
    }

    return this->mData[index];
}

template <typename T>
bool Vector<T>::isEmpty() const
{
    return this->mSize == 0;
}

template <typename T>
T Vector<T>::getFirst() const
{
    return this->getAt(0);
}

template <typename T>
T Vector<T>::getLast() const
{
    return this->getAt(this->mSize - 1);
}

template <typename T>
void Vector<T>::assign(size_t n, const T& x)
{
    this->mSize = n;
    this->resize(n, (n*4)/3);

    for(size_t i = 0; i < n; i++)
    {
        this->mData[i] = x;
    }
}

template <typename T>
void Vector<T>::pushBack(const T& x)
{
    this->mSize++;
    this->resize(this->mSize, this->mCapacity * 2);
    this->mData[this->mSize - 1] = x;
}

template <typename T>
void Vector<T>::popBack()
{
    --this->mSize;
    this->resize(this->mSize, this->mCapacity / 2);
}

template <typename T>
void Vector<T>::removeAt(size_t index)
{
    if (index >= this->mSize)
    {
        throw "Index out of bounds!\n";
    }

    for(size_t i = index; i < this->mSize - 1; i++)
    {
        this->mData[i] = this->mData[i + 1];
    }

    --this->mSize;
    this->resize(this->mSize, this->mCapacity / 2);
}

template <>
void Vector<char*>::removeAt(size_t index)
{
    if (index >= this->mSize)
    {
        throw "Index out of bounds!\n";
    }

    for(size_t i = index; i < this->mSize - 1; i++)
    {
        this->mData[i] = this->mData[i + 1];
    }

    delete[] this->mData[this->mSize - 1];
    this->mSize--;
    this->resize(this->mSize, this->mCapacity / 2);
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) const
{
    if (this->mSize == other.mSize)
    {
        for(size_t i = 0; i < this->mSize; i++)
        {
            if (this->mData[i] != other.mData[i])
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
    Vector<T> result(*this);

    for(size_t i = 0; i < other.mSize; i++)
    {
        result.pushBack(other.mData[i]);
    }

    return result;
}

template <typename T>
T Vector<T>::operator[](size_t index) const
{
    return this->getAt(index);
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    return this->getAt(index);
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Vector<U>& other)
{
    out << other.mSize << ' ';
    for(size_t i = 0; i < other.mSize; i++)
    {
        out << other.mData[i] << ' ';
    }

    return out;
}

template<typename U>
std::istream& operator>>(std::istream& in, Vector<U>& other)
{
    in >> other.mSize; 
    for(size_t i = 0; i < other.mSize; i++)
    {
        in >> other.mData[i];
    }

    return in;
}