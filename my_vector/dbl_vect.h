#ifndef DBL_VECT_H
#define DBL_VECT_H

#include <ostream>
#include <cassert>

struct dbl_vect {
  explicit dbl_vect(int n = 10);
  dbl_vect(const dbl_vect&);
  ~dbl_vect() { delete[] p; }
  double& at(int);		/* accessor AND mutator */
  double& operator[](int);	/* same with traditional array access */
  double get(int) const;	/* accessor */
  int size() const { return vect_size; }
private:
  double* p;
  int vect_size;
};

std::ostream& operator<<(std::ostream&, const dbl_vect&);

#endif // DBL_VECT_H
