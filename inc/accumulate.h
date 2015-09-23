#ifndef ACCUMULATE_DEMO_H_
#define ACCUMULATE_DEMO_H_

// accumulate_demo.h
namespace ns_stl	{

	struct add_squares_t	{

		int operator() (const int accumulator, const int augend)	{
			auto sum	= accumulator + augend*augend;
			return sum;
		}
	};


	extern void accumulate_demo();
}
#endif
