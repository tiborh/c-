#include <iostream>
#include <cstring>
#include "person.h"
#include "Student.h"

using namespace std;

int main()
{
    char* test_name = new char[64];
    strcpy(test_name,"John Doe");
    char* test_birthday = new char[11];
    strcpy(test_birthday,"1980 01 05");
    char* test_address = new char[128];
    strcpy(test_address,"12 Chestnut Street");

    Person sample_person(test_name,test_birthday,test_address);

    cout << "Sample person:" << endl;
    cout << sample_person.get_name() << endl;
    cout << sample_person.get_birthday() << endl;
    cout << sample_person.get_address() << '\n' << endl;

    Student sample_student(sample_person.get_name(),
                           sample_person.get_birthday(),
                           sample_person.get_address(),
                           1,4.9,Student::freshman);

    cout << "Sample student:" << endl;
    cout << sample_student.get_name() << endl;
    cout << sample_student.get_birthday() << endl;
    cout << sample_student.get_address() << endl;
    cout << sample_student.get_id() << endl;
    cout << sample_student.get_pga() << endl;
    cout << sample_student.get_year()+1 << endl;

    delete test_name;
    delete test_birthday;
    delete test_address;
    return 0;
}
