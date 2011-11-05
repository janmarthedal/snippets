#include <kanooth/snippets/prime_checker.hpp>

template <class X, class A>
inline void xassert(A assertion) {
  if (!assertion) throw X();
}

class bad_result {};

int main()
{
  const int bound = 1000;
  prime_checker_bounded is_prime(1000);
  
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
  
  
  
  return 0;
}

