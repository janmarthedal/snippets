#include <boost/multiprecision/gmp.hpp>
//#include <boost/random/mersenne_twister.hpp>
#include <boost/random/ranlux.hpp>

#include "random_bits_number.hpp"


int main()
{
    typedef boost::multiprecision::mpz_int number;
    //boost::random::mt19937 engine(std::time(0));
    boost::random::ranlux3 engine(std::time(0));
    
    number v = generate_random_bits_number<number>(engine, 10000);
    
    std::cout << v << std::endl;
    std::cout << floor_log2(v)+1 << std::endl;
    
    return 0;
}
