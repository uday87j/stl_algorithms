#include "count.h"
#include "util.h"

#include <random>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace ns_stl	{

	void count_demo()	{
		cout << "\nExample 1:\n";
		cout << "\nstd::count():\n";
    	auto ivec	= create_random_int_vector(10, 10, 20);
		print_vector(ivec);
		auto target	= create_random_num(10, 20);
		cout << endl << target << " appears " << std::count(ivec.begin(), ivec.end(), target) << " times in the array\n";

		cout << "\nExample 2:\n";
		cout << "\nstd::count_if():\n";
		auto rectangles	= create_random_rectangle_vector(10);
		print_vector(rectangles);
		auto c	= std::count_if(rectangles.begin(), rectangles.end(), [](const rect_t& r)	{
			return ((r.height().len() % 2) != 0);
		});
		cout << endl << "\nThere are " << c << " rectangles with odd height\n";
	}
}
