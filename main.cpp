#include <iostream>

template <unsigned int x>
struct factorial {
	static const int value = x * factorial<x - 1>::value;
};

template <>
struct factorial<0> {
	static const int value = 1;
};

int main()
{
	std::cout << factorial<5>::value << std::endl;

	return 0;
}
