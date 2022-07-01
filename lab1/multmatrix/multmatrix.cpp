#include <array>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int SIZE = 3;

using  Matrix3x3 = array<array<double, SIZE>, SIZE>;

struct Args
{
	string inputFirstMatrixFileName;
	string inputSecondMatrixFileName;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: findtext.exe <matrix file1> <matrix file2>";
		return nullopt;
	}
	Args args;
	args.inputFirstMatrixFileName = argv[1];
	args.inputSecondMatrixFileName = argv[2];
	return args;
}

bool ReadMatrixFromFile(const string& fileName, Matrix3x3& matrix)
{
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Failed to open '" << fileName << "' for reading\n";
		return false;
	}
	string bufferStr;
	int lineCount = 0;
	while (getline(file, bufferStr) && lineCount != SIZE)
	{
		// можно обойтись без vector и посчиать равно ли число 3
		// переименовать
		istringstream bufferStrStream(bufferStr);

		vector<string> stringNumList{ istream_iterator<string>(bufferStrStream), {} };
		if (stringNumList.size() != SIZE)
		{
			cout << "Wrong number of numbers in line " << lineCount << " of " << fileName << endl;
			return false;
		}
		for (int i = 0; i < stringNumList.size(); i++)
		{
			istringstream streamStringNum(stringNumList[i]);
			if ((streamStringNum >> matrix[lineCount][i]) && streamStringNum.eof())
			{
				
			}
			else
			{
				cout << "Expected number on line " << lineCount << " of " << fileName << endl;
				return false;
			}
		};

		lineCount++;
	}

	if (lineCount != 3)
	{
		cout << "Incorrect number of lines in " << fileName << endl;
		return false;
	}
	if (file.bad())
	{
		cout << "Failed to read data from " << fileName << endl;
		return false;
	}
	return true;
}

Matrix3x3 MatrixMultiplication(const Matrix3x3& firstMatrix, const Matrix3x3& secondMatrix)
{
	Matrix3x3 multiMatrix{};
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			for (int k = 0; k < SIZE; ++k)
			{
				multiMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
	return multiMatrix;
}

void PrintMatrix(const Matrix3x3& matrix)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << fixed;
			cout << setprecision(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	Matrix3x3 firstMatrix{};
	Matrix3x3 secondMatrix{};

	if (!ReadMatrixFromFile(args->inputFirstMatrixFileName, firstMatrix)
		|| !ReadMatrixFromFile(args->inputSecondMatrixFileName, secondMatrix))
	{
		return 1;
	}

	Matrix3x3 matrixProduct = MatrixMultiplication(firstMatrix, secondMatrix);
	PrintMatrix(matrixProduct);
	return 0;
}
