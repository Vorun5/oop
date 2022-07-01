#include "dictionary.h"
// лучше не использовать std
using namespace std;
// объеденить модули
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary dictionary;
	// вывести имя файла в констану
	if (!ReadDictionaryFromFile("dictionary.txt", dictionary))
	{
		return 1;
	}

	ReadRequestsFromStream(cin, dictionary);


	return 0;
}
