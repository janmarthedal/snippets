#include <kanooth/snippets/gcd_stein.hpp>
#include <kassert.hpp>

int gcd_sum(int n)
{
  int sum = 0;
  for (int k = 1; k <= n; ++k)
    sum += gcd_stein(k, n);
  return sum;
}

int main()
{
  kassert(gcd_stein(0, 1) == 1);
  kassert(gcd_stein(1, 0) == 1);
  kassert(gcd_stein(9, 6) == 3);
  kassert(gcd_stein(6, 9) == 3);

  // See http://oeis.org/A018804
  kassert(gcd_sum(2000) == 20400);

  return 0;
}

