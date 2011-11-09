/*
 * File:   snippets/gcd_stein.hpp
 * Author: Jan Marthedal Rasmussen
 *
 * Created 2011-11-09 14:27Z
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_GCD_STEIN_HPP
#define _SNIPPETS_GCD_STEIN_HPP

template <typename NUM>
inline unsigned shift_to_uneven(NUM& n)
{
  unsigned shift = 0;
  while (!(n & 1)) {
    n >>= 1;
    ++shift;
  }
  return shift;
}

template <typename NUM>
NUM gcd_stein(NUM a, NUM b)
{
  if (!a) return b;
  if (!b) return a;
  unsigned shift = std::min(shift_to_uneven(a), shift_to_uneven(b));
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

