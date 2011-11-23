#include <kanooth/snippets/trailing_binary_zeros.hpp>
#include <kassert.hpp>

template <typename T>
unsigned ntz(T v) {
  unsigned r = 0;
  while (!(v & 1)) { v >>= 1; r++; }
  return r;
}

int main()
{
	for (unsigned short n=1; n < 1000; n++)
	  kassert(trailing_binary_zeros(n) == ntz(n));
	for (unsigned int n=100000; n < 101000; n++)
	  kassert(trailing_binary_zeros(n) == ntz(n));
	for (unsigned long n=10000000; n < 10001000; n++)
	  kassert(trailing_binary_zeros(n) == ntz(n));

  return 0;
}

