#include <iostream>
#include <string>
#include <cmath>
#include "item.h"
#include "pair.h"
#include "Array.h"

using namespace std;

template<class T>
void testItem(Item<T> item1, const T sample)
{
    cout << "After creation: " << item1 << endl;
    item1.SetData(sample);
    cout << "After setting data: " << item1 << endl;
    T someData = item1.GetData();
    cout << "Gotten data: " << someData << endl;
    cout << '\n';
}

int main()
{
    Item<int> item1;
    testItem(item1,120);

    Item<double> item2;
    testItem(item2,3.14);

    Item<string> item3;
    string teststr = "something";
    testItem(item3,teststr);

    // Assume as Point struct
    Pair<> point1; //by default, the first is int and the second is of the same type as the first
    cout << "point1 is: "  << point1 << " (with empty constructor)\n";

    // Logically same as X and Y members
    point1.assign(10,20,"point1");
    //point1.first = 10;
    //point1.second = 20;
    cout << "point1 is: "  << point1 << "\n";

    Pair<int, double> SqRoot(90,9.4868329,"SqRoot");
    //SqRoot.first = 90;
    //SqRoot.second = 9.4868329;
    cout << "The square root of "  << SqRoot.getFirst() << " is " << SqRoot.getSecond() << ".\n";

    Pair<> point2(12,40);
    Pair<> point3(point1);
    cout << "point2 is: "  << point2 << "\n";
    cout << "point3 is: "  << point3 << ", that is, a copy of point1\n";

    cout << "Is point1 equal to point2? " << boolalpha << (point1==point2) << '\n';
    cout << "Is point1 equal to point3? " << boolalpha << (point1==point3) << '\n';
    cout << "Is point1 is less than point2? " << boolalpha << (point1<point2) << '\n';
    cout << "Is point1 is less than point3? " << boolalpha << (point1<point3) << '\n';
    cout << "Is point2 is greater than point1? " << boolalpha << (point2>point1) << '\n';
    cout << "Is point1 is greater than point3? " << boolalpha << (point1>point3) << '\n';
    cout << "Is point2 is less than or equal to point1? " << boolalpha
         << (point2<=point1) << '\n';
    cout << "Is point1 is less than or equal to point3? " << boolalpha
         << (point1<=point3) << '\n';
    cout << "Is point1 is greater than or equal to point2? " << boolalpha
         << (point1>=point2) << '\n';
    cout << "Is point1 is greater than or equal to point3? " << boolalpha
         << (point1>=point3) << '\n';

    cout << "\nStarting new test series:\n\t";
    Pair<> point4 = Pair<>(1,2,"point4");
    //cout << "point4 is: "  << point4 << "\n";
    point4.printDatLine();
    /*cout << "Name to point4 again: ";
    point4.setName("point4");
    point4.printDatLine();*/

    Pair<> point5;
    cout << "After creation of a new one:\n\t";
    point5.printDatLine();
    point5 = point4;
    //cout << "point5 is: "  << point5 << "\n";
    cout << "After made equal to point4:\n\t";
    point5.printDatLine();

    cout << "To prove that point5 is not an alias of point4,\n";
    cout << " point5 is changed and then both are printed out.\n";
    point5.assign(3,4,"point5");
    cout << "After assignment:\n";
    cout << "\t"; point5.printDatLine();
    cout << "\t"; point4.printDatLine();

    cout << "And now the swap(point4,point5):\n Caution! Names are also swapped!\n";
    swap(point4,point5);
    cout << "\t"; point4.printDatLine();
    cout << "\t"; point5.printDatLine();
    swap(point4,point5);
    cout << "Reswapped: \n";
    cout << "\t"; point4.printDatLine();
    cout << "\t"; point5.printDatLine();
    point4.setName("point4");
    point5.setName("point5");
    cout << "Renamed: \n";
    cout << "\t"; point4.printDatLine();
    cout << "\t"; point5.printDatLine();

    cout << "Same with method call point4.swap(point5):\n";
    point4.swap(point5);
    cout << "\t"; point4.printDatLine();
    cout << "\t"; point5.printDatLine();

    Pair<> point6 = point4 + point5;
    cout << "point6 = point4 + point5\n";
    cout << "\t"; point6.printDatLine();

    Pair<> point7 = point4 - point5;
    cout << "point7 = point4 - point5\n";
    cout << "\t"; point7.printDatLine();

    Pair<> point8 = Pair<>(1,2,"eight");
    cout << "New point with name: " << point8.getName() << "\n";
    cout << "\t"; point8.printDatLine();

    Pair<> point9 = Pair<>(point8);
    cout << "New point after copying it from point8.\n\t";
    point9.printDatLine();
    point9.setName("point9");
    cout << "After setting its name:\n\t";
    point9.printDatLine();

    cout << "After setting it to inverse:\n\t";
    point9.inverse();
    point9.printDatLine();

    cout << "\nArray Tests:\n";
    Array<> my_array0; //default is integer
    cout << my_array0 << endl;
    Array<> my_array1(3);
    cout << my_array1 << endl;
    Array<> my_array2(1,1);
    cout << my_array2 << endl;
    cout << "First and last element: " << my_array2[0] << " " << my_array2[my_array2.size()-1] << endl;
    cout << "Sum of elements: " << my_array2.Accumulate() << endl;
    cout << "Average of elements: " << my_array2.Average() << endl;
    my_array2[5] = 100;
    cout << my_array2 << endl;
    try {
        my_array2[100] = 5;
    } catch (const char* e) {
        cout << e << endl;
    }
    //cout << "\nArray constructor now allows initialisation:\n";
    //Array<std::string,ArraySize> my_array2("a","ba");
    //cout << my_array2 << endl;
    cout << "Creating an array greater than the default size:\n";
    Array<int,100> my_array3(0,1);
    cout << my_array3 << endl;
    cout << "Get the size of the array: " << my_array3.size() << endl;

    Pair<int,Pair<> > complex_pair1;
    complex_pair1.setFirst(1);
    complex_pair1.setSecond(Pair<>(2,3));
    cout << "\nComplex pair test:\n\t";
    cout << complex_pair1 << endl;

    Array<Pair<>> array_of_pairs1(Pair<>(1,2));
    cout << "\nArray of pairs:\n\t";
    cout << array_of_pairs1 << endl;

    Array<Pair<int,Pair<>>> array_of_pairs2(Pair<int,Pair<> >(1,Pair<>(2,3)));
    cout << "\nArray of complex pairs:\n\t";
    cout << array_of_pairs2 << endl;

    Array<Pair<int,Pair<int,double>>> array_of_pairs3(Pair<int,Pair<int,double> >(1,Pair<int,double>(2,acos(-1))));
    cout << "\nArray of complex heterogeneous pairs:\n\t";
    cout << array_of_pairs3 << endl;
    cout << "After changing a single array element:\n";
    array_of_pairs3[4] = Pair<int,Pair<int,double> >();
    cout << array_of_pairs3 << endl;

    cout << "\nWhat about a pair of Array's?\n";
    Pair<Array<int>,Array<double> > my_pair2(Array<int>(1,2),Array<double>(acos(-1),acos(-1)));
    cout << my_pair2 << endl;
    cout << "After changing first of the pair:\n";
    my_pair2.setFirst(Array<>());
    cout << my_pair2 << endl;

    cout << '\n';
    Array<Pair<int,Pair<int,double>>> array_of_pairs4;
    array_of_pairs4 = array_of_pairs3;
    cout << "copy test on array of pairs: " << array_of_pairs3 << '\n';
    cout << "copied to array_of_pairs4: " << array_of_pairs4 << '\n';
    array_of_pairs4[0] = Pair<int,Pair<int,double> >(1,1.2);
    cout << "array_of_pairs4 after the change (in first element): " << array_of_pairs4 << '\n';
    cout << "check if array_of_pairs3 is independent: " << array_of_pairs3 << '\n';
    cout << "getting: array_of_pairs4[1].getSecond(): " << array_of_pairs4[1].getSecond() << '\n';
    array_of_pairs4[1].setSecond(Pair<int,double>(1,1.2));
    cout << "getting: array_of_pairs4[1].getSecond() (after change): " << array_of_pairs4[1].getSecond() << '\n';
    cout << "getting: array_of_pairs3[1].getSecond() (to check): " << array_of_pairs3[1].getSecond() << '\n';

    Array<Array<int,3>>* array_of_arrays1 = new Array<Array<int,3>>();
    cout << array_of_arrays1[0] << '\n';
    cout << array_of_arrays1[1] << '\n';//problem!!!
    cout << array_of_arrays1;//problem!!!

    return 0;
}
