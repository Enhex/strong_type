#include <strong_type.h>

using T = int;
STRONG_TYPE(ST, T);

void f(T s) {}

int main()
{
	ST st;
	f(st);	// should fail
}