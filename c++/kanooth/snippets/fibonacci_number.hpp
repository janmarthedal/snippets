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

template <typename R>
struct fibonacci_number_evaluator {
  R operator()(unsigned n) const
  {
    if (n <= 1) return n;
    R a=1, b=0, p=0, q=1, tmp;
    while (n != 1) {
      if (n % 2 != 0) {
          tmp = b*q + a*q + a*p;
          b   = b*p + a*q;
          a   = tmp;
      }
      tmp = p*p + q*q;
      q   = (2*p + q)*q;
      p   = tmp;
      n /= 2;
    }
    return b*p + a*q;
  }
};

#endif // _SNIPPETS_FIBONACCI_NUMBER_HPP

