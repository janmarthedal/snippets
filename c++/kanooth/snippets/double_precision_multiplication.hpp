#ifndef _SNIPPETS_DOUBLE_PRECISION_MULTIPLICATION_HPP
#define _SNIPPETS_DOUBLE_PRECISION_MULTIPLICATION_HPP

#include <snippets/type_traits.hpp>

template <typename T>
void double_mult_add_add(const T u, const T v, const T a1, const T a2, T& low, T& high)
{
  const unsigned int halfbits = kanooth::number_bits<T>::value / 2;
  const T lowmask = (((T) 1) << halfbits) - 1;
  T u1 = u >> halfbits, u0 = u & lowmask;
  T v1 = v >> halfbits, v0 = v & lowmask;
  T r  = u0*v0 + (a1 & lowmask) + (a2 & lowmask);
  T s  = u1*v0 + (a1 >> halfbits) + (r >> halfbits);
  T t  = u0*v1 + (s & lowmask) + (a2 >> halfbits);
  high = u1*v1 + (s >> halfbits) + (t >> halfbits);
  low  = (t << halfbits) | (r & lowmask);
}

#endif // _SNIPPETS_DOUBLE_PRECISION_MULTIPLICATION_HPP

