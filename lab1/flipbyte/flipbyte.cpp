#include <iostream>
#include <optional>
#include <sstream>
#include <vector>

using namespace std;

struct Args
{
	uint8_t inputNum;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: flipbyte.exe <input byte>\n";
		return nullopt;
	}
	int buffNum;
	istringstream stream(argv[1]);
	if ((stream >> buffNum) && stream.eof())
	{
		if (buffNum <= 255 && buffNum >= 0)
		{
			Args args;
			args.inputNum = buffNum;
			return args;
		}
		else
		{
			cout << "Invalid number range\n";
			cout << "Valid values are from 0 to 255\n";
			return nullopt;
		}
	}
	else
	{
		cout << "Invalid data\n";
		cout << "Enter the number\n";
		return nullopt;
	}
}

uint8_t FlipByte(uint8_t num)
{
	uint8_t reverseByteNum = 0;
	for (int i = 0; i < 8; i++)
	{
		if (num & 1 << i)
		{
			reverseByteNum |= 1 << (7 - i);
		}
	}
	return reverseByteNum;
}


int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	uint8_t reverseByteInputNum = FlipByte(args->inputNum);

	cout << static_cast<int>(reverseByteInputNum);
	return 0;
}
