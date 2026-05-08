#include "iso_trig.hpp"
#include "iso_linear_alg.hpp"
#include "iso_linear_alg_impl.hpp"
#include "iso_types.hpp"

int main()
{
        log(iso::__sin<float32>(0.0000001));
        log(iso::__cos<float128>(iso::constant::pi));
        log(iso::__tan<float128>(iso::constant::pi / 4));

        iso::Vec3<int> v1 = iso::Vec3<int>(1, 3, 7);
        iso::Vec3<int> v2 = iso::Vec3<int>(-1, 4, -9);

        iso::Vec3<int> sum = v1 + v2;
        sum.logtty();

	exit(1);
}
