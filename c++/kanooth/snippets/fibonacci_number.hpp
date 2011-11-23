/*
 * Author: Jan Marthedal Rasmussen
 * See   : http://kanooth.com/blog/2011/03/evaluation-of-fibonacci-numbers.html
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_FIBONACCI_NUMBER_HPP
#define _SNIPPETS_FIBONACCI_NUMBER_HPP

template <typename T>
void set_pair(T& x, T& y, T a, T b) { x = a; y = b; }

template <typename R>
struct fibonacci_number_evaluator {
  R operator()(unsigned n) const
  {
    if (n <= 1) return n;
    R a=1, b=0, p=0, q=1;
    while (n > 1) {
      if (n & 1)
        set_pair(a, b, b*q + a*q + a*p, b*p + a*q);
      set_pair(p, q, p*p + q*q, (2*p + q)*q);
      n >>= 1;
    }
    return b*p + a*q;
  }
};

#endif // _SNIPPETS_FIBONACCI_NUMBER_HPP

