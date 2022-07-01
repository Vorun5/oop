#include "dictionary.h"

using namespace std;
// разделить сохранение и диалог с пользователем

void ReadRequestsFromStream(istream& stream, Dictionary& dictionary)
{
	bool changesHaveBeenMade = false;
	while (!stream.eof())
	{
		string request;

		getline(stream, request);

		if (request.empty())
		{
			continue;
		}
		// вывести в константу
		if (request == "...")
		{
			if (changesHaveBeenMade)
			{
				cout << "¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом.\n";
				getline(stream, request);
				// вывести в константу
				if (request == "Y" || request == "y")
				{
					SaveDictionaryToFile("dictionary.txt", dictionary);
					cout << "»зменени€ сохранены. ƒо свидани€." << endl;
				}
			}

			return;
		}

		if (PrintAllTranslationsOfAWord(request, dictionary) == false)
		{
			string unknownWord = request;
			cout << "Ќеизвестное слово У" << unknownWord << "Ф ¬ведите перевод или пустую строку дл€ отказа." << endl;
			getline(stream, request);
			if (!request.empty())
			{
				dictionary.emplace(unknownWord, request);
				cout << "—лово У" << unknownWord << "Ф сохранено в словаре как У" << request << "Ф." << endl;
				changesHaveBeenMade = true;
			}
		}
	}
}