#ifndef QUANTITY_HPP_
#define QUANTITY_HPP_

#include <boost/mpl/transform.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/static_assert.hpp>

namespace mpl = boost::mpl;

template <typename T, typename Dimension>
struct Quantity {
	Quantity(const T& value) : value_(value) {
	}

	template <typename OtherDimension>
	Quantity(const Quantity<T, OtherDimension>& rhs) : value_(rhs.value()) {
		BOOST_STATIC_ASSERT((
				mpl::equal<Dimension, OtherDimension>::type::value
				));
	}

	const T& value() const {
		return value_;
	}

private:
	T value_;
};

template <typename T, typename Dimension>
Quantity<T, Dimension> operator+(
		const Quantity<T, Dimension>& q1,
		const Quantity<T, Dimension>& q2) {
	return Quantity<T, Dimension>(q1.value() + q2.value());
}

template <typename T, typename Dimension>
Quantity<T, Dimension> operator-(
		const Quantity<T, Dimension>& q1,
		const Quantity<T, Dimension>& q2) {
	return Quantity<T, Dimension>(q1.value() - q2.value());
}

template <typename T, typename Dimension1, typename Dimension2>
Quantity<T, typename mpl::transform<Dimension1, Dimension2, mpl::plus<mpl::_1, mpl::_2> >::type> operator*(
		const Quantity<T, Dimension1>& q1,
		const Quantity<T, Dimension2>& q2) {
	return Quantity<T, typename mpl::transform<Dimension1, Dimension2, mpl::plus<mpl::_1, mpl::_2> >::type>(
			q1.value() * q2.value());
}

template <typename T, typename Dimension1, typename Dimension2>
Quantity<T, typename mpl::transform<Dimension1, Dimension2, mpl::minus<mpl::_1, mpl::_2> >::type> operator/(
		const Quantity<T, Dimension1>& q1,
		const Quantity<T, Dimension2>& q2) {
	return Quantity<T, typename mpl::transform<Dimension1, Dimension2, mpl::minus<mpl::_1, mpl::_2> >::type>(
			q1.value() / q2.value());
}


#endif /* QUANTITY_HPP_ */
