#include "accumulate.h"
#include "bounds.h"

#include <vector>
#include <iterator>

#include <iostream>

using namespace ns_stl;
using namespace std;

void print_line_break()	{
	std::vector<char> cvec(82, '-');
	cvec[0]	= cvec[81]	= '\n';
	std::copy(cvec.begin(), cvec.end(), std::ostream_iterator<char>(cout, ""));
}

int main()	{

	print_line_break();
	accumulate_demo();

	print_line_break();
	bounds_demo();

	print_line_break();
	return 0;
}
