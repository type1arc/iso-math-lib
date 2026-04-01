#pragma once
#include <concepts>
#include <type_traits>

template<typename _type>
concept numeric = std::is_arithmetic_v<_type>;
