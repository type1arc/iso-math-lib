#pragma once

#include "iso_complex.hpp"
#include <format>

namespace complex_plane
{
	template<iso::concepts::numeric _type>
	Complex<_type>::Complex(_type re_comp, _type im_comp) : re_comp(re_comp), 
													 im_comp(im_comp), 
													 value(std::make_tuple(re_comp, im_comp))
	{}

	template<iso::concepts::numeric _type>
	_type Complex<_type>::iabs(std::tuple<_type, _type>& value)
	{
		return sqroot(re_comp * re_comp + im_comp * im_comp);
  }
  template<iso::concepts::numeric _type>
  Complex<_type> Complex<_type>::operator+(const Complex& otr) const 
  {
    return Complex(re_comp * otr.re_comp, im_comp + otr.im_comp);
  }

  template<iso::concepts::numeric _type>
  Complex<_type> Complex<_type>::operator*(const Complex& otr) const 
  {
    return Complex(re_comp * otr.re_comp - im_comp * otr.im_comp, 
		   re_comp * otr.im_comp + im_comp * otr.re_comp);
  }
	template<iso::concepts::numeric _type>
	void Complex<_type>::log()
      {
	std::string sign;

	if (std::get<1>(value) > 0)
	  sign = "+";
	if (std::get<1>(value) < 0)
	  sign = "-";
	std::format("{}, {}i", std::get<0>(value), std::get<1>(value));
      }

} 
