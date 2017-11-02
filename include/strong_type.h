/*
The MIT License (MIT)

Copyright (c) 2017 Yehonatan Ballas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#ifndef phantom_type_h
#define phantom_type_h


#include <type_traits>
#include <utility>


/*
strong type template class.
*/
template <typename T, typename enable = void>
struct strong_type
{
	strong_type() = default;
	constexpr explicit strong_type(const T& value) : value(value) {}
	constexpr strong_type(T&& value) : value(std::forward<T>(value)) {}

	T value;

	// Implicitly convert to the underlying value
	operator T& () noexcept { return value; }
	constexpr operator const T& () const noexcept { return value; }

	// Operators
	T& operator++() { return ++value; }
	T operator++(int) { return value++; }

	T& operator--() { return --value; }
	T operator--(int) { return value--; }
};

// Specialize for class types to use inheritance
template <typename T>
struct strong_type<T, typename std::enable_if_t<std::is_class_v<T>>> : T
{
	strong_type() = default;
	constexpr explicit strong_type(const T& value) : T(value) {}
	constexpr strong_type(T&& value) : T(std::forward<T>(value)) {}
};


// Macro for concisely defining a phantom type
#define STRONG_TYPE(type_name, value_type) \
struct type_name : strong_type<value_type> \
{\
    using strong_type::strong_type;\
}


#endif//phantom_type_h