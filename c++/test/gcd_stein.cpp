#include <kanooth/snippets/gcd_stein.hpp>
#include <kassert.hpp>

unsigned gcd_sum(unsigned n)
{
  unsigned sum = 0;
  for (unsigned k = 1; k <= n; ++k)
    sum += gcd_stein(k, n);
  return sum;
}

int main()
{
  kassert(gcd_stein(0u, 1u) == 1u);
  kassert(gcd_stein(1u, 0u) == 1u);
  kassert(gcd_stein(9u, 6u) == 3u);
  kassert(gcd_stein(6u, 9u) == 3u);

  // See http://oeis.org/A018804
  kassert(gcd_sum(2000) == 20400);

  return 0;
}

