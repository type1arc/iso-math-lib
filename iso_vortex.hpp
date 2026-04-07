#pragma once

#include "iso_concepts.hpp"
#include <math.h>
#include <iostream>

namespace vortex // TO DO: ADD MORE
{
	namespace opt
	{
		template<iso::concepts::numeric _type>
		struct Shift
		{
		public:
			_type x, y, z;
			Shift(_type x, _type y, _type z);

			Shift operator>>(const Shift& _this);

			void log();
		};

		template<iso::concepts::numeric _type>
		struct Expo // UPDATED...
		{
		public:
			_type x;
			Expo(_type x);

			_type operator^(_type Exponent);
		};
	}
}

