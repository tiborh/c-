#include "Student.h"

Student::Student(char* name_str,
                 char* birthday_str,
                 char* address_str,
                 int in_id,
                 double in_gpa,
                 year in_year):Person(name_str,birthday_str,address_str)
{
    student_id = in_id;
    gpa = in_gpa;
    y = in_year;
}

int Student::get_id()
{
    return student_id;
}

double Student::get_pga()
{
    return gpa;
}

Student::year Student::get_year()
{
    return y;
}

Student::~Student()
{
    //dtor
}
