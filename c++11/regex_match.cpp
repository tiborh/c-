// regex_match example
#include <iostream>
#include <string>
#include <regex>

int main ()
{

  //first
  if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
    std::cout << "string literal matched\n";

  const char cstr[] = "subject";
  std::string s ("subject");
  std::regex e ("(sub)(.*)");

  //same as first
  if (std::regex_match (s,e))
    std::cout << "string object matched\n";

  //could be a subrange too
  if ( std::regex_match ( s.begin(), s.end(), e ) )
    std::cout << "range matched\n";


  std::cmatch cm;    // same as std::match_results<const char*> cm;
  std::regex_match (cstr,cm,e);
  std::cout << "string literal with " << cm.size() << " matches\n";
  std::cout << "\tcm[0]: " << cm[0] << ", cm[1]: " << cm[1] << ", cm[2]: " << cm[2] << '\n';

  std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
  std::regex_match (s,sm,e);
  std::cout << "string object with " << sm.size() << " matches\n";
  std::cout << "\tsm[0]: " << sm[0] << ", sm[1]: " << sm[1] << ", sm[2]: " << sm[2] << '\n';

  std::regex_match ( s.cbegin(), s.cend(), sm, e);
  std::cout << "range with " << sm.size() << " matches\n";
  std::cout << "\tsm[0]: " << sm[0] << ", sm[1]: " << sm[1] << ", sm[2]: " << sm[2] << '\n';

  // using explicit flags:
  std::regex_match ( cstr, cm, e, std::regex_constants::match_default );

  std::cout << "the matches were: ";
  for (unsigned i=0; i<sm.size(); ++i) {
    std::cout << "[" << sm[i] << "] ";
  }

  std::cout << std::endl;

  return 0;
}
