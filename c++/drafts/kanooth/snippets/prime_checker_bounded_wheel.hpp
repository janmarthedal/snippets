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

#ifndef _SNIPPET_PRIME_CHECKER_BOUNDED_WHEEL_HPP
#define _SNIPPET_PRIME_CHECKER_BOUNDED_WHEEL_HPP

#include <vector>

class prime_checker_bounded_wheel {
private:
  typedef std::vector<bool> Cont;
  Cont not_prime;
public:
  prime_checker_bounded_wheel(const typename Cont::size_type n)
    : not_prime(n+1)
  {
    const unsigned table_size = 3;
    unsigned table[table_size] = {2,3,5};
    unsigned index = 0, i, j, k;

    i = 0;
    while (index < table_size) {
      while (i < table[index] && i <= n)
        not_prime[i++] = true;
      ++i;
      ++index;
    }

    if (index == table_size) {
      const unsigned wheel_size = 8;
      unsigned wheel[wheel_size] = {6,4,2,4,2,4,6,2};
      
      k = 1;
      index = 0;
      while (true) {
        do {
          k += wheel[index];
          index = (index+1) % wheel_size;
        } while (k <= n && not_prime[k]);
        if (k > n)
          break;
        for (i=k*k, j=index; i <= n; i += k*wheel[j], j = (j+1) % wheel_size)
          not_prime[i] = true;
      }
    }
  }
  inline bool operator[](const typename Cont::size_type n) const {
    return !not_prime[n];
  }
  inline typename Cont::size_type max() const {
    return not_prime.size()-1;
  }
};

#endif // _SNIPPET_PRIME_CHECKER_BOUNDED_WHEEL_HPP

