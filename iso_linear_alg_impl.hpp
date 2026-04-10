#pragma once

#include <cmath>
#include <iostream>
#include "iso_concepts.hpp"
#include "iso_linear_alg.hpp"

namespace iso
{
	template<iso::concepts::numeric _type>
	Vec3<_type>::Vec3(_type x, _type y, _type z)
	{
		this->x = x;
		this->y = y;
		this->z = z;

	}

        template <iso::concepts::numeric _type>
        constexpr Vec3<_type> Vec3<_type>::operator+(const Vec3<_type>& v) const
        {
                return Vec3<_type>(x + v.x, y + v.y, z + v.z);
        }

	template<iso::concepts::numeric _type>
	void Vec3<_type>::logv() { std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }

	template<iso::concepts::numeric _type>
	_type Vec3<_type>::mag() { return x + y + z; }


	template<iso::concepts::numeric _type>
	Vec2<_type>::Vec2(_type x, _type y)
	{
		this->x = x;
		this->y = y;
	}

	template<iso::concepts::numeric _type>
	void Vec2<_type>::logv() { std::cout << "(" << x << ", " << y << ")" << std::endl; }

	template<iso::concepts::numeric _type>
	_type Vec2<_type>::mag() { return x + y; }


	template<iso::concepts::numeric _type>
        Mat4<_type> Mat4<_type>::perspective(float32 fov, float32 aspect, float32 near, float32 far)
        {
                float32 f = 1.0f / tanf(fov * 0.5f);
                Mat4 m = {0};
                m.matrix[0][0] = f / aspect;
                m.matrix[1][1] = f;
                m.matrix[2][2] = (far + near) / (near - far);
                m.matrix[2][3] = (2 * far * near) / (near - far);
                m.matrix[3][2] = -1.0f;

                return m;
        }
	// vectors in 3D space
	template<iso::concepts::numeric _type>
	Vec3<_type> add(Vec3<_type>& v1, Vec3<_type>& v2)
	{
		Vec3<_type> _out = Vec3<_type>
			(
				v1.x + v2.x,
				v1.y + v2.y,
				v1.z + v2.z
			);

		return _out;
	}

	template<iso::concepts::numeric _type>
	Vec3<_type> normalize(Vec3<_type>& v)
	{
		Vec3<_type> _out = Vec3<_type>(
			v.x /= abs(v.x),
			v.y /= abs(v.y),
			v.z /= abs(v.z)
		);

		if (isnan(_out.x)) _out.x = 0;
		if (isnan(_out.y)) _out.y = 0;
		if (isnan(_out.z)) _out.z = 0;

		return _out;
	}

	template<iso::concepts::numeric _type>
	Vec3<_type> negate(Vec3<_type>& v)
	{
		v.x *= -1;
		v.y *= -1;
		v.z *= -1;

		return v;
	}

	template<iso::concepts::numeric _type>
	_type dot_product(Vec3<_type>& v1, Vec3<_type>& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; 
	}

	template<iso::concepts::numeric _type>
	Vec3<_type> cross_product(Vec3<_type>& v1, Vec3<_type>& v2)
	{
    // a×b⃗=i^(a2b3−a3b2)−j^(a1b3−a3b1)+k^(a1b2−a2b1
    return Vec3<_type>(v1.y * v2.z - v1.z * v2.y, v1.x * v2.z - v1.z - v2.x, v1.x * v2.y - v1.y * v2.x);
	}

	// vectors in 2D space
	template<iso::concepts::numeric _type>
	Vec2<_type> Add(Vec2<_type>& v1, Vec2<_type>& v2)
	{
		Vec2<_type> _out = Vec2<_type>
			(
				v1.x + v2.x,
				v1.y + v2.y
			);

		return _out;
	}

	template<iso::concepts::numeric _type>
	Vec2<_type> normalize(Vec2<_type>& v)
	{
		Vec2<_type> _out = Vec2<_type>(
			v.x /= abs(v.x),
			v.y /= abs(v.y)
		);

		if (isnan(_out.x)) _out.x = 0;
		if (isnan(_out.y)) _out.y = 0;

		return _out;
	}

	template<iso::concepts::numeric _type>
	Vec2<_type> negate(Vec2<_type>& v)
	{
		v.x *= -1;
		v.y *= -1;

		return v;
	}

	template<iso::concepts::numeric _type>
	 _type dot_product(Vec2<_type>& v1, Vec2<_type>& v2)
	{
		return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
	}

	template<iso::concepts::numeric _type>
	Vec2<_type> cross_product(Vec2<_type>& v1, Vec2<_type>& v2)
	{
		Vec2<_type> _out = Vec2<_type>(0.0f, 0.0f);
		_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
		_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));

		return _out;
	}
}
