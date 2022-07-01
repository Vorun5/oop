#include "dictionary.h"

using namespace std;
// ��������� ���������� � ������ � �������������

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
		// ������� � ���������
		if (request == "...")
		{
			if (changesHaveBeenMade)
			{
				cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
				getline(stream, request);
				// ������� � ���������
				if (request == "Y" || request == "y")
				{
					SaveDictionaryToFile("dictionary.txt", dictionary);
					cout << "��������� ���������. �� ��������." << endl;
				}
			}

			return;
		}

		if (PrintAllTranslationsOfAWord(request, dictionary) == false)
		{
			string unknownWord = request;
			cout << "����������� ����� �" << unknownWord << "� ������� ������� ��� ������ ������ ��� ������." << endl;
			getline(stream, request);
			if (!request.empty())
			{
				dictionary.emplace(unknownWord, request);
				cout << "����� �" << unknownWord << "� ��������� � ������� ��� �" << request << "�." << endl;
				changesHaveBeenMade = true;
			}
		}
	}
}