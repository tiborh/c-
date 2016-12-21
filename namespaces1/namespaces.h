#ifndef NAMESPACES_H_INCLUDED
#define NAMESPACES_H_INCLUDED

namespace Q {
  namespace V { // V is a member of Q, and is fully defined within Q
// namespace Q::V { // C++17 alternative to the above two lines
    class C { void m(); }; // C is a member of V and is fully defined within V
                           // C::m is only declared
    void f(); // f is a member of V, but is only declared here
  }
  void V::f() // definition of V's member f outside of V
              // f's enclosing namespaces are still the global namespace, Q, and Q::V
  {
      extern void h(); // This declares ::Q::V::h
  }
  void V::C::m() // definition of V::C::m outside of the namespace (and the class body)
                 // enclosing namespaces are the global namespace, Q, and Q::V
  {
  }
}


#endif // NAMESPACES_H_INCLUDED
