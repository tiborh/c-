#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <sstream>

const unsigned _size = 10;

template<typename T = int, unsigned SIZE = _size> //defaults have been set
class Array
{
    public:
        Array(T value = T(), T stepping = T(0))
        {
            for(unsigned int nIndex = 0; nIndex < SIZE; ++nIndex)
            {
                TheArray[nIndex] = value;
                value += stepping;
            }
        }

        int size() { return SIZE; }

        T Accumulate() const
        {
          T sum = T();
          for(unsigned int nIndex = 0; nIndex < SIZE; ++nIndex)
          {
             sum += TheArray[nIndex];
          }
          return sum;
        }

        double Average() const
        {
            return static_cast<double>((*this).Accumulate())/SIZE;
        }

        // getter
        T operator[](unsigned int nIndex) const
        {
          if (nIndex>=0 && nIndex<SIZE)
            return TheArray[nIndex];

          return T();
        }

        // setter
        T& operator[](unsigned int nIndex)
        {
            if (nIndex>=0 && nIndex<SIZE)
                return TheArray[nIndex];
            else
                throw "Out of bounds exception";
        }

        friend std::ostream& operator<<(std::ostream& out, const Array<T,SIZE>& an_array)
        {
            std::stringstream outstr;
            outstr << "{";
            for(unsigned int i = 0; i < SIZE; ++i)
            {
                //outstr += std::to_string(i) + ": ";
                outstr << an_array[i];
                if (i < SIZE-1)
                    outstr << " ";
            }
            outstr << "}";
            std::string outstring = outstr.str();
            return (out << outstring);
        }

        Array<T,SIZE> operator+=( const Array<T,SIZE>& other )
        {
          for(int i = 0; i < SIZE; ++i)
            TheArray[i]+=other[i];

          return *this;
        }

        protected:
        private:
            T TheArray[SIZE];
};

#endif // ARRAY_H
