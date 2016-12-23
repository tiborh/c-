#include <iostream>
#include <ctime>

using namespace std;

int main() {
  enum week {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

  static union {		// a static anonymous union's members are available outside the union
    int i;
    week w;
  };

  time_t now = time(0);
  i = localtime(&now)->tm_wday;
  
  if (w == Sat || w == Sun)
    cout << " 週末です！ \n";
  else
    cout << " 平日です。（ひらび） \n";

  return 0;
}
