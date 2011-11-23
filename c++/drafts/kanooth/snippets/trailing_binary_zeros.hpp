/*
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_TRAILING_BINARY_ZEROS_HPP
#define _SNIPPETS_TRAILING_BINARY_ZEROS_HPP

#include <cstddef>   // for std::size_t
#include <kanooth/snippets/number_bits.hpp>

namespace {

  // https://oeis.org/A007814
	short ruler_table[256] = {
	 -1, 0, 1,0, 2,0,1,0, 3,0,1,0,2,0,1,0, 4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,
	 5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,
	 6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,
	 5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,
	 7,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,
	 5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,
	 6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,
	 5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0 };

	template <typename T, unsigned bits>
	struct ruler_eval;

	template <typename T>
	struct ruler_eval<T, 8> {
		std::size_t operator()(const T n) const {
		  return ruler_table[n & 0xff];
		}
	};

	template <typename T>
	struct ruler_eval<T, 16> {
		std::size_t operator()(T n) const {
		  static const T ones = -1;
		  std::size_t r = 0;
		  if (!(n & ~(ones << 8))) { n >>= 8; r += 8; }
		  return r + ruler_table[n & 0xff];
		}
	};

	template <typename T>
	struct ruler_eval<T, 32> {
		std::size_t operator()(T n) const {
		  static const T ones = -1;
		  std::size_t r = 0;
		  if (!(n & ~(ones << 16))) { n >>= 16; r += 16; }
		  if (!(n & ~(ones <<  8))) { n >>=  8; r +=  8; }
		  return r + ruler_table[n & 0xff];
		}
	};

	template <typename T>
	struct ruler_eval<T, 64> {
		std::size_t operator()(T n) const {
		  static const T ones = -1;
		  std::size_t r = 0;
		  if (!(n & ~(ones << 32))) { n >>= 32; r += 32; }
		  if (!(n & ~(ones << 16))) { n >>= 16; r += 16; }
		  if (!(n & ~(ones <<  8))) { n >>=  8; r +=  8; }
		  return r + ruler_table[n & 0xff];
		}
	};

}

template <typename T>
inline std::size_t trailing_binary_zeros(T n)
{
	return ruler_eval<T, number_bits<T>::value>()(n);
}

#endif // _SNIPPETS_TRAILING_BINARY_ZEROS_HPP

