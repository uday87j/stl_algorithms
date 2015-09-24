#include "sort.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;

namespace ns_stl	{

	void print_vector(const std::vector<int>& vec)	{
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	}

	void sort_demo()	{

		cout << "\nstd::sort()\n";

		cout << "\nExample 1:\n";
		std::uniform_int_distribution<int> dist(1, 100);
		std::random_device rd;
		std::vector<int> ivec(10);
		for(auto& i : ivec)	{
			i	= dist(rd);
		}
		print_vector(ivec);

		std::sort(ivec.begin(), ivec.end());

		cout << "\nAfter sorting:\n";
		print_vector(ivec);
	}
}
