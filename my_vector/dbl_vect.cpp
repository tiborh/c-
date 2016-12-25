#include "dbl_vect.h"

dbl_vect::dbl_vect(int n) : vect_size(n) {
  assert(n > 0);
  p = new double[vect_size];
  assert(p != 0);
}
dbl_vect::dbl_vect(const dbl_vect& other): vect_size(other.size()) {
  assert( other.size() > 0);
  p = new double[vect_size];
  assert(p != 0);
  for (int i = 0; i < vect_size; ++i) {
    p[i] = other.get(i);
  }
}
double& dbl_vect::at(int i) {
  assert (i >= 0 && i < vect_size);
  return p[i];
}
double dbl_vect::get(int i) const {
  assert (i >= 0 && i < vect_size);
  double out = p[i];
  return out;
}
double& dbl_vect::operator[](int i) {
  return at(i);
}
std::ostream& operator<<(std::ostream& os, const dbl_vect& dv) {
  int size = dv.size();
  for (int i = 0; i < size; ++i)
    os << dv.get(i) << " ";
  return os;
}
