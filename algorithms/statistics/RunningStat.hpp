#ifndef RUNNINGSTAT_H_INCLUDED
#define RUNNINGSTAT_H_INCLUDED

#include <cmath>

class RunningStat {
public:
  RunningStat() : m_n(0) {}
  void Clear() { m_n = 0; }
  void Push(double);
  int NumDataValues() const { return m_n; }
  double Mean() const { return (m_n > 0) ? m_newM : 0.0; }
  double Variance() const {
    return ( (m_n > 1) ? m_newS/(m_n - 1) : 0.0 );
  }
  double StandardDeviation() const { return sqrt( Variance() ); }

private:
  int m_n;
  double m_oldM, m_newM, m_oldS, m_newS;
};

#endif //RUNNINGSTAT_H_INCLUDED

// Local Variables:
// mode: c++
// End:
