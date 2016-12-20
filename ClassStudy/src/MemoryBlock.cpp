#include "MemoryBlock.h"

MemoryBlock::MemoryBlock(size_t length)
    : _length(length)
    , _data(new int[length])
{
    srand(time(NULL));
    std::cout << "\nIn MemoryBlock(size_t). length = "
              << _length << "." << '\n';
}

MemoryBlock::MemoryBlock(const MemoryBlock& other)
    : _length(other._length)
    , _data(new int[other._length])
{
    std::cout << "\nIn MemoryBlock(const MemoryBlock&). length == "
              << other._length << ". Copying resource." << '\n';

    std::copy(other._data, other._data + _length, _data);
}

void MemoryBlock::init()
{
    for(size_t i = 0; i < _length; ++i)
        *(_data+i) = rand() % MAXVAL;

}

MemoryBlock::~MemoryBlock()
{
    std::cout << "\nIn ~MemoryBlock(). length = "
              << _length << ".";

    if (_data != NULL)
    {
        std::cout << "\n Deleting resource.";
        // Delete the resource.
        delete[] _data;
    }

    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const MemoryBlock &other)
{
    os << '(';
    for(size_t i = 0; i < other._length; ++i)
    {
        os << *(other._data + i);
        os << ((i < other._length - 1) ? ' ' : ')');
    }
    if (other._length == 0)
        os << ')';

    return os;
}
