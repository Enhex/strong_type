#include <strong_type.h>

using T = int;
STRONG_TYPE(ST, T);

void f(ST& s) {}

int main()
{
	T t;
	f(t);	// should fail
}