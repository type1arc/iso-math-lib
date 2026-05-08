#ifndef ISO_LINEAR_ALG_HPP
#define ISO_LINEAR_ALG_HPP

#include "iso_concepts.hpp"
#include "iso_types.hpp"

namespace iso
{
	
	template<iso::concepts::numeric _type>
	struct Vec3 // For vectors in 3D space
	{
	private:

	public:
		_type x, y, z;

		Vec3(_type x, _type y, _type z);

		void logtty();
		_type mag();

            constexpr Vec3<_type> operator+(const Vec3<_type>& v) const;
	};

	template<iso::concepts::numeric _type>
	struct Vec2 // For vectors in 2D space
	{
	private:

	public:
		_type x, y;

		Vec2(_type x, _type y);

		void logtty();
		_type mag();
	};

        // Matrices

        template <iso::concepts::numeric _type>
        struct Mat4
        {
                _type matrix[4][4];
                static Mat4 perspective(float32 fov, float32 aspect, float32 near, float32 far);
                
        };


	// for vectors in 3D space
	template<iso::concepts::numeric _type>
	Vec3<_type> add(Vec3<_type> v1, Vec3<_type> v2);


	template<iso::concepts::numeric _type>
	Vec3<_type> normalize(Vec3<_type>& v);
	
	template<iso::concepts::numeric _type>
	Vec3<_type> negate(Vec3<_type>& v);
	
	template<iso::concepts::numeric _type>
	_type dot_product(Vec3<_type>& v1, Vec3<_type>& v2);
	
	template<iso::concepts::numeric _type>
	Vec3<_type> cross_product(Vec3<_type>& v1, Vec3<_type>& v2);

	// for vectors in 2D space
	template<iso::concepts::numeric _type>
	Vec2<_type> Add(Vec2<_type>& v1, Vec2<_type>& v2);

	template<iso::concepts::numeric _type>
	Vec2<_type> normalize(Vec2<_type>& v);
	
	template<iso::concepts::numeric _type>
	Vec2<_type> negate(Vec2<_type>& v);
	

	template<iso::concepts::numeric _type>
	_type dot_product(Vec2<_type>& v1, Vec2<_type>& v2);
	
	template<iso::concepts::numeric _type>
	Vec2<_type> cross_product(Vec2<_type>& v1, Vec2<_type>& v2);
}

#endif // !ISO_LINEAR_ALG_HPP
