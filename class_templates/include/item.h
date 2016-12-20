#ifndef ITEM_H
#define ITEM_H
#include <iostream>

template<typename T>
class Item
{
    private:
        T Data;
    public:
        Item() : Data( T() )
        {}

        void SetData(T nValue)
        {
            Data = nValue;
        }

        T GetData() const
        {
            return Data;
        }

        friend std::ostream& operator<<(std::ostream& out, Item an_item)
        {
            return (out << an_item.Data);
        }
};

#endif // ITEM_H
