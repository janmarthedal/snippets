SNIPPETS=kanooth/snippets
INCPATH=-I../test -I. -I..

trailing_binary_zeros: trailing_binary_zeros.cpp $(SNIPPETS)/trailing_binary_zeros.hpp
	g++ -O2 $(INCPATH) $< -o $@

is_perfect_square: is_perfect_square.cpp $(SNIPPETS)/is_perfect_square.hpp
	g++ -O2 $(INCPATH) $< -o $@

clean:
	rm -f trailing_binary_zeros
	rm -f is_perfect_square

