#include <iostream>
#include "CRational.h"
int main()
{
	CRational r(1, 2);
	CRational r2(1, 6);
	r += r2;
	std::cout << r.GetNumerator() << "|" << r.GetDenominator() << std::endl;
	
	std::cout << std::lcm(2, 20);
	return 0;
}