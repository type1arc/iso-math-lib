#ifndef ISO_CONCEPTS_HPP
#define ISO_CONCEPTS_HPP

#include <concepts>
#include <type_traits>


namespace iso 
{
        namespace concepts 
        {
                template<typename _type>
                concept numeric = std::is_arithmetic_v<_type>;
        }
}

#endif
