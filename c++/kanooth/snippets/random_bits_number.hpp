#ifndef SNIPPET_RANDOM_BITS_NUMBER_HPP
#define SNIPPET_RANDOM_BITS_NUMBER_HPP

#include <limits>

template <typename T>
struct make_unsigned {};
template <>
struct make_unsigned<signed int>    { typedef unsigned int type;  };
template <>
struct make_unsigned<unsigned int>  { typedef unsigned int type;  };
template <>
struct make_unsigned<signed long>   { typedef unsigned long type; };
template <>
struct make_unsigned<unsigned long> { typedef unsigned long type; };

template <typename T>
unsigned floor_log2(T v)
{
    unsigned res = -1;
    while (v) {
        v >>= 1;
        ++res;
    }
    return res;
}

template <typename T>
typename make_unsigned<T>::type subtract_to_unsigned(T x, T y)
{
    typedef typename make_unsigned<T>::type unsigned_type;
    if (y < 0)
        return unsigned_type(x) + unsigned_type(-(y+1)) + 1;
    return unsigned_type(x - y);
}

template <typename T, typename Engine>
T generate_random_bits_number(Engine& engine, unsigned width)
{
    typedef typename Engine::result_type base_type;
    typedef typename make_unsigned<base_type>::type unsigned_base;
    unsigned_base range = subtract_to_unsigned(Engine::max(), Engine::min());    
    unsigned_base limit, value;
    unsigned base_bits;
    T result = T();
    
    if (range == unsigned_base(-1)) {
        base_bits = std::numeric_limits<unsigned_base>::digits;
        limit = unsigned_base(-1);
    } else {
        base_bits = floor_log2(range + 1);
        limit = (unsigned_base(1) << base_bits) - 1;
    }
    
    while (width >= base_bits) {
        do {
            value = subtract_to_unsigned(engine(), Engine::min());
        } while (value > limit);
        result <<= base_bits;
        result |= value;
        width -= base_bits;
    }
    if (width) {
        do {
            value = subtract_to_unsigned(engine(), Engine::min());
        } while (value > limit);
        result <<= width;
        result |= value & ((unsigned_base(1) << width) - 1);
    }

    return result;
}

#endif // SNIPPET_RANDOM_BITS_NUMBER_HPP
