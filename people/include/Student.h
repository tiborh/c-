#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

class Student : public Person
{
    public:
        enum year {freshman, sophomore, junior, senior, graduate};
        Student(char*,char*,char*,int,double,year);
        int get_id();
        double get_pga();
        year get_year();
        virtual ~Student();
    protected:
    private:
        int student_id;
        double gpa;
        year y;
};

#endif // STUDENT_H
