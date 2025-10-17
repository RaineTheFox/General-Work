// functie cu template ptr schimbarea valorilor a 2 variabile

#include <iostream>
#include <string>

template <typename T>
void swapValues(T& a, T& b) // as seen in the course, if we needed Max /Min we would use T instead of void
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
	// Testing with integers, doubles, and strings

	// swapping integers
	std::cout << "Swapping integers:\n";
	int x = 10; 
	int y = 20;
	std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
	swapValues(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << "\n\n";

	// swapping doubles
	std::cout << "Swapping doubles:\n";
	double m = 5.5;
	double n = 9.9;
	std::cout << "Before swap: m = " << m << ", n = " << n << "\n";
	swapValues(m, n);
	std::cout << "After swap: m = " << m << ", n = " << n << "\n\n";

	// swapping strings
	std::cout << "Swapping strings:\n";
	std::string str1 = "Hello";
	std::string str2 = "World";
	std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << "\n";
	swapValues(str1, str2);
	std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << "\n";


	return 0;
}