#include "bounds.h"

#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

namespace ns_stl	{

	void lower_bound_demo(const std::vector<int>& ivec, const int val)	{
		auto lb	= lower_bound(ivec.begin(), ivec.end(), val);
		cout << "\nFirst element in the vector that is  NOT less than " << val << " is: " << *lb \
		<< ", at position: " << std::distance(ivec.begin(), lb) << endl;
	}

	void upper_bound_demo(const std::vector<int>& ivec, const int val)	{
		auto ub	= upper_bound(ivec.begin(), ivec.end(), val);
		cout << "\nFirst element in the vector that is greater than " << val << " is: " << *ub \
		<< ", at position: " << std::distance(ivec.begin(), ub) << endl;
	}

	void bounds_demo()	{

		cout << "\nstd::lower_bound() & std::upper_bound()\n";
		
		std::vector<int> ivec {14, 22, 43, 75, 78, 103};
		std::vector<int> ivec_2 {5, 5, 10, 10, 10, 15, 15, 20, 20, 20};

		cout << "\nExample 1:\n";
		std::ostream_iterator<int> ost_it(cout, " ");
		std::copy(ivec.begin(), ivec.end(), ost_it);
		lower_bound_demo(ivec, 40);
		upper_bound_demo(ivec, 40);

		cout << "\nExample 2:\n";
		std::copy(ivec_2.begin(), ivec_2.end(), ost_it);
		lower_bound_demo(ivec_2, 10);
		upper_bound_demo(ivec_2, 10);
	}
}
