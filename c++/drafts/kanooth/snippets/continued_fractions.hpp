/*
 * Author: Jan Marthedal Rasmussen
 * See   : http://kanooth.com/blog/2009/11/continued-fractions-and-continuants.html
 *
 * (C) Copyright Jan Marthedal Rasmussen 2009-2011
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _SNIPPETS_CONTINUED_FRACTIONS_HPP
#define _SNIPPETS_CONTINUED_FRACTIONS_HPP

template <typename NUM, typename Out>
void fraction_to_continued_fraction(NUM u, NUM v, Out out)
{
  if (v < 0) { u = -u; v = -v; }
  NUM r = u % v;
  if (r < 0) { u -= v; r += v; }
  *out++ = u/v;
  u = r;
  while (true) {
    if (!u) return;
    *out++ = v/u;
    v %= u;
    if (!v) return;
    *out++ = u/v;
    u %= v;
  }
}

template <typename NUM>
void show_cont_frac(const std::vector<NUM>& vec)
{
  unsigned i = 0;
  for (typename std::vector<NUM>::const_iterator p = vec.begin(); p != vec.end(); ++p, ++i) {
    if (i == 1)
      std::cout << " + //";
    else if (i > 1)
      std::cout << ", ";
    std::cout << *p;
  }
  if (i > 1)
    std::cout << "//";
}

void show_frac(unsigned u, unsigned v)
{
  std::vector<unsigned> cf;
  fraction_to_continued_fraction(u, v, std::back_inserter(cf));
  show_cont_frac(cf);
  std::cout << std::endl;
}

template <typename NUM, typename In>
NUM evaluate_continued_fraction_rec2(In first, In last)
{
  if (first == last) return (NUM) 0;
  return 1/(*first + evaluate_continued_fraction_rec2<NUM>(first+1, last));
}

template <typename NUM, typename In>
NUM evaluate_continued_fraction_rec(In first, In last)
{
  if (first == last) return (NUM) 0;
  return *first + evaluate_continued_fraction_rec2<NUM>(first+1, last);
}

template <typename NUM, typename Bi>
NUM evaluate_continued_fraction_rev(Bi first, Bi last)
{
  if (last == first) return (NUM) 0;
  NUM r = 0;
  while (--last != first)
    r = 1/(*last + r);
  return *last + r;
}

template <typename NUM, typename In>
void evaluate_continued_fraction(In first, In last, NUM& num, NUM& den)
{
  if (first == last) { num = 0; den = 1; return; }
  NUM x, u = *first, v = 1, s = 1, t = 0;
  while (true) {
    if (++first == last) { num = u; den = v; return; }
    x = *first;
    s += x*u;
    t += x*v;
    if (++first == last) { num = s; den = t; return; }
    x = *first;
    u += x*s;
    v += x*t;
  }
}

template <typename NUM, typename In>
void evaluate_continued_fraction2(In first, In last, NUM& num, NUM& den)
{
  if (first == last) { num = 0; den = 1; return; }
  NUM x, u = *first, v = 1, s = 1, t = 0;
  while (++first != last) {
    x = *first;
    s += x*u;
    t += x*v;
    std::swap(u, s);
    std::swap(t, v);
  }
  num = u;
  den = v;
}

#endif // _SNIPPETS_CONTINUED_FRACTIONS_HPP

