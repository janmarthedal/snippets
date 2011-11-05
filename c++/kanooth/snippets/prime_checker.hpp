#ifndef _SNIPPET_PRIME_CHECKER_HPP
#define _SNIPPET_PRIME_CHECKER_HPP

#include <vector>

class prime_checker_bounded {
private:
  typedef std::vector<bool> Cont;
  Cont not_prime;
public:
  prime_checker_bounded(const typename Cont::size_type n) : not_prime(n+1) {
    typename Cont::size_type j=1, k;
    not_prime[0] = not_prime[1] = true;
    while (true) {
      do {
        j++;
      } while (j <= n && not_prime[j]);
      if (j > n)
        break;
      for (k = j*j; k <= n; k += j)
        not_prime[k] = true;
    }
  }
  inline bool operator[](const typename Cont::size_type n) const {
    return !not_prime[n];
  }
  inline typename Cont::size_type max() const {
    return not_prime.size()-1;
  }
};

#endif // _SNIPPET_PRIME_CHECKER_HPP

