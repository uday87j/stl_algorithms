#ifndef UTIL_FUNC_H_
#define UTIL_FUNC_H_

#include "length.h"

#include <vector>
#include <iterator>
#include <iostream>

namespace ns_stl	{
    extern std::vector<int> create_random_int_vector(const std::uint32_t size);
    extern std::vector<rect_t> create_random_rectangle_vector(const std::uint32_t size);
	
	template<typename T>
	void print_vector(const std::vector<T>& vec)	{
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	}
}
#endif
