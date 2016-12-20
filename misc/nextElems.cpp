#include <iostream>
#include <cassert>

using namespace std;

int next(int x) { return ++x; }
int f(int x) { return --x; }
int g(int x) { return next(next(x)); }
int add(int x, int y) { return x + y; }
bool equal(int x, int y) { return(x == y); }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { assert(y != 0); return x / y; }
int mod(int x, int y) { return x % y; }

//Q1 part
int prev(int x) { return --x; }
//int s(int n) { return prev(add(s(n), next(multiply(n, next(next(0)))))); }
//bool c(int n) { return equal(s(n), add(multiply(next(next(3)), n) , next(-5))); }

//Binary representation, Q1
int binOps(int a, int b)
{
  int c = 0;
  while (b != 0)
    {
      if ((b&1) != 0)
        c = c + a;
      a>>=1;
      b<<=1;
    }
  return c;
}

int shifting(int n)
{
  int nsaved = n;
  n <<= 5;
  n -= nsaved;
  return n;
}

int flipBits(int a) { return -(~a); }

//Graded quiz
int myminus(int n) { return -n; }
int myminus(int n, int m) { return n-m; }
//int s(int n) { return prev(add(n,next(multiply(n, next(next(0)))))); }
int s(int n) { return n*n; }

int main()
{
  int n = 7;
  int m = 2;
  cout << "Topic: Natural numbers\n";
  cout << "n: " << n << endl;
  cout << "m: " << m << endl;
  cout << "f(n): " << f(n) << endl;
  cout << "g(n): " << g(n) << endl;
  cout << "next(n): " << next(n) << endl;
  cout << "f(g(n)) == g(f(n)): " <<  (f(g(n)) == g(f(n))) << endl;
  cout << "g(f(next(n)) == next(next(n)): " << ( g(f(next(n))) == next(next(n)) ) << endl;
  cout << "f(g(g(n)) == next(next(next(next(n)))): " << ( f(g(g(n))) == next(next(next(next(n)))) ) << endl;
  cout << "g(f(0)) == next(0): " << (g(f(0)) == next(0)) << endl;
  cout << "add(next(m),n) == next(add(m,n)): " << ( add(next(m),n) == next(add(m,n)) ) << endl;
  cout << "equal(add(0,n),n): " << equal(add(0,n),n) << endl;
  cout << "equal(n,m): " << equal(n,m) << endl;
  cout << "equal(0,0) == true: " << (equal(0,0) == true) << endl;
  cout << "equal(n,next(n)) == false: " << (equal(n,next(n)) == false) << endl;
  cout << "equal(0,next(n)) == false: " << (equal(0,next(n)) == false) << endl;
  cout << "equal(next(n),0) == false: " << (equal(next(n),0) == false) << endl;
  cout << "equal(next(n),next(m)) == equal(n,m): " <<  ( equal(next(n),next(m)) == equal(n,m) ) << endl;
  cout << "multiply(0,n) == 0: " << (multiply(0,n) == 0) << endl;
  cout << "multiply(next(m),n) == add(n,multiply(m,n)): " << ( multiply(next(m),n) == add(n,multiply(m,n)) ) << endl;
  cout << "divide(n,m): " << divide(n,m) << endl;
  cout << "divide(m,n): " << divide(m,n) << endl;
  cout << "mod(n,m): " << mod(n,m) << endl;
  cout << "mod(m,n): " << mod(m,n) << endl;
  cout << "n == multiply(divide(n,m),m) + mod(n,m): " << ( n == multiply(divide(n,m),m) + mod(n,m) ) << endl;
  cout << "equal(add(n,m),add(m,n)): " << equal(add(n,m),add(m,n)) << endl;

  /* Segmentation fault, endless recursion
  cout << "Exercise: Q1\n";
  for (int i = 0; i < 8; ++i)
    {
      cout << "n == " << i << endl;
      cout << "s(n) == " << s(i) << endl;
      cout << "c(n) == " << c(i) << endl;
    }
  */

  cout << "n: " << n << endl;
  cout << "m: " << m << endl;
  cout << "flipBits(n): " << flipBits(n) << endl;
  cout << "flipBits(m): " << flipBits(m) << endl;
  cout << "shifting(n): " << shifting(n) << endl;
  cout << "shifting(m): " << shifting(m) << endl;
  cout << "n*31: " << n*31 << endl;
  cout << "m*31: " << m*31 << endl;
  cout << "binOps(n,m): " << binOps(n,m) << endl;

  cout << "next(myminus(next(n))) == next(myminus(n)): " << ( next(myminus(next(n))) == next(myminus(n)) ) << endl;
  cout << "myminus(next(myminus(next(0)))) == 0: " << ( myminus(next(myminus(next(0)))) == 0 ) << endl;
  cout << "next(myminus(0)) == next(next(myminus(next(0))): " << ( next(myminus(0)) == next(next(myminus(next(0)))) ) << endl;
  cout << "next(myminus(next(n))) == myminus(next(n)): " << ( next(myminus(next(n))) == myminus(next(n)) ) << endl;

  cout << "add(s(n),n) == multiply(n,next(n)): " <<  ( add(s(n),n) == multiply(n,next(n)) ) << endl;
  cout << "add(multiply(s(n),m),next(0)) == next(multiply(s(m),n)): " << ( add(multiply(s(n),m),next(0)) == next(multiply(s(m),n)) ) << endl;
  cout << "add(s(n),m) == multiply(next(s(n)),m): " << ( add(s(n),m) == multiply(next(s(n)),m) ) << endl;
  cout << "add(next(n),s(n)) = myminus(s(next(n)),n): " << ( add(next(n),s(n)) == myminus(s(next(n)),n) ) << endl;
  
  return 0;
}
