#pragma once

#include <tuple>
#include "iso_concepts.hpp"

#define iota sqrt(-1)

  // Complex numbers - lets see how it goes
  // [UPDATE] turned out pretty good i think
  //
  // added '+' and '*' operators for Complex values 
namespace complex_plane
{
	template<iso::concepts::numeric _type>
	struct Complex
	{
	public:
	  std::tuple<_type, _type> value;
	  _type re_comp, im_comp;
		
	  Complex(_type re_comp, _type im_comp);
    Complex operator+(const Complex& otr) const; 

    Complex operator*(const Complex& otr) const; 
	  _type iabs(std::tuple<_type, _type>& value);
	  void log();
	};
}
