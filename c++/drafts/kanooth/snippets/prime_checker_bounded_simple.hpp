/*
 * File:   snippets/double_precision_multiplication.hpp
 * Author: Jan Marthedal Rasmussen
 *
 * Created 2011-11-07 10:00Z
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPET_PRIME_CHECKER_BOUNDED_SIMPLE_HPP
#define _SNIPPET_PRIME_CHECKER_BOUNDED_SIMPLE_HPP

#include <vector>

class prime_checker_bounded_simple {
private:
  typedef std::vector<bool> Cont;
  Cont not_prime;
public:
  prime_checker_bounded_simple(const typename Cont::size_type n)
    : not_prime(n+1)
  {
    typename Cont::size_type j=1, k;
    not_prime[0] = not_prime[1] = true;
    while (true) {
      do {
        j++;
      } while (j <= n && not_prime[j]);
      if (j > n)
        break;
      for (k = j*j; k <= n; k += j)
        not_prime[k] = true;
    }
  }
  inline bool operator[](const typename Cont::size_type n) const {
    return !not_prime[n];
  }
  inline typename Cont::size_type max() const {
    return not_prime.size()-1;
  }
};

#endif // _SNIPPET_PRIME_CHECKER_BOUNDED_SIMPLE_HPP

