#pragma once

#include <tuple>
#include "iso_concepts.hpp"

namespace iso
{
	
	template<iso::concepts::numeric _type>
	struct Vec3 // For vectors in 3D space
	{
	private:
		std::tuple<_type, _type, _type> vec_t;

	public:
		_type x, y, z;

		Vec3(_type x, _type y, _type z);

		void logv();
		_type mag();
		std::tuple<_type, _type, _type> get(); 

                constexpr Vec3<_type> operator+(const Vec3<_type>& v) const;
	};

	template<iso::concepts::numeric _type>
	struct Vec2 // For vectors in 2D space
	{
	private:
		std::tuple<_type, _type> vec_t;

	public:
		_type x, y;

		Vec2(_type x, _type y);

		void logv();
		_type mag();
		std::tuple<_type, _type> get();
	};

	/*template <iso::concepts::numeric _type>
	struct	mat3
	{
	public:
		std::vector<std::vector<_type>> mat;
		mat3(_type diag)
		{
			mat =
			{
				{diag, 0, 0},
				{0, diag, 0},
				{0, 0, diag}
			}; 
		}
		void log_m()
		{
			for (int x = 0; x < mat.size(); x++)
			{
				for (int y = 0; y < mat[x].size(); y++)
				{
					std::cout << mat[x][y] << " ";
				}
				std::cout << std::endl;
			}
		}
	};	*/

	// for vectors in 3D space
	template<iso::concepts::numeric _type>
	Vec3<_type> add(Vec3<_type> v1, Vec3<_type> v2);

         


	template<iso::concepts::numeric _type>
	Vec3<_type> normalize(Vec3<_type> v);
	
	template<iso::concepts::numeric _type>
	Vec3<_type> negate(Vec3<_type> v);
	
	template<iso::concepts::numeric _type>
	_type dot_product(Vec3<_type> v1, Vec3<_type> v2);
	
	template<iso::concepts::numeric _type>
	Vec3<_type> cross_product(Vec3<_type> v1, Vec3<_type> v2);

	// for vectors in 2D space
	template<iso::concepts::numeric _type>
	Vec2<_type> Add(Vec2<_type> v1, Vec2<_type> v2);

	template<iso::concepts::numeric _type>
	Vec2<_type> normalize(Vec2<_type> v);
	
	template<iso::concepts::numeric _type>
	Vec2<_type> negate(Vec2<_type> v);
	

	template<iso::concepts::numeric _type>
	_type dot_product(Vec2<_type> v1, Vec2<_type> v2);
	
	template<iso::concepts::numeric _type>
	Vec2<_type> cross_product(Vec2<_type> v1, Vec2<_type> v2);
}

#include "iso_vector_impl.hpp"
