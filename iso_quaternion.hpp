#pragma once

#include "iso_concepts.hpp"
#include "iso_types.hpp"
#include "iso_util.hpp"
#include <cmath>

namespace iso 
{
    template <iso::concepts::numeric _type>
    class quaternion 
    {
      private:
	_type w, x, y, z;

      public:
	constexpr quaternion(_type _w, _type _x, _type _y, _type _z) : w(_w), x(_x), y(_y), z(_z) 
	{};

	constexpr quaternion<_type> operator*(const quaternion<_type>& quat) const 
	{
	  return quaternion<_type> (
		w*quat.w - x*quat.x - y*quat.y - z*quat.z,
		w*quat.x + x*quat.w + y*quat.z - z*quat.y,
		w*quat.y - x*quat.z + y*quat.w + z*quat.x,
		w*quat.z + x*quat.y - y*quat.x + z*quat.w
	  );
	}

	// quaternion<_type> normalize()
	// {
	//   float_t mag = std::sqrt(w * w + x * x + y * y + z * z);
	//   return quaternion(w / mag, x / mag, y / mag, z / mag); 
	// }
	
	quaternion<_type> normalize() 
	{
	    float128 mag_sq = w*w + x*x + y*y + z*z;
	    if (mag_sq > 0.0) {
		float128 inv_mag = 1.0 / util::sqroot(mag_sq);
		w *= inv_mag; x *= inv_mag; y *= inv_mag; z *= inv_mag;
	    }
	    return quaternion(w, x, y, z);
	}
	const quaternion<_type> inverse() const 
	{
	  return quaternion(w, -x, -y, -z);
	} 

	void rotate(float128& vx, float128& vy, float128& vz) const 
	{
		  quaternion v(0, vx, vy, vz);
		  quaternion result = (*this) * v * this->inverse();
		  vx = result.x; vy = result.y; vz = result.z;
	}
    };
}

