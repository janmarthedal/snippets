#include <kanooth/snippets/gcd_euclid.hpp>
#include <kassert.hpp>

int gcd_sum(int n)
{
  int sum = 0;
  for (int k = 1; k <= n; ++k)
    sum += gcd_euclid(k, n);
  return sum;
}

int main()
{
  kassert(gcd_euclid(0, 1) == 1);
  kassert(gcd_euclid(1, 0) == 1);
  kassert(gcd_euclid(9, 6) == 3);
  kassert(gcd_euclid(6, 9) == 3);

  // See http://oeis.org/A018804
  kassert(gcd_sum(2000) == 20400);

  return 0;
}

