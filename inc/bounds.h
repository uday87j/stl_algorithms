#ifndef BOUND_DEMO_H_
#define BOUND_DEMO_H_

#include <algorithm>
#include <vector>

// bound_demo.h
namespace ns_stl	{

// default (1)	
// template <class ForwardIterator, class T>
//   ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
//                                const T& val);
// custom (2)	
// template <class ForwardIterator, class T, class Compare>
//   ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
//                                const T& val, Compare comp);

extern void lower_bound_demo(const std::vector<int>& ivec, const int val);
extern void upper_bound_demo(const std::vector<int>& ivec, const int val);
extern void bounds_demo();


}
#endif
