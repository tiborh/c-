#ifndef PAIR_H
#define PAIR_H
#include <cmath>
#include <string>
//#include "class_templates.h"

//struct Point { int x; int y; };
//struct Money { int Dollars; int Cents; };

// Instead of the above two, the following is used.
// This is also a Class definition
template<typename Type1 = int, typename Type2 = Type1>
struct Pair
{
    private:
    std::string name;
    // In public area, since we want the client to use them directly.
    Type1 first;
    Type2 second;

    public:
    // The following given default constructor would initialize
    // both members to their default values, as per data type of Type1 and Type2:
    //Pair() : first(Type1()), second(Type2()) {}

    // Following is a parametrised constructor taking Type1 and Type2
    // to initialize values of first and second:
    Pair(const Type1& t1 = Type1(), const Type2& t2 = Type2(), std::string aName = std::string()) :
        first(t1), second(t2) {
            //name = "c1_" + aName;
            name = aName;
        }

    // Following is a copy-constructor which would copy one Pair object
    // from another Pair object, of exactly same type:
    Pair(const Pair<Type1, Type2>& OtherPair) :
        first(OtherPair.first), second(OtherPair.second)
        {
            //name = "c2_" + OtherPair.name;
            name = "";
        }

    void swap(Pair<Type1, Type2>& Other)
    {
        std::string name1 = name;
        std::string name2 = Other.name;
        Pair<Type1, Type2> temp = Other;
        Other = *this;
        *this = temp;
        name = name1;
        Other.name = name2;
    }

    void assign(Type1 newfirst, Type2 newsecond, std::string aName = std::string())
    {
        first = newfirst;
        second = newsecond;
        if (0 != aName.compare("") && (0 == name.compare("") || 0 != name.compare(aName)))
            name = aName;
    }

    Type1 getFirst() { return first; }
    void setFirst( Type1 newVal ) { first = newVal; }
    Type2 getSecond() { return second; }
    void setSecond( Type2 newVal ) { second = newVal; }
    std::string getName() { return name; }
    void setName(std::string aName) { name = aName; }

    void inverse() { first = -first; second = -second; }

    void printDatLine()
    {
        std::cout << "\"" << name << "\" is " << *this << std::endl;
    }

    bool operator == (const Pair<Type1, Type2>& Other) const
    {
        return first == Other.first && second == Other.second;
    }

    bool operator < (const Pair<Type1, Type2>& Other) const
    {
        return sqrt(first*first + second*second) <
               sqrt(pow(Other.first,2) + pow(Other.second,2));
    }

    bool operator > (const Pair<Type1, Type2>& Other) const
    {
        return sqrt(first*first + second*second) >
               sqrt(pow(Other.first,2) + pow(Other.second,2));
    }

    bool operator <= (const Pair<Type1, Type2>& Other) const
    {
        return sqrt(first*first + second*second) <=
               sqrt(pow(Other.first,2) + pow(Other.second,2));
    }

    bool operator >= (const Pair<Type1, Type2>& Other) const
    {
        return sqrt(first*first + second*second) >=
               sqrt(pow(Other.first,2) + pow(Other.second,2));
    }

    Pair<Type1,Type2>& operator=( const Pair<Type1,Type2>& other ) {
      first = other.first;
      second = other.second;
      name = "copyof_" + other.name;
      return *this;
    }

    Pair<Type1,Type2> operator+=( const Pair<Type1,Type2>& other ) {
      first += other.first;
      second += other.second;
      name = name + "+" + other.name;
      return *this;
    }

    Pair<Type1,Type2> operator+( const Pair<Type1,Type2>& other ) {
      return Pair<Type1,Type2>((first + other.first),(second + other.second),(name + "+" + other.name));
    }

    Pair<Type1,Type2> operator-( const Pair<Type1,Type2>& other ) {
      return Pair<Type1,Type2>((first - other.first),(second - other.second),(name + "-" + other.name));
    }

    friend std::ostream& operator<<(std::ostream& out, const Pair<Type1,Type2>& a_pair)
    {
        return (out << "(" << a_pair.first << "," << a_pair.second << ")");
    }
};

#endif // PAIR_H
