#include <boost/type_traits/is_same.hpp>
#include <iostream>

template <typename c, typename x, typename y, bool isSame>
struct replace_type_impl;

template <typename c, typename x, typename y>
struct replace_type {
	typedef typename replace_type_impl<c, x, y, boost::is_same<c, x>::value>::type type;
};

template <typename c, typename x, typename y>
struct replace_type_impl<c, x, y, true> {
	typedef y type;
};

template <typename c, typename x, typename y>
struct replace_type_impl<c*, x, y, false> {
	typedef typename replace_type<c, x, y>::type* type;
};

template <typename c, typename x, typename y>
struct replace_type_impl<c [], x, y, false> {
	typedef typename replace_type<c, x, y>::type type[];
};

template <typename c, typename x, typename y, int N>
struct replace_type_impl<c [N], x, y, false> {
	typedef typename replace_type<c, x, y>::type type[N];
};

template <typename c, typename x, typename y>
struct replace_type_impl<const c, x, y, false> {
	typedef typename replace_type<c, x, y>::type const type;
};

template <typename c, typename x, typename y>
struct replace_type_impl<c&, x, y, false> {
	typedef typename replace_type<c, x, y>::type& type;
};

template <typename c, typename x, typename y>
struct replace_type_impl<c (*)(), x, y, false> {
	typedef typename replace_type<c, x, y>::type (*type)();
};

 int main()
 {
	 std::cout << std::boolalpha << boost::is_same<int, replace_type<void, void, int>::type>::value << std::endl;
	 std::cout << std::boolalpha << boost::is_same<int*, replace_type<void**, void*, int>::type>::value << std::endl;
	 std::cout << std::boolalpha << boost::is_same<int[], replace_type<char[], char, int>::type>::value << std::endl;
	 std::cout << std::boolalpha << boost::is_same<const int, replace_type<const bool, bool, int>::type>::value << std::endl;
	 std::cout << std::boolalpha << boost::is_same<int&, replace_type<long&, long, int>::type>::value << std::endl;
	 std::cout << std::boolalpha << boost::is_same<const char&, replace_type<const double&, double, char>::type>::value << std::endl;
	 std::cout << std::boolalpha << boost::is_same<long*[10], replace_type<int const* [10], int const, long>::type>::value << std::endl;
	 std::cout << std::boolalpha << boost::is_same<float* (*)(), replace_type<const int* (*)(), const int, float>::type>::value << std::endl;

     return 0;
 }
