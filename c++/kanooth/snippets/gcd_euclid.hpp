/*
 * File:   snippets/gcd_euclid.hpp
 * Author: Jan Marthedal Rasmussen
 *
 * Created 2011-11-09 14:23Z
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_GCD_EUCLID_HPP
#define _SNIPPETS_GCD_EUCLID_HPP

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

