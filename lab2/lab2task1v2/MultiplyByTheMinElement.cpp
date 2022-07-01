#include "lab2task1v2.h"
using namespace std;


vector<double> MultiplyByTheMinElement(const vector<double>& numbers)
{
	vector<double> outputNumbers{};
	if (numbers.empty())
	{
		double min = *min_element(numbers.begin(), numbers.end());
		transform(numbers.begin(), numbers.end(), back_inserter(outputNumbers),
			[min](double el) { return el * min; });
	}
	return outputNumbers;
}