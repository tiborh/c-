#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int MAXVAL = 100;

class MemoryBlock
{
public:
// Simple constructor that initializes the resource.

    explicit MemoryBlock(size_t length);

    // Destructor.
    ~MemoryBlock();

    // Copy constructor.
    MemoryBlock(const MemoryBlock&);

    // Move constructor by calling move assignment
    MemoryBlock(MemoryBlock&& other):
        _data(nullptr),
        _length(0)
    {
        *this = std::move(other);
    }

    // Copy assignment operator.
    MemoryBlock& operator=(const MemoryBlock& other)
    {
        std::cout << "\nIn operator=(const MemoryBlock&). length = "
                  << other._length << ". Copying resource." << '\n';

        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;

            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
        }
        return *this;
    }

    // Move assignment operator
    MemoryBlock& operator=(MemoryBlock&& other)
    {
        if (this != &other)
        {
            delete[] _data;
        }
        _data = other._data;
        _length = other._length;
        other._data = nullptr;
        other._length = 0;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream&, const MemoryBlock&);

    // fill with random values
    void init();

    // Retrieves the length of the data resource.
    size_t get_length() const
    {
        return _length;
    }

private:
    size_t _length; // The length of the resource.
    int* _data; // The resource.
};

#endif // MEMORYBLOCK_H
