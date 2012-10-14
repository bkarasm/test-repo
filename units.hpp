#ifndef UNITS_HPP_
#define UNITS_HPP_

#include <boost/mpl/vector_c.hpp>

namespace mpl =  boost::mpl;

namespace units {
	//						   kg   m   s
	typedef mpl::vector_c<int,  1,  0,  0> mass;
	typedef mpl::vector_c<int,  0,  1,  0> length;
	typedef mpl::vector_c<int,  0,  0,  1> time;
	typedef mpl::vector_c<int,  0,  0,  0> scalar;
	typedef mpl::vector_c<int,  0,  1, -1> velocity;
	typedef mpl::vector_c<int,  0,  1, -2> acceleration;
	typedef mpl::vector_c<int,  1,  1, -2> force;
	typedef mpl::vector_c<int,  1,  2, -2> energy;
}


#endif /* UNITS_HPP_ */
