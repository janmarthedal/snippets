/*
 * Author: Jan Marthedal Rasmussen
 * See   : http://kanooth.com/snippets/gcd_euclid.html
 *
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_GCD_EUCLID_HPP
#define _SNIPPETS_GCD_EUCLID_HPP

/* Computes the greatest common divisor of two    *
 * non-negative integers using Euclid's algorithm */
template <typename NUM>
NUM gcd_euclid(NUM a, NUM b)
{
  while (true) {
    if (!b) return a;
    a %= b;
    if (!a) return b;
    b %= a;
  }
}

#endif // _SNIPPETS_GCD_EUCLID_HPP

