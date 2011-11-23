/*
 * Author: Jan Marthedal Rasmussen
 * See   : 
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_IS_PERFECT_SQUARE_HPP
#define _SNIPPETS_IS_PERFECT_SQUARE_HPP

#include <integer_square_root.hpp>

template <typename NUM>
NUM sqr(const NUM n)
{
  return n*n;
}

template <typename NUM>
bool is_perfect_square(const NUM n)
{
  return sqr(integer_square_root(n)) == n;
}

#endif // _SNIPPETS_IS_PERFECT_SQUARE_HPP

