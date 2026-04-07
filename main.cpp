#include "iso_trig.hpp"
#include "iso_util.hpp"

int main()
{
        log(iso::__sin<float128>(0.0000001));
        log(iso::__cos<float128>(iso::constant::pi));

	exit(1);
}
