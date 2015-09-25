#include "sort.h"
#include "length.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;

namespace ns_stl	{

    template<typename T>
	void print_vector(const std::vector<T>& vec)	{
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(cout, " "));
	}

    template<typename T>
    void print_vector(const std::vector<rectangle_t<T> >& vec)  {
        std::for_each(vec.begin(), vec.end(), [](const rect_t& r) {
            cout << r << endl;
        });
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

		cout << "\nExample 2:\n";
        std::vector<rect_t> rectangles(5);
        rectangles[0]   = rect_t(4, 10);
        rectangles[1]   = rect_t(6, 12);
        rectangles[2]   = rect_t(15, 4);
        rectangles[3]   = rect_t(5, 17);
        rectangles[4]   = rect_t(11, 6);
		print_vector(rectangles);

		std::sort(rectangles.begin(), rectangles.end());
        
        cout << "\nAfter sorting:\n";
		print_vector(rectangles);

		
	}
}
