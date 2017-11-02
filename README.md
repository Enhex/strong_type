# strong_type
Create new type from existing type without changing the interface.

You only need to include [strong_type.h](include/strong_type.h).

## Example
```C++
#include <strong_type.h>
#include <iostream>

STRONG_TYPE(StrongInt, int);

void print(StrongInt& x) {
	std::cout << x << std::endl;
}

int main()
{
	int i = -1;
	StrongInt si(1);

	print(si);
	print(i);	// Compilation error, StrongInt and int are different types
}
```
For more examples see [this](example/example.cpp).

## License
MIT
