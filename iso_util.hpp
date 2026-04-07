#ifndef ISO_UTIL_HPP
#define ISO_UTIL_HPP

#include "iso_concepts.hpp"
#include <random>
#include <iostream>

#define log(x)	    std::cout << x << std::endl;
#define errlog(x)   std::cerr << x << std::endl;

namespace iso 
{
    namespace util 
    {
      template<typename _type>
      _type get_random(_type min, _type max)
      {
	static_assert(std::is_arithmetic<_type>::value, "[ERROR]: INVALID TYPE: 'numeric type not found.'");

	std::random_device id;
	std::mt19937 generator(id());
	if constexpr (std::is_integral<_type>::value)
	{
	  std::uniform_int_distribution<_type> dist(min, max);
	  return dist(generator);
	}
	std::uniform_real_distribution dist(min, max);
	return dist(generator);
      }

      template<iso::concepts::numeric _type>
      _type sqroot(_type _x) // SQR ROOT FUNCTION using Newton-Raphson Method
      {
	if (_x < 0.0f) {
	  errlog("complex-plane: arg < 0");
	  return EXIT_FAILURE;
	}

	_type guess = _x / 2.0f;
	_type epsilon = 0.00000001f;

	while (abs(guess * guess - _x) > epsilon)
	{
	  guess = (guess + _x / guess) / 2.0f;
	}

	return guess;
      }
      template <iso::concepts::numeric _type>
      _type abs(_type x) { return 0 > x ? -1 * x : x; }
    }
  }

#endif
