#include <kanooth/snippets/integer_binary_logarithm.hpp>
#include <kassert.hpp>

template <typename T>
unsigned lb(T v) {
  unsigned r = -1;
  while (v) { v >>= 1; r++; }
  return r;
}

template <typename T>
void compare(T v)
{
  kassert(integer_binary_logarithm(v) == lb(v));
}

int main()
{
  compare(0u);
  compare(1u);
  compare(2u);
  compare(33u);
  compare(127u);
  compare(200u);
  compare(256u);

  return 0;
}

