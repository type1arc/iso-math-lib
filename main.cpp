#include "iso_trig.hpp"
#include "iso_util.hpp"
#include "iso_linear_alg.hpp"

int main()
{
        log(iso::__sin<float128>(0.0000001));
        log(iso::__cos<float128>(iso::constant::pi));
        log(iso::__tan<float128>(iso::constant::pi / 4));

        iso::Vec3<int> v1 = iso::Vec3<int>(1, 3, 7);
        iso::Vec3<int> v2 = iso::Vec3<int>(-1, 4, -9);

        iso::Vec3<int> sum = v1 + v2;
        sum.logv();

	exit(1);
}
