#ifndef HEADER_2CEB99229E534865
#define HEADER_2CEB99229E534865

#ifndef PERSON_H
#define PERSON_H

class Person
{
    public:
        Person(char*, char*, char*); // name birthday address
        int* parse_birthday_str(char*);
        char* get_name() const;
        char* get_address() const;
        char* get_birthday() const;
        virtual ~Person();
    protected:
    private:
        char* name;
        int* birthday;
        char* address;
};

#endif // PERSON_H

#endif // header guard
