/*
 * Author: Jan Marthedal Rasmussen
 * See   : http://kanooth.com/snippets/gcd_stein.html
 *
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_GCD_STEIN_HPP
#define _SNIPPETS_GCD_STEIN_HPP

#include <kanooth/snippets/trailing_binary_zeros.hpp>

template <typename T>
inline T minimum(T a, T b)
{
	return a < b ? a : b;
}

template <typename NUM>
inline unsigned shift_to_uneven(NUM& n)
{
  unsigned shift = trailing_binary_zeros(n);
	n >>= shift;
  return shift;
}

/* Computes the greatest common divisor of two    *
 * non-negative integers using Stein's algorithm. *
 * NUM must be an unsigned integer.               */
template <typename NUM>
NUM gcd_stein(NUM a, NUM b)
{
  if (!a) return b;
  if (!b) return a;
  unsigned shift = minimum(shift_to_uneven(a), shift_to_uneven(b));
  while (a != b) {
    if (a > b) {
      a -= b;
      shift_to_uneven(a);
    } else {
      b -= a;
      shift_to_uneven(b);
    }
  }
  return a <<= shift;
}

#endif // _SNIPPETS_GCD_STEIN_HPP

