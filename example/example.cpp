#include <strong_type.h>
#include <iostream>


// Create strong types
struct A : strong_type<int, A> { using strong_type::strong_type; };
struct B : strong_type<int, B> { using strong_type::strong_type; };

// or use a macro to be more concise
STRONG_TYPE(C, int);
STRONG_TYPE(D, std::string);

// Will be used to show accessing members
struct S
{
	int m = 5;
};
STRONG_TYPE(StrongS, S);

// Takes A strong type
void add_to_A(A& a, A a2, int x)
{
	a += a2 + x;
}

void add_to_StrongS(StrongS& a, StrongS a2, S x)
{
	a.m += a2.m + x.m;
}


int main()
{
	A a = 0;
	B b(1);
	constexpr C c = 2;
	D d("c");
	D d2 = "c";
	int i = 3;

	add_to_A(a, a, 10);
	add_to_A(a, a, a);
	//add_to_A(b, b, 10);	// Compilation error, A and B are different types
	//add_to_A(i, i, 10);	// Compilation error, A and int are different types
	//b = c;				// Compilation error, no implicit conversion

	std::cout << a << '\n';

	// Access underlying type's members
	StrongS ps;
	std::cout << ps.m << '\n';

	S s;
	//ps = s;	// error

	//add_to_StrongS(s,	s,	s);			// error
	//add_to_StrongS(ps,	s,	s);		// error
	//add_to_StrongS(s,	ps,	s);			// error
	add_to_StrongS(ps,	ps,	s);
	//add_to_StrongS(s,	s,	ps);		// error
	//add_to_StrongS(ps,	s,	ps);	// error
	//add_to_StrongS(s,	ps,	ps);		// error
	add_to_StrongS(ps,	ps,	ps);
}