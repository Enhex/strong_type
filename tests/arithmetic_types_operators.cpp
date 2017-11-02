#include <strong_type.h>

template<typename T>
void test_operators()
{
	STRONG_TYPE(ST, T);
	//using ST = T;

	ST a(1), b(2);

	// assignment
	a = b;
	a += b;
	a -= b;
	a *= b;
	a /= b;

	// increment / decrement
	++a;
	--a;
	a++;
	a--;

	// arithmetic
	+a;
	if constexpr(std::is_signed_v<T>)
		- a;
	a + b;
	a - b;
	a * b;
	a / b;

	// logical
	!a;
	a && b;
	a || b;

	// comparison
	a == b;
	a != b;
	a < b;
	a > b;
	a <= b;
	a >= b;

	//member access
	ST* p = &a;
	*p;

	if constexpr(std::is_integral_v<T>) {
		a %= b;
		a &= b;
		a |= b;
		a ^= b;
		a <<= b;
		a >>= b;

		a % b;
		~a;
		a & b;
		a | b;
		a ^ b;
		a << b;
		a >> b;
	}
}

int main()
{
	test_operators<char>();
	test_operators<unsigned char>();
	test_operators<short>();
	test_operators<unsigned short>();
	test_operators<int>();
	test_operators<unsigned int>();
	test_operators<long>();
	test_operators<unsigned long>();
	test_operators<long long>();
	test_operators<unsigned long long>();
	test_operators<float>();
	test_operators<double>();
	test_operators<long double>();
}