// person.hxx
//

#ifndef PERSON_HXX
#define PERSON_HXX

#include <string>
#include <odb/core.hxx>

#pragma db object

class person
{
public:
  /*
    person (const std::string& first,
          const std::string& last,
          unsigned short age);
  */
  person (const std::string first,
          const std::string last,
          unsigned short age);

  const std::string& get_first () const;
  void set_first (const std::string&);

  const std::string& get_last () const;
  void set_last (const std::string&);

  const unsigned short& get_age () const;
  void set_age (const unsigned short&);

  const std::string& email () const;
  void email (const std::string&);

private:
  person () {}
  friend class odb::access;
  std::string first_;
  std::string last_;
  unsigned short age_;
  //std::string email_;
#pragma db id auto
  unsigned long id_;
};

#pragma db object(person)
  //#pragma db member(person::email_) id

#endif // PERSON_ODB_HXX
