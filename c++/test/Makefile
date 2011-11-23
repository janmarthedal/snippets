SNIPPETS_ROOT=..
SNIPPETS=$(SNIPPETS_ROOT)/kanooth/snippets
DEFINC=kassert.hpp

fibonacci_number: fibonacci_number.cpp $(SNIPPETS)/fibonacci_number.hpp $(DEFINC)
	g++ -O2 -I. -I$(SNIPPETS_ROOT) $< -o $@

gcd_euclid: gcd_euclid.cpp $(SNIPPETS)/gcd_euclid.hpp $(DEFINC)
	g++ -O2 -I. -I$(SNIPPETS_ROOT) $< -o $@

gcd_stein: gcd_stein.cpp $(SNIPPETS)/gcd_stein.hpp $(DEFINC)
	g++ -O2 -I. -I$(SNIPPETS_ROOT) $< -o $@

integer_binary_logarithm: integer_binary_logarithm.cpp $(SNIPPETS)/integer_binary_logarithm.hpp $(DEFINC)
	g++ -O2 -I. -I$(SNIPPETS_ROOT) $< -o $@

clean:
	rm -f fibonacci_number
	rm -f gcd_euclid
	rm -f gcd_stein
	rm -f integer_binary_logarithm

