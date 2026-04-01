#include "iso_trig.hpp"
#include "iso_util.hpp"

int main()
{
  log(iso::_sin<float128>(0.0000001));
  log(iso::_cos<float128>(iso::constant::pi));

 	exit(1);
}
