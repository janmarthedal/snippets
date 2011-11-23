SNIPPETS=kanooth/snippets
DEFINC=../test/kassert.hpp
INCPATH=-I../test -I. -I..

trailing_binary_zeros: trailing_binary_zeros.cpp $(SNIPPETS)/trailing_binary_zeros.hpp $(DEFINC)
	g++ -O2 $(INCPATH) $< -o $@

clean:
	rm -f trailing_binary_zeros

