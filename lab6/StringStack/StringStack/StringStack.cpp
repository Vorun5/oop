#include "CStringStack.h"
#include <iostream>
#include <vector>


CStringStack StringStack123()
{
	CStringStack s;
	s.Push("1");
	s.Push("2");
	s.Push("3");
	return s;
}

int main()
{
	std::vector<int> a;
	CStringStack s;
	s.Push("cat");
	s.Push("dog");
	s.Push("frog");
	try
	{
		std::cout << s.GetTop() << std::endl;
		s.Pop();
		std::cout << s.GetTop() << std::endl;
		s.Pop();
		std::cout << s.GetTop() << std::endl;
		s.Pop();
		std::cout << s.GetTop() << std::endl;
		s.Pop();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	CStringStack s1;
	s1.Push("1");
	s1.Push("2");
	s1.Push("3");

	s1.Clear();

	CStringStack s1Copy(s1);

	CStringStack s123;
	s123.Push("1");
	s123.Push("2");
	s = StringStack123();
	s123 = s;
	CStringStack m = StringStack123();
	return 0;
}
