#include <kanooth/snippets/prime_checker_bounded_simple.hpp>

template <class X, class A>
inline void xassert(A assertion) {
  if (!assertion) throw X();
}

class bad_result {};

int main()
{
  const int bound = 10000000;
  prime_checker_bounded_simple is_prime(bound);
  
  xassert<bad_result>(!is_prime[0]);
  xassert<bad_result>(!is_prime[1]);
  xassert<bad_result>( is_prime[2]);
  xassert<bad_result>( is_prime[3]);
  xassert<bad_result>(!is_prime[4]);
  xassert<bad_result>( is_prime[5]);
  xassert<bad_result>(!is_prime[6]);
  xassert<bad_result>( is_prime[7]);
  xassert<bad_result>(!is_prime[8]);
  xassert<bad_result>(!is_prime[9]);
  xassert<bad_result>(!is_prime[10]);
  
  // Number of primes <= n
  // See http://oeis.org/A000720
  // See http://oeis.org/A006880
  unsigned count = 0;
  for (int k = 0; k <= bound; ++k)
    if (is_prime[k])
      ++count;
  //xassert<bad_result>(count == 9592);     // bound == 100000
  xassert<bad_result>(count == 664579);  // bound == 10000000
  
  // Sum of first n primes
  // See http://oeis.org/A007504
  unsigned sum = 0;  // must be at least 32 bits
  int n = 0, i = 0;
  for (int k = 0; n < 27875; ++k)
    if (is_prime[k]) {
      sum += k;
      ++n;
    }
  xassert<bad_result>(sum == 4294841976u);  // sum of the first 27875 primes
  
  return 0;
}

