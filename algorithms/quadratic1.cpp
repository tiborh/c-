#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

int main()
{
  int how_many = 0;
  double a, b, c, discr, sq_disc, root1, root2;
  a = b = c = discr = sq_disc = 0.0;
  complex<double> complex_root1, complex_root2, complex_sq_disc;

  cout << "\nCalculating roots of quadratic equation.";
  cout << "\n(a * x^2 + b * x + c == 0)";

  cout << "\nHow many sets? ";
  cin >> how_many;
  cout << "(" << how_many << ")\n";

  for(int i = 0; i < how_many; i++)
    {
      root1 = root2 = 0.0;
      cin >> a >> b >> c;
      cout << "(a,b,c): (" << a << "," << b << "," << c << ")\n";
      discr = b * b - 4 * a * c;
      if ((discr > 0) && (sq_disc = sqrt(discr)))
	{
	  root1 = (-b + sq_disc) / (2 * a);
	  root2 = (-b - sq_disc) / (2 * a);
	}
      else if (discr < 0)
	{
	  complex_sq_disc = sqrt(discr);
	  complex_root1 = (-b + sq_disc) / (2 * a);
	  complex_root2 = (-b - sq_disc) / (2 * a);
	  cout << "complex root1 == " << complex_root1 << endl;
	  cout << "complex root2 == " << complex_root2 << endl;
	}
      else
	root1 = root2 = -b / (2 * a);
      if (discr >= 0)
	{
	  cout << "root1 == " << root1 << endl;
	  cout << "root2 == " << root2 << endl;
	}
    }


  return 0;
}
