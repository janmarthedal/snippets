/*
 * File:   snippets/double_precision_multiplication.hpp
 * Author: Jan Marthedal Rasmussen
 *
 * Created 2011-11-09 08:07Z
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_DOUBLE_PRECISION_MULTIPLICATION_HPP
#define _SNIPPETS_DOUBLE_PRECISION_MULTIPLICATION_HPP

#include <kanooth/snippets/type_traits.hpp>

template <typename T>
void double_precision_multiplication(const T u, const T v, const T a1, const T a2,
                                     T& low, T& high)
{
  // TODO assert(!is_signed<T>::value)
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

