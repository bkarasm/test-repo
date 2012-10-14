#include <cassert>
#include <iostream>
#include "units.hpp"
#include "quantity.hpp"


int main()
{
	Quantity<double, units::mass> m1 = 77.2;
	Quantity<double, units::mass> m2 = 0.6;
	Quantity<double, units::acceleration> a = 9.81;
	Quantity<double, units::time> t = 12.2;
	Quantity<double, units::length> l = 100;

	Quantity<double, units::mass> m = m1 + m2;
	Quantity<double, units::force> f = m * a;
	std::cout << "f = " << f.value() << std::endl;

	Quantity<double, units::velocity> v = l / t;
	std::cout << "v = " << v.value() << std::endl;

	Quantity<double, units::energy> e = m * v * v / Quantity<double, units::scalar>(2);
	std::cout << "e = " << e.value() << std::endl;

	return 0;
}
