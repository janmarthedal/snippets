/*
 * File:   snippets/double_precision_multiplication.hpp
 * Author: Jan Marthedal Rasmussen
 *
 * Created 2011-11-09 10:00Z
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_INTEGER_SQUARE_ROOT_HPP
#define _SNIPPETS_INTEGER_SQUARE_ROOT_HPP

#include <kanooth/snippets/integer_binary_logarithm.hpp>

template <typename T>
T integer_square_root(const T n)
{
  if (n <= 1) return n;
  T a = 1 << (integer_binary_logarithm(n) / 2 + 1), b;
  while (true) {
    b = (a + n / a) >> 1;
    if (b >= a) return a;
    a = (b + n / b) >> 1;
    if (a >= b) return b;
  }
}

#endif // _SNIPPETS_INTEGER_SQUARE_ROOT_HPP

