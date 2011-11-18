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

#include <kanooth/snippets/integer_square_root.hpp>
#include <assert.h>
#include <iostream>

#ifdef NDEBUG
#error "NDEBUG set, running file will have no effect"
#endif

int main()
{
  unsigned n=0, next=1, inc=3;

  for (unsigned k = 0; k < 1000; k++) {
    while (n < next) {
      assert(integer_square_root(n) == k);
      n++;
    }
    next += inc;
    inc += 2;
  }

  return 0;
}

