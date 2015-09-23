#include "accumulate.h"

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

namespace ns_stl	{

// std::accumulate
// sum (1)	
// template <class InputIterator, class T>
//    T accumulate (InputIterator first, InputIterator last, T init);
// custom (2)	
// template <class InputIterator, class T, class BinaryOperation>
//    T accumulate (InputIterator first, InputIterator last, T init,
//                  BinaryOperation binary_op);

	void accumulate_demo()	{
		
		cout << "\nstd::accumulate()\n";
		
		std::vector<int> ivec {1, 2, 3, 5, 8, 13};
		auto sum	= 0;
		sum	= accumulate(ivec.begin(), ivec.end(), sum);

		std::copy(ivec.begin(), ivec.end(), std::ostream_iterator<int>(cout, " "));
		std::cout << "\nAccumulated sum: " << sum << std::endl;

		add_squares_t as;
		sum	= 0;
		sum	= accumulate(ivec.begin(), ivec.end(), sum, as);
		std::cout << "\nSum of squares: " << sum << std::endl;
	}
}
