#include "lab2task1v2.h"
#include "MultiplyByTheMinElement.cpp"

using namespace std;


void Print(const vector<double>& numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << setprecision(4) << numbers[i] << " ";
	}
}

vector<double> ReadNumbersFromStream(istream& stream)
{
	vector<double> numbers;
	while (!stream.eof())
	{
		double number;
		if (stream >> number)
		{
			numbers.push_back(number);
		}
		else
		{
			break;
		}
	}
	return numbers;
};

int main()
{
	vector<double> numbers = ReadNumbersFromStream(cin);
	numbers = MultiplyByTheMinElement(numbers);
	sort(numbers.begin(), numbers.end());
	Print(numbers);
	return 0;
}
