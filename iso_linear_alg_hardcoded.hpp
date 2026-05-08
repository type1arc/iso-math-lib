#ifndef ISO_LINEAR_ALG_HARDCODED
#define ISO_LINEAR_ALG_HARDCODED

#include "iso_trig.hpp"

namespace iso
{
	
	struct fVec3 // For vectors in 3D space
	{
	private:

	public:
		float32 x, y, z;

		constexpr fVec3(float32 x, float32 y, float32 z);

		void logtty();
		float32 mag();
                inline constexpr fVec3 operator+(const fVec3& v) const;
	};

	struct fVec2 // For vectors in 2D space
	{
	private:

	public:
		float32 x, y;

		fVec2(float32 x, float32 y);

		void logtty();
		float32 mag();
	};

        // Matrices

        struct fMat4
        {
                float32 matrix[4][4];
                static fMat4 perspective(float32 fov, float32 aspect, float32 near, float32 far);
                
        };


	// for vectors in 3D space
	fVec3 add(fVec3 v1, fVec3 v2);


	fVec3 normalize(fVec3& v);
	
	fVec3 negate(fVec3& v);
	
	float32 dot_product(fVec3& v1, fVec3& v2);
	
	fVec3 cross_product(fVec3& v1, fVec3& v2);

	// for vectors in 2D space
	fVec2 Add(fVec2& v1, fVec2& v2);

	fVec2 normalize(fVec2& v);
	
	fVec2 negate(fVec2& v);
	

	float32 dot_product(fVec2& v1, fVec2& v2);
	
	fVec2 cross_product(fVec2& v1, fVec2& v2);



	struct iVec3 // For vectors in 3D space
	{
	private:

	public:
		int32 x, y, z;

		constexpr iVec3(int32 x, int32 y, int32 z);

		void logtty();
		int32 mag();

            inline constexpr iVec3 operator+(const iVec3& v) const;
	};

	struct iVec2 // For vectors in 2D space
	{
	private:

	public:
		int32 x, y;

		iVec2(int32 x, int32 y);

		void logtty();
		int32 mag();
	};

        // Matrices

        struct iMat4
        {
                int32 matrix[4][4];
                static iMat4 perspective(float32 fov, float32 aspect, float32 near, float32 far);
                
        };


	// for vectors in 3D space
	iVec3 add(iVec3 v1, iVec3 v2);


	iVec3 normalize(iVec3& v);
	
	iVec3 negate(iVec3& v);
	
	int32 dot_product(iVec3& v1, iVec3& v2);
	
	iVec3 cross_product(iVec3& v1, iVec3& v2);

	// for vectors in 2D space
	iVec2 Add(iVec2& v1, iVec2& v2);

	iVec2 normalize(iVec2& v);
	
	iVec2 negate(iVec2& v);
	

	int32 dot_product(iVec2& v1, iVec2& v2);
	
	iVec2 cross_product(iVec2& v1, iVec2& v2);
}

#endif
