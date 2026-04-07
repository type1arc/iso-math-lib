#pragma once

#include "iso_vortex.hpp"

namespace vortex
{
	namespace opt
	{
		template<iso::concepts::numeric _type>
		Shift<_type>::Shift(_type x, _type y, _type z) : x(x), y(y), z(z) {}

		template<iso::concepts::numeric _type>
		Shift<_type> Shift<_type>::operator>>(const Shift<_type>& _this)
		{
			return Shift(x = _this.y, y = _this.z, z = _this.x);
		}
		
		template<iso::concepts::numeric _type>
		void Shift<_type>::log()
		{
			std::cout << "(" << x << ", " << y << ", " << ")";
		}
		
		// Exponentiation
		template<iso::concepts::numeric _type>
		Expo<_type>::Expo(_type x) : x(x) {}

		template<iso::concepts::numeric _type>
		_type Expo<_type>::operator^(_type Exponent)
		{
			return std::pow(x, Exponent);
		}
	}
}
