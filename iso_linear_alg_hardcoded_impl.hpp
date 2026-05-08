#ifndef ISO_LINEAR_ALG_HARDCODED_IMPL
#define ISO_LINEAR_ALG_HARDCODED_IMPL

#include <cmath>
#include <iostream>
#include "iso_linear_alg_hardcoded.hpp"

namespace iso
{
	constexpr fVec3::fVec3(float32 x, float32 y, float32 z)
		: x(x), y(y), z(z)
	{

	}

        constexpr fVec3 fVec3::operator+(const fVec3& v) const
        {
                return fVec3(x + v.x, y + v.y, z + v.z);
        }

	void fVec3::logtty() { std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }

	float32 fVec3::mag() { return x + y + z; }


	fVec2::fVec2(float32 x, float32 y)
	{
		this->x = x;
		this->y = y;
	}

	void fVec2::logtty() { std::cout << "(" << x << ", " << y << ")" << std::endl; }

	float32 fVec2::mag() { return x + y; }


        fMat4 fMat4::perspective(float32 fov, float32 aspect, float32 near, float32 far)
        {
                float32 f = 1.0f / iso::__tan(fov * 0.5f);
                fMat4 m = {0};
                m.matrix[0][0] = f / aspect;
                m.matrix[1][1] = f;
                m.matrix[2][2] = (far + near) / (near - far);
                m.matrix[2][3] = (2 * far * near) / (near - far);
                m.matrix[3][2] = -1.0f;

                return m;
        }
	// vectors in 3D space
	fVec3 add(fVec3& v1, fVec3& v2)
	{
		fVec3 _out = fVec3
			(
				v1.x + v2.x,
				v1.y + v2.y,
				v1.z + v2.z
			);

		return _out;
	}

	fVec3 formalize(fVec3& v)
	{
		fVec3 _out = fVec3(
			v.x /= fabs(v.x),
			v.y /= fabs(v.y),
			v.z /= fabs(v.z)
		);

		if (std::isnan(_out.x)) _out.x = 0;
		if (std::isnan(_out.y)) _out.y = 0;
		if (std::isnan(_out.z)) _out.z = 0;

		return _out;
	}

	fVec3 negate(fVec3& v)
	{
		v.x *= -1;
		v.y *= -1;
		v.z *= -1;

		return v;
	}

	float32 dot_product(fVec3& v1, fVec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; 
	}

	fVec3 cross_product(fVec3& v1, fVec3& v2)
	{
            // a×b⃗=i^(a2b3−a3b2)−j^(a1b3−a3b1)+k^(a1b2−a2b1)
            return fVec3(v1.y * v2.z - v1.z * v2.y, v1.x * v2.z - v1.z - v2.x, v1.x * v2.y - v1.y * v2.x);
	}

	// vectors in 2D space
	fVec2 Add(fVec2& v1, fVec2& v2)
	{
		fVec2 _out = fVec2
			(
				v1.x + v2.x,
				v1.y + v2.y
			);

		return _out;
	}

	fVec2 cross_product(fVec2& v1, fVec2& v2)
	{
		fVec2 _out = fVec2(0.0f, 0.0f);
		_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
		_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));
		return _out;
	}

        fVec3 Add(fVec3& v1, fVec3& v2)
	{
		fVec3 _out = fVec3
			(
				v1.x + v2.x,
				v1.y + v2.y,
				v1.z + v2.z
			);

		return _out;
	}

	fVec3 normalize(fVec3& v)
	{
		fVec3 _out = fVec3(
			v.x /= fabs(v.x),
			v.y /= fabs(v.y),
			v.z /= fabs(v.z)
		);

		if (std::isnan(_out.x)) _out.x = 0;
		if (std::isnan(_out.y)) _out.y = 0;
		if (std::isnan(_out.z)) _out.z = 0;

		return _out;
	}

	constexpr iVec3::iVec3(int32 x, int32 y, int32 z)
		: x(x), y(y), z(z)
	{

	}

        constexpr iVec3 iVec3::operator+(const iVec3& v) const
        {
                return iVec3(x + v.x, y + v.y, z + v.z);
        }

	void iVec3::logtty() { std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }

	int32 iVec3::mag() { return x + y + z; }


	iVec2::iVec2(int32 x, int32 y)
	{
		this->x = x;
		this->y = y;
	}

	void iVec2::logtty() { std::cout << "(" << x << ", " << y << ")" << std::endl; }

	int32 iVec2::mag() { return x + y; }


        iMat4 iMat4::perspective(float32 fov, float32 aspect, float32 near, float32 far)
        {
                float32 f = 1.0f / iso::__tan(fov * 0.5f);
                iMat4 m = {0};
                m.matrix[0][0] = f / aspect;
                m.matrix[1][1] = f;
                m.matrix[2][2] = (far + near) / (near - far);
                m.matrix[2][3] = (2 * far * near) / (near - far);
                m.matrix[3][2] = -1.0f;

                return m;
        }

	iVec3 negate(iVec3& v)
	{
		v.x *= -1;
		v.y *= -1;
		v.z *= -1;

		return v;
	}

        iVec2 normalize(iVec2& v)
	{
		iVec2 _out = iVec2(
			v.x /= fabs(v.x),
			v.y /= fabs(v.y)
		);

		if (std::isnan(_out.x)) _out.x = 0;
		if (std::isnan(_out.y)) _out.y = 0;

		return _out;
	}

	iVec2 negate(iVec2& v)
	{
		v.x *= -1;
		v.y *= -1;

		return v;
	}

	int32 dot_product(iVec3& v1, iVec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; 
	}

	iVec3 cross_product(iVec3& v1, iVec3& v2)
	{
            // a×b⃗=i^(a2b3−a3b2)−j^(a1b3−a3b1)+k^(a1b2−a2b1)
            return iVec3(v1.y * v2.z - v1.z * v2.y, v1.x * v2.z - v1.z - v2.x, v1.x * v2.y - v1.y * v2.x);
	}

	// vectors in 2D space
	iVec2 Add(iVec2& v1, iVec2& v2)
	{
		iVec2 _out = iVec2
			(
				v1.x + v2.x,
				v1.y + v2.y
			);

		return _out;
	}

	fVec2 normalize(fVec2& v)
	{
		fVec2 _out = fVec2(
			v.x /= fabs(v.x),
			v.y /= fabs(v.y)
		);

		if (std::isnan(_out.x)) _out.x = 0;
		if (std::isnan(_out.y)) _out.y = 0;

		return _out;
	}


	int32 dot_product(iVec2& v1, iVec2& v2)
	{
		return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
	}

	iVec2 cross_product(iVec2& v1, iVec2& v2)
	{
		iVec2 _out = iVec2(0.0f, 0.0f);
		_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
		_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));
		return _out;
	}
}

#endif
