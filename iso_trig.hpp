#include "iso_constants.hpp"
#include "iso_concepts.hpp"
#include "iso_util.hpp"

namespace iso
{
      template <iso::concepts::numeric _type>
      _type __sin(_type x)
      {

                // minimax approximation
                constexpr double c1 = -1.66666666666666324348e-01;
                constexpr double c2 =  8.33333333332248946124e-03;
                constexpr double c3 = -1.98412698298579493134e-04;
                constexpr double c4 =  2.75573137070700676789e-06;
                constexpr double c5 = -2.50507602534068634195e-08;
                constexpr double c6 =  1.58969099521155010221e-10;  
                
                // edge-cases
                if (std::isnan(x)) return NAN;
                if (std::isinf(x)) return NAN;
                if (x == 0) return 0;

                float128 quad	  = x / iso::constant::half_pi;
                int32	 quad_val = static_cast<int32>(quad);
                float128 reduced  = x - quad_val * iso::constant::half_pi;  

                // polynomial approximation
                float128 z = reduced * reduced;
                float128 v = z * reduced;
                float128 r = c2 + z * (c3 + z * (c4 + z * (c5 + z * c6)));
                float128 approx = reduced + v * (c1 + z * r); 

                switch(quad_val & 3)					  // using bitwise AND instead of modulo to reduce the quadrant number into 1, 2, 3, 4	
                {
                          case 0: return approx;				  // first  quadrant  :	 sin x
                          case 1: return util::sqroot (1 - approx * approx);	  // second quadrant  :	 cos x
                          case 2: return - approx;				  // third  quadrant  : -sin x
                          case 3: return -util::sqroot(1 - approx * approx);	  // fourth quadrant  : -cos x
                }
                return approx;
      }

      template <iso::concepts::numeric _type>
      _type __cos(_type x)
      {
                constexpr double c2  = -5.00000000000000000000e-01;
                constexpr double c4  =  4.16666666666666666647e-02;
                constexpr double c6  = -1.38888888888887588854e-03;
                constexpr double c8  =  2.48015872888505653021e-05;
                constexpr double c10 = -2.75573192192997980483e-07;
                constexpr double c12 =  2.08767557072843831027e-09;

                if (std::isnan(x)) return NAN;
                if (std::isinf(x)) return NAN;
                if (x == 0) return 1;

                float128 quad	  = x / iso::constant::half_pi;
                int32	 quad_val = static_cast<int32>(quad);
                float128 reduced  = x - quad_val * iso::constant::half_pi;

                if (util::abs(reduced) < 1e-19) {
                          if ((quad_val & 1) == 1) return 0;
                          return ((quad_val & 2) == 0) ? 1 : -1;
                }

                float128 z  = reduced * reduced;
                float128 r  = c4 + z * (c6 + z * (c8 + z * (c10 + z * c12)));
                float128 approx = 1.0L + z * (c2 + z * r);

                return ((quad_val & 1) == 0) ? approx : -approx;
      }

      template <iso::concepts::numeric _type>
      _type __tan(_type x)
      {
              return __sin(x) / __cos(x);
      }
}
