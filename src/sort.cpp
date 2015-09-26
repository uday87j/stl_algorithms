#include "sort.h"
#include "length.h"
#include "util.h"

#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <random>
#include <cassert>

using namespace std;

namespace ns_stl	{

    void simple_sort_demo()	{
		cout << "\nExample 1:\n";
		cout << "\nstd::sort()\n";
    	auto ivec	= create_random_int_vector(10);
		print_vector(ivec);

		std::sort(ivec.begin(), ivec.end());

        cout << "\nAfter sorting:\n";
		print_vector(ivec);
		
		cout << "\n\nExample 2:\n";
		
		auto rectangles	= create_random_rectangle_vector(20);
		
		print_vector(rectangles);

		std::sort(rectangles.begin(), rectangles.end(), &compare_rect_height<rect_t::this_type>);
        
        cout << "\nAfter sort():\n";
        assert(std::is_sorted(rectangles.begin(), rectangles.end(), &compare_rect_height<rect_t::this_type>));
		print_vector(rectangles);
		cout << "\nIt can be noticed that for reactangles with equal width, after sorting, \
they are not necessarily arranged as per the order of their respective height\n";
	}

	void stable_sort_demo()	{
		cout << "\nExample 3:\n";
			
		auto rectangles	= create_random_rectangle_vector(20);
		print_vector(rectangles);

		std::stable_sort(rectangles.begin(), rectangles.end(), &compare_rect_height<rect_t::this_type>);

        cout << "\nAfter stable_sort():\n";
        assert(std::is_sorted(rectangles.begin(), rectangles.end(), &compare_rect_height<rect_t::this_type>));
		print_vector(rectangles);
		cout << "\nIt can be noticed that for reactangles with equal width, after stable-sorting, \
they are necessarily arranged as per the order of their respective height\n";
	}

	void partial_sort_demo()	{
		cout << "\nExample 4:\n";
		cout << "\nstd::partial_sort()\n";
    	auto ivec	= create_random_int_vector(10);
		print_vector(ivec);

		auto mid	= ivec.begin() + ((ivec.end() - ivec.begin())/2);
		std::partial_sort(ivec.begin(), mid, ivec.end());

        cout << "\nAfter partial-sorting 1st half:\n";
        assert(std::is_sorted(ivec.begin(), mid));
        cout << "\nNote that the element just after the end of sorted range needn't necessarily occupy the position it would get if the entire vector was sorted\n";
		print_vector(ivec);
	}

	void nth_element_sort_demo()	{
		cout << "\nExample 5:\n";
		cout << "\nstd::nth_element()\n";
    	auto ivec	= create_random_int_vector(10);
		print_vector(ivec);

		auto mid	= ivec.begin() + ((ivec.end() - ivec.begin())/2);
		std::nth_element(ivec.begin(), mid, ivec.end());

		cout << "\nAfter partitioning with nth element (mid:" << *mid << ") as pivot:\n";
		std::for_each(ivec.begin(), mid, [&](const int e)	{
			assert(std::less_equal<int>()(e, *mid));
		});
		std::for_each(mid, ivec.end(), [&](const int e)	{
			assert(std::greater_equal<int>()(e, *mid));
		});
		cout << "\nNote that \"mid\" actually occupies its final position as if the entire vector was sorted\
, and 'mid' partitions the vector such that elements to left of it are <= to it &\
 those to right of it are >= to it.\n";
		print_vector(ivec);
	}

	void sort_demo()	{
		simple_sort_demo();
		stable_sort_demo();
		partial_sort_demo();
		nth_element_sort_demo();
	}
}
