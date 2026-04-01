#pragma once

#include "iso_complex.hpp"
#include <format>

namespace complex_plane
{
	template<numeric _type>
	complex<_type>::complex(_type re_comp, _type im_comp) : re_comp(re_comp), 
													 im_comp(im_comp), 
													 value(std::make_tuple(re_comp, im_comp))
	{}

	template<numeric _type>
	_type complex<_type>::iabs(std::tuple<_type, _type>& value)
	{
		return sqroot(re_comp * re_comp + im_comp * im_comp);
  }
  template<numeric _type>
  complex<_type> complex<_type>::operator+(const complex& otr) const 
  {
    return complex(re_comp * otr.re_comp, im_comp + otr.im_comp);
  }

  template<numeric _type>
  complex<_type> complex<_type>::operator*(const complex& otr) const 
  {
    return complex(re_comp * otr.re_comp - im_comp * otr.im_comp, 
                   re_comp * otr.im_comp + im_comp * otr.re_comp);
  }
	template<numeric _type>
	void complex<_type>::log()
      {
        std::string sign;

        if (std::get<1>(value) > 0)
          sign = "+";
        if (std::get<1>(value) < 0)
          sign = "-";
        std::format("{}, {}i", std::get<0>(value), std::get<1>(value));
      }

} 
