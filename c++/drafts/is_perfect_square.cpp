#include <kanooth/snippets/is_perfect_square.hpp>
#include <kassert.hpp>

int main()
{
	kassert( is_perfect_square(1u));
	kassert(!is_perfect_square(2u));
	kassert(!is_perfect_square(3u));
	kassert( is_perfect_square(4u));
	kassert(!is_perfect_square(5u));
	kassert(!is_perfect_square(6u));
	kassert(!is_perfect_square(7u));
	kassert(!is_perfect_square(8u));
	kassert( is_perfect_square(9u));
	kassert(!is_perfect_square(10u));

  return 0;
}

