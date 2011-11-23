/*
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_INTEGRAL_CONSTANT_HPP
#define _SNIPPETS_INTEGRAL_CONSTANT_HPP

template <typename T, T val>
struct integral_constant {
  static const T value = val;
};

#endif // _SNIPPETS_INTEGRAL_CONSTANT_HPP

