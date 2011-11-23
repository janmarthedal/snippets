/*
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_NUMBER_BITS_HPP
#define _SNIPPETS_NUMBER_BITS_HPP

#include <kanooth/snippets/integral_constant.hpp>

#ifdef KANOOTH_USE_BOOST

#include <boost/integer_traits.hpp>
template <typename T>
struct number_bits
	: public integral_constant<unsigned, boost::integer_traits<T>::digits> {};

#else

#include <limits>
template <typename T>
struct number_bits
	: public integral_constant<unsigned, std::numeric_limits<T>::digits> {};

#endif

#endif // _SNIPPETS_NUMBER_BITS_HPP

