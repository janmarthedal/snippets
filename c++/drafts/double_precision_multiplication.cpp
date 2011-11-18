#include <assert.h>
#include <kanooth/snippets/double_precision_multiplication.hpp>

template <typename T>
void test_max()
{
  T max = (T) -1;
  T high, low;
  double_precision_multiplication(max, max, max, max, high, low);
  assert(high == max);
  assert(low == max);
}

int main()
{
  test_max<unsigned short>();
  test_max<unsigned int>();
  test_max<unsigned long>();
#ifdef KANOOTH_HAS_LONG_LONG
  test_max<unsigned long long>();
#endif

  return 0;
}

